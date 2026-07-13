import urllib.request
import struct

def get_png_info(url):
    req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
    with urllib.request.urlopen(req) as response:
        data = response.read()
    print(f"Downloaded {len(data)} bytes from {url}")
    # PNG signature: 89 50 4E 47 0D 0A 1A 0A
    if data[:8] != b'\x89PNG\r\n\x1a\n':
        print("Not a PNG")
        return
    
    # We don't have PIL, so we can't easily parse IDAT, but we can see PLTE if present.
    i = 8
    while i < len(data):
        length = struct.unpack('>I', data[i:i+4])[0]
        chunk_type = data[i+4:i+8]
        if chunk_type == b'PLTE':
            print("PLTE chunk found!")
        i += 12 + length

get_png_info('https://img.lightshot.app/eUb3559IQdm_bEp65ieaQA.png')
get_png_info('https://img.lightshot.app/NbSCrC0UTamAq_hF0ttkQg.png')
