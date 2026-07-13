import sys
import math

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

normal_pal = read_pal('normal.pal')
stellar_pal = read_pal('stellar.pal')

mapping = {}
for i, sc in enumerate(stellar_pal):
    # Find closest color in normal_pal
    best_j = 0
    best_dist = 999999
    for j, nc in enumerate(normal_pal):
        dist = (sc[0]-nc[0])**2 + (sc[1]-nc[1])**2 + (sc[2]-nc[2])**2
        if dist < best_dist:
            best_dist = dist
            best_j = j
    mapping[i] = best_j
    print(f"Stellar {i} {sc} -> Normal {best_j} {normal_pal[best_j]} (dist {best_dist})")

print("Mapping dict:", mapping)
