import sys
with open('graphics/fonts/latin_normal.1bpp', 'rb') as f:
    data = f.read()

out = "const unsigned char font[] = {\n"
for i in range(0, len(data), 8):
    chunk = data[i:i+8]
    if len(chunk) < 8: break
    out += "    " + ", ".join([hex(b) for b in chunk]) + ",\n"
out += "};\n"

with open('multiboot_payload/font.h', 'w') as f:
    f.write(out)
