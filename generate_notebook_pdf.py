#!/usr/bin/env python3
import argparse
from collections import defaultdict
from pathlib import Path

IGNORE_DEFAULT = {"test.cpp", "tests.cpp", "example.cpp"}

LATEX_HEADER = r"""\documentclass[10pt,twocolumn]{article}
\usepackage[margin=0.7cm]{geometry}
\usepackage[T1]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage{microtype}
\usepackage{parskip}
\usepackage{hyperref}
\hypersetup{colorlinks=true, linkcolor=blue, urlcolor=blue}
\usepackage{listings}
\usepackage{xcolor}
\definecolor{codegray}{gray}{0.92}
\definecolor{backgray}{gray}{0.98}
\lstdefinestyle{Competitive}{
  backgroundcolor=\color{backgray},
  basicstyle=\ttfamily\scriptsize,
  breaklines=true,
  breakatwhitespace=true,
  keepspaces=true,
  columns=fullflexible,
  frame=single,
  rulecolor=\color{gray},
  numbers=left,
  numberstyle=\tiny,
  showstringspaces=false,
  showtabs=false,
  tabsize=2,
  captionpos=b,
  language=C++
}

\title{Notebook de Programación Competitiva}
\author{Generado automáticamente}
\date{\today}

\begin{document}
\maketitle
\tableofcontents
\vspace{0.5cm}
"""

LATEX_FOOTER = r"""
\end{document}
"""


def latex_escape(text: str) -> str:
    replacements = {
        "&": "\\&",
        "%": "\\%",
        "$": "\\$",
        "#": "\\#",
        "_": "\\_",
        "{" : "\\{",
        "}" : "\\}",
        "~": "\\textasciitilde{}",
        "^": "\\textasciicircum{}",
        "\\": "\\textbackslash{}",
    }
    for k, v in replacements.items():
        text = text.replace(k, v)
    return text


def format_section_name(rel_path: Path) -> str:
    if rel_path == Path('.'):
        return "General"
    parts = [p.replace('_', ' ').strip().title() for p in rel_path.parts if p != '.']
    made = ' / '.join(parts)
    return made if made else 'General'


def scan_files(source_dir: Path, ignore_names: set) -> dict:
    files_by_dir = defaultdict(list)
    for file in sorted(source_dir.rglob('*.cpp')):
        if file.name in ignore_names:
            continue
        # ignora ficheros dentro de cualquier carpeta "tests" o con prefijo test
        if 'tests' in [p.lower() for p in file.parts] or file.name.lower().startswith('test'):
            continue
        rel = file.relative_to(source_dir)
        parent = rel.parent if rel.parent.parts else Path('.')
        files_by_dir[parent].append(file)
    return files_by_dir


def generate_main_tex(source_dir: Path, output_file: Path, ignore_names: set):
    files_by_dir = scan_files(source_dir, ignore_names)
    if not files_by_dir:
        raise SystemExit('No se encontraron archivos .cpp en ' + str(source_dir))

    body_lines = [LATEX_HEADER]

    for rel_dir in sorted(files_by_dir.keys(), key=lambda x: str(x).lower()):
        section_title = format_section_name(rel_dir)
        body_lines.append(f"\\section{{{latex_escape(section_title)}}}\n")

        files = sorted(files_by_dir[rel_dir], key=lambda p: p.name.lower())
        for fp in files:
            display = fp.stem.replace('_', ' ').title()
            body_lines.append(f"\\subsection{{{latex_escape(display)}}}\n")
            relative_cpp_path = fp.as_posix()
            body_lines.append('\n'.join([
                f"\\lstinputlisting[style=Competitive, caption={{ {latex_escape(fp.name)} }}, label={{lst:{latex_escape(fp.stem)}}}]{{{relative_cpp_path}}}",
                ""
            ]))

    body_lines.append(LATEX_FOOTER)

    output_file.write_text('\n'.join(body_lines), encoding='utf-8')
    print(f"main.tex generado: {output_file}")


def main():
    parser = argparse.ArgumentParser(description='Generar main.tex para notebook competitivo a partir de .cpp')
    parser.add_argument('--source', default='notebook', help='Directorio raíz de notebook (default notebook)')
    parser.add_argument('--output', default='main.tex', help='Archivo TeX de salida (default main.tex)')
    parser.add_argument('--ignore', nargs='*', default=[], help='Nombres de archivos a ignorar (test.cpp)')
    args = parser.parse_args()

    source_dir = Path(args.source)
    output_file = Path(args.output)

    if not source_dir.exists() or not source_dir.is_dir():
        raise SystemExit(f"Directorio de source no existe: {source_dir}")

    ignore_names = IGNORE_DEFAULT.union({n.strip() for n in args.ignore})

    generate_main_tex(source_dir, output_file, ignore_names)


if __name__ == '__main__':
    main()
