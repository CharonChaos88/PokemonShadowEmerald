import urllib.request
import re
import math

req = urllib.request.Request('https://prnt.sc/y4GqJGMMFusV', headers={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'})
try:
    html = urllib.request.urlopen(req).read().decode('utf-8')
    m = re.search(r'<img[^>]+src=\"([^\"]+)\"[^>]+id=\"screenshot-image\"', html)
    if m:
        img_url = m.group(1)
        if img_url.startswith('//'): img_url = 'https:' + img_url
        print("Image URL:", img_url)
        # Download it
        req2 = urllib.request.Request(img_url, headers={'User-Agent': 'Mozilla/5.0'})
        img_data = urllib.request.urlopen(req2).read()
        print("Downloaded bytes:", len(img_data))
        with open("screenshot.png", "wb") as f:
            f.write(img_data)
        print("Saved to screenshot.png")
    else:
        print("No image found in HTML")
except Exception as e:
    print("Error:", e)
