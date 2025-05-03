import os
import subprocess
import argparse

IMAGETOPAA_EXE = r"C:\Steam\steamapps\common\DayZ Tools\Bin\ImageToPAA\ImageToPAA.exe"

def convert_matching_paa_files(base_path, target_filename):
    target_filename = target_filename.lower()
    
    for root, _, files in os.walk(base_path):
        for file in files:
            if file.lower().endswith(".paa") and file.lower() == target_filename:
                paa_path = os.path.join(root, file)
                png_path = paa_path[:-4] + ".png"

                try:
                    print(f"Converting {paa_path} -> {png_path}")
                    subprocess.run([IMAGETOPAA_EXE, paa_path, png_path], check=True)

                    print(f"Converting {png_path} -> {paa_path}")
                    subprocess.run([IMAGETOPAA_EXE, png_path, paa_path], check=True)

                    print(f"Deleting {png_path}")
                    os.remove(png_path)
                except subprocess.CalledProcessError as e:
                    print(f"Error processing {file}: {e}")
                except Exception as e:
                    print(f"Unexpected error: {e}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Reconvert a specific .paa file using ImageToPAA.")
    parser.add_argument("path", help="Root folder to start searching")
    parser.add_argument("filename", help="Filename of the .paa to process (e.g., cookz_generic_baked_co.paa)")
    args = parser.parse_args()

    convert_matching_paa_files(args.path, args.filename)
