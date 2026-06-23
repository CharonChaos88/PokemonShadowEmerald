import re

files = [
    "src/battle_script_commands.c",
    "src/bad_egg_virus.c",
    "src/ui_main_menu.c",
    "src/party_menu.c"
]

for file in files:
    with open(file, "r") as f:
        content = f.read()

    # Remove the hack in party_menu.c
    content = re.sub(r'#undef gPlayerPartyCount\n#define gPlayerPartyCount gPartiesCount\[B_TRAINER_PLAYER\]\n', '', content)

    # Replace occurrences
    content = re.sub(r'\bgPlayerPartyCount\b', 'gPartiesCount[B_TRAINER_PLAYER]', content)
    content = re.sub(r'\bgPlayerParty\b', 'gParties[B_TRAINER_PLAYER]', content)

    with open(file, "w") as f:
        f.write(content)
print("Done")
