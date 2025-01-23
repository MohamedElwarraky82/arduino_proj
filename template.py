from jinja2 import Environment, FileSystemLoader
import json

env = Environment(loader = FileSystemLoader('templates'))
template = env.get_template('doc_test_report.tex.j2')

data_file = "build/results.json"

# Open and read the JSON file
with open(data_file, 'r') as file:
    data = json.load(file)

output = template.render(data)

with open("doc/test_report/doc_test_report.tex", 'w') as f:
    f.write(output)