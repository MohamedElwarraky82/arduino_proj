from jinja2 import Environment, FileSystemLoader
import json, os

env = Environment(loader = FileSystemLoader('templates'))
template = env.get_template('doc_test_report.tex.j2')

data_file = "build/results.json"

# Open and read the JSON file
with open(data_file, 'r') as file:
    data = json.load(file)

output = template.render(data)

out_dir = "build/test_report"
if not os.path.exists(out_dir):
    os.makedirs(out_dir)

with open("build/test_report/doc_test_report.tex", 'w') as f:
    f.write(output)