from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
import json


REQUIRED_ASSETS = [
    "front.png",
    "back.png",
    "icon.png",
    "footprint.png",
    "normal.pal",
    "shiny.pal",
]

FALLBACK_ALIASES = {
    "front.png": ["front.png", "anim_front.png"],
    "back.png": ["back.png"],
    "icon.png": ["icon.png", "icon_gba.png"],
    "footprint.png": ["footprint.png", "footprint_gba.png"],
    "normal.pal": ["normal.pal", "normal_gba.pal"],
    "shiny.pal": ["shiny.pal", "shiny_gba.pal"],
}


@dataclass
class ValidationResult:
    data: dict
    warnings: list[str] = field(default_factory=list)
    errors: list[str] = field(default_factory=list)
    asset_sources: dict[str, Path] = field(default_factory=dict)
    used_fallback: bool = False
    fallback_species_folder: str | None = None


def load_species_json(path: Path) -> dict:
    text = path.read_text(encoding="utf-8")
    parsed = json.loads(text)
    if not isinstance(parsed, dict):
        raise ValueError("The JSON of sort must be an object")
    return parsed


def validate_species_definition(
    data: dict,
    json_path: Path,
    project_root: Path,
    fallback_folder: str | None,
) -> ValidationResult:
    result = ValidationResult(data=data)

    mode = data.get("mode")
    if mode not in {"add", "edit", "delete"}:
        result.errors.append("mode has to be 'add', 'edit' or 'delete'")

    constant_name = data.get("constant_name")
    if not isinstance(constant_name, str) or not constant_name.startswith("SPECIES_"):
        result.errors.append("constant_name must start with SPECIES_")

    if mode == "delete":
        result.asset_sources = {}
        return result

    species_name = data.get("species_name")
    if not isinstance(species_name, str) or not species_name.strip():
        result.errors.append("species_name is required")
    elif len(species_name.strip()) > 12:
        result.errors.append("species_name exceeds 12 character limit")

    description = data.get("description")
    if description is not None:
        if not isinstance(description, str):
            result.errors.append("description must be text")
        elif len(description) > 180:
            result.errors.append("description exceeds 180 character limit")

    cry_id = data.get("cry_id")
    if cry_id is not None and (not isinstance(cry_id, str) or not cry_id.startswith("CRY_")):
        result.errors.append("cry_id must start with CRY_")

    ev_yields = data.get("ev_yields")
    if ev_yields is not None:
        if not isinstance(ev_yields, dict):
            result.errors.append("ev_yields must be object")
        else:
            for key in ["hp", "attack", "defense", "speed", "sp_attack", "sp_defense"]:
                value = ev_yields.get(key, 0)
                if not isinstance(value, int) or value < 0 or value > 3:
                    result.errors.append(f"ev_yields.{key} out of range (0..3): {value}")

    folder_name = data.get("folder_name")
    if not isinstance(folder_name, str) or not folder_name.strip():
        result.errors.append("folder_name it is mandatory")

    base_stats = data.get("base_stats")
    required_stats = ["hp", "attack", "defense", "speed", "sp_attack", "sp_defense"]
    if not isinstance(base_stats, dict):
        result.errors.append("base_stats is required")
    else:
        for stat in required_stats:
            if stat not in base_stats:
                result.errors.append(f"base_stats.{stat} lost")

    types = data.get("types")
    abilities = data.get("abilities")
    if not isinstance(types, list) or len(types) == 0:
        result.errors.append("types must be non-empty list")
    if not isinstance(abilities, list) or len(abilities) == 0:
        result.errors.append("abilities should be a non-empty list")
    else:
        normalized_abilities = [str(a).strip() for a in abilities]
        if not any(normalized_abilities):
            result.errors.append("abilities cannot be empty")
        for a in normalized_abilities:
            if a and not a.startswith("ABILITY_"):
                result.errors.append(f"ability invalid: {a}")

    if isinstance(types, list):
        normalized_types = [str(t).strip() for t in types if str(t).strip()]
        if len(normalized_types) == 0:
            result.errors.append("types must contain at least a valid TYPE_")
        for t in normalized_types:
            if not t.startswith("TYPE_"):
                result.errors.append(f"type invalid: {t}")

    if mode == "edit":
        result.asset_sources = {}
        return result

    assets_folder_raw = data.get("assets_folder")
    assets_folder = None
    if isinstance(assets_folder_raw, str) and assets_folder_raw.strip():
        assets_folder = (json_path.parent / assets_folder_raw).resolve()
    else:
        result.warnings.append("assets_folder not provided; asset fallback was attempted")

    resolved_assets: dict[str, Path] = {}
    missing_assets: list[str] = []

    if assets_folder and assets_folder.exists():
        for asset in REQUIRED_ASSETS:
            candidate = assets_folder / asset
            if candidate.exists():
                resolved_assets[asset] = candidate
            else:
                missing_assets.append(asset)
    else:
        missing_assets = REQUIRED_ASSETS.copy()

    if missing_assets:
        if fallback_folder:
            fallback_root = project_root / "graphics" / "pokemon" / fallback_folder
            used_any = False
            for asset in missing_assets:
                aliases = FALLBACK_ALIASES.get(asset, [asset])
                selected = None
                for alias in aliases:
                    fallback_candidate = fallback_root / alias
                    if fallback_candidate.exists():
                        selected = fallback_candidate
                        break
                if selected is not None:
                    resolved_assets[asset] = selected
                    used_any = True
            if used_any:
                result.used_fallback = True
                result.fallback_species_folder = fallback_folder
                result.warnings.append(
                    f"Used fallback assets from graphics/pokemon/{fallback_folder} for missing files"
                )

    still_missing = [a for a in REQUIRED_ASSETS if a not in resolved_assets]
    if still_missing:
        result.errors.append(
            "Could not resolve all required assets: " + ", ".join(still_missing)
        )

    result.asset_sources = resolved_assets
    return result
