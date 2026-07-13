import sys

def read_pal(path):
    with open(path, 'r') as f:
        lines = f.read().splitlines()
    assert lines[0] == "JASC-PAL"
    num_colors = int(lines[2])
    colors = []
    for line in lines[3:3+num_colors]:
        r, g, b = map(int, line.split())
        colors.append((r, g, b))
    return colors

def write_pal(path, colors):
    with open(path, 'w') as f:
        f.write("JASC-PAL\n0100\n16\n")
        for c in colors:
            f.write(f"{c[0]} {c[1]} {c[2]}\n")

tera_pal = read_pal('tera_types.pal')
# Palette 2 is colors 32 to 47
correct_colors = tera_pal[32:48]
write_pal('stellar_correct.pal', correct_colors)

# Read stellar.pal
stellar_pal = read_pal('stellar.pal')

# Create mapping from stellar index to correct index
mapping = {}
for i, sc in enumerate(stellar_pal):
    # Find closest color in correct_colors
    best_j = 0
    best_dist = 999999
    for j, cc in enumerate(correct_colors):
        dist = (sc[0]-cc[0])**2 + (sc[1]-cc[1])**2 + (sc[2]-cc[2])**2
        if dist < best_dist:
            best_dist = dist
            best_j = j
    mapping[i] = best_j

print("Mapping dict:", mapping)

# Read stellar.4bpp
with open('graphics/types_bw/tera/stellar.4bpp', 'rb') as f:
    data = f.read()

# Remap
new_data = bytearray()
for b in data:
    low = b & 0x0F
    high = (b >> 4) & 0x0F
    
    new_low = mapping[low]
    new_high = mapping[high]
    
    new_b = (new_high << 4) | new_low
    new_data.append(new_b)

with open('stellar_mapped.4bpp', 'wb') as f:
    f.write(new_data)
