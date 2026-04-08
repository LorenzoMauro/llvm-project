import shutil
import subprocess
import os
import sys
import pathlib

# Get absolute paths based on the script location
script_dir = os.path.dirname(os.path.abspath(__file__))

clang_format = os.path.join(script_dir, "..", "build", "release", "bin", "clang-format")
# if on Windows, add .exe extension
if os.name == "nt":
    clang_format += ".exe"
input_file = os.path.join(script_dir, "tests", "unformattedFile.cpp")
output_file = os.path.join(script_dir, "tests", "formattedFile.cpp")

# Step 1: Check if clang-format exists
if not os.path.isfile(clang_format):
    print(f"Error: clang-format not found at {clang_format}")
    sys.exit(1)

# Step 2: Check if input file exists
if not os.path.isfile(input_file):
    print(f"Error: input file not found at {input_file}")
    sys.exit(1)

# Step 3: Copy input to output
shutil.copyfile(input_file, output_file)
print(f"Copied {input_file} to {output_file}")

# Step 4: Run clang-format
try:
    subprocess.run([clang_format, "-style=file", "-i", "--verbose", output_file], check=True)
    print(f"Formatted {output_file} with clang-format")
    pathlib.Path(output_file).touch()  # Update the last modified time
except subprocess.CalledProcessError as e:
    print("Error running clang-format:", e)
    sys.exit(1)
