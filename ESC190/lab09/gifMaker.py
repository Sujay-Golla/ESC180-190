import os
from PIL import Image, ImageEnhance

# Paths
ASSETS_DIR = os.path.join(os.path.dirname(__file__), "assets")
INPUT_NAME = "cannon.jpg"
OUTPUT_NAME = "cannon_brightrend.gif"

# NOTE: create the assets directory manually before running (no auto-create)
#   mkdir lab09/assets
input_path = os.path.join(ASSETS_DIR, INPUT_NAME)
output_path = os.path.join(ASSETS_DIR, OUTPUT_NAME)

if not os.path.isfile(input_path):
    raise FileNotFoundError(
        f"Input image not found: {input_path}.\n" 
        "Place cannon.jpg into the assets folder and run again."
    )

# Load source image
img = Image.open(input_path).convert("RGB")

# Build brightness factors:
# - first half: darker->normal->brighter
# - second half: brighter->normal->darker for smooth loop
frames = []
steps = 20
min_factor = 0.4
max_factor = 2.2

# generate increasing brightness from min to max
for i in range(steps):
    factor = min_factor + (max_factor - min_factor) * (i / (steps - 1))
    frames.append(ImageEnhance.Brightness(img).enhance(factor))

# generate decreasing brightness from max to min (excluding endpoints to avoid duplicate frames)
for i in range(1, steps - 1):
    factor = max_factor - (max_factor - min_factor) * (i / (steps - 1))
    frames.append(ImageEnhance.Brightness(img).enhance(factor))

# Save as animated GIF
frames[0].save(
    output_path,
    save_all=True,
    append_images=frames[1:],
    optimize=False,
    duration=80,
    loop=0,
)

print(f"Saved GIF: {output_path} ({len(frames)} frames)")
