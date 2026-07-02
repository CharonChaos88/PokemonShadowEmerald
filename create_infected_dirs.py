import os
import shutil

def copy_pokemon_files():
    graphics_dir = os.path.join('graphics', 'pokemon')

    if not os.path.exists(graphics_dir):
        print(f"Error: Directory {graphics_dir} does not exist. Run this in the project root.")
        return

    processed_count = 0

    # os.walk deeply scans all directories and nested subdirectories
    for root, dirs, files in os.walk(graphics_dir):
        
        # Prevent the script from scanning inside 'infected' folders it just created
        if 'infected' in dirs:
            dirs.remove('infected')

        # Check if this folder actually holds Pokemon sprites
        # If it doesn't have a front sprite or palette, skip it
        has_sprite = any(f in files for f in ['anim_front.png', 'front.png', 'normal.pal'])
        if not has_sprite:
            continue

        # We found a valid Pokemon form folder. Create the infected directory.
        infected_dir = os.path.join(root, 'infected')
        os.makedirs(infected_dir, exist_ok=True)

        files_to_copy = []

        ### UNIFIED COPY LOGIC ###
        # Because we explicitly whitelist these files, overworld, icon, and GBA files 
        # are naturally ignored. It will grab 2-frame if available, or fallback to 1-frame.

        # 1. Front Male (Prefer anim_front, fallback to front)
        if 'anim_front.png' in files:
            files_to_copy.append('anim_front.png')
        elif 'front.png' in files:
            files_to_copy.append('front.png')

        # 2. Front Female (Prefer anim_frontf, fallback to frontf)
        if 'anim_frontf.png' in files:
            files_to_copy.append('anim_frontf.png')
        elif 'frontf.png' in files:
            files_to_copy.append('frontf.png')

        # 3. Back Male
        if 'back.png' in files:
            files_to_copy.append('back.png')

        # 4. Back Female
        if 'backf.png' in files:
            files_to_copy.append('backf.png')

        # 5. Palettes
        if 'normal.pal' in files:
            files_to_copy.append('normal.pal')
        if 'shiny.pal' in files:
            files_to_copy.append('shiny.pal')

        # Execute file copies
        copied_any = False
        for file in files_to_copy:
            src = os.path.join(root, file)
            dst = os.path.join(infected_dir, file)
            shutil.copy2(src, dst)
            copied_any = True
            
        if copied_any:
            processed_count += 1
            # Uncomment the line below if you want to see exactly which folders it processes:
            # print(f"Infected: {root}")

    print(f"Success! Processed {processed_count} Pokémon directories and subdirectories.")

if __name__ == '__main__':
    copy_pokemon_files()