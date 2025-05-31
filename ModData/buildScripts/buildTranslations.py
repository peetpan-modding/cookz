import csv
import json
import sys
import os
import re
from io import StringIO

def read_json(input_path):
    with open(input_path, 'r', encoding='utf-8') as file:
        return json.load(file)

def validate_and_flatten(data):
    rows = []
    languages = ["en", "cs", "de", "ru", "pl", "it", "es", "fr", "zh", "ja", "pt", "zh-cn"]

    for key, translations in data.items():
        row = {"key": key, "original": translations.get("en", "")}

        for lang in languages:
            if key.endswith("Opened_DS"):
                row[lang] = translations.get(lang, translations.get("en", "")) or translations.get("en", "")
            else:
                if lang not in translations or not translations[lang]:
                    raise ValueError(f"Missing translation for key {key} language: {lang}")
                row[lang] = translations[lang]

        rows.append(row)

    return rows

def resolve_references(rows, data):
    key_pattern = re.compile(r'@([a-zA-Z0-9_&]+)')
    languages = ["original", "en", "cs", "de", "ru", "pl", "it", "es", "fr", "zh", "ja", "pt", "zh-cn"]

    for row in rows:
        for lang in languages:
            value = row[lang]
            matches = key_pattern.findall(value)

            for key_ref in matches:
                if key_ref in data:
                    replacement = data[key_ref].get(lang, data[key_ref].get("en", ""))
                    value = value.replace(f"@{key_ref}", replacement)
                else:
                    raise ValueError(f"Key '{key_ref}' not found in the data structure for language '{lang}'")

            row[lang] = value

def write_csv(output_path, rows):
    header = [
        "Language", "original", "english", "czech", "german", "russian", "polish", "italian", "spanish",
        "french", "chinese", "japanese", "portuguese", "chinesesimp"
    ]

    buffer = StringIO()
    writer = csv.writer(buffer, quotechar='"', quoting=csv.QUOTE_ALL)
    writer.writerow(header)

    for row in rows:
        if not row["key"].startswith("&"):
            writer.writerow([
                f"STR_{row['key']}", row["original"], row["en"], row["cs"], row["de"], row["ru"], row["pl"],
                row["it"], row["es"], row["fr"], row["zh"], row["ja"], row["pt"], row["zh-cn"]
            ])

    # Add trailing comma to each line
    lines = buffer.getvalue().splitlines()
    content_with_commas = "\n".join(line + "," for line in lines) + "\n"

    if csv_content_changed(output_path, content_with_commas):
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write(content_with_commas)
        print(f"Updated {output_path} - {len(rows)} rows")
    else:
        print(f"Skipped writing {output_path} (no changes)")

def csv_content_changed(path, new_content):
    if not os.path.exists(path):
        return True
    with open(path, 'r', encoding='utf-8') as file:
        existing_content = file.read()
    return existing_content != new_content

def main():
    if len(sys.argv) < 3:
        print(f"Usage: python {os.path.basename(__file__)} <input.json> <output.csv>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    data = read_json(input_path)
    rows = validate_and_flatten(data)
    resolve_references(rows, data)
    write_csv(output_path, rows)

if __name__ == "__main__":
    main()
