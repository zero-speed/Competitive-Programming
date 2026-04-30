#!/usr/bin/env python3
import argparse
from collections import defaultdict
from pathlib import Path

IGNORE_DEFAULT = {"test.cpp", "tests.cpp", "example.cpp"}

# Plantilla LaTeX personalizada
TEMPLATE_HEADER = r"""\documentclass[9pt]{article}

% ====== PAQUETES ======
\usepackage[a4paper,margin=1.0cm,landscape]{geometry}
\usepackage[T1]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage{microtype}
\usepackage{multicol}
\usepackage{titlesec}
\usepackage{fancyhdr}
\usepackage{lastpage}
\usepackage{array}
\usepackage{xcolor}
\usepackage{amssymb}
\usepackage{hyperref}
\hypersetup{
    colorlinks=true,
    linkcolor=black,
    urlcolor=blue,
    citecolor=black
}
\usepackage{listings}

% ====== COLORES ======
\definecolor{accent}{RGB}{0,102,204}
\definecolor{backgray}{gray}{0.97}

% ====== ESTILO DE CODIGO (DEL PRIMERO ��) ======
\lstdefinestyle{Competitive}{
  backgroundcolor=\color{backgray},
  basicstyle=\ttfamily\scriptsize,
  breaklines=true,
  breakatwhitespace=true,
  keepspaces=true,
  columns=fullflexible,
  frame=single,
  numbers=left,
  numberstyle=\tiny,
  showstringspaces=false,
  tabsize=2,
  language=C++
}

% ====== HEADER / FOOTER ======
\pagestyle{fancy}
\fancyhf{}

\fancyhead[L]{Notebook ICPC}



\fancyfoot[C]{\small \thepage/\pageref{LastPage} \;|\; huevo el contest}

\setlength{\headheight}{35pt}
\setlength{\headsep}{5pt}
\setlength{\footskip}{12pt}

% ====== TITULOS ======
\titleformat{\section}
  {\color{accent}\bfseries\small}
  {}
  {0em}
  {}

\setlength{\columnsep}{1.0cm}

\begin{document}

% ================= HOJA 1 =================
\begin{multicols}{2}

% ====== PORTADA ======
\begin{center}
\vspace*{1cm}

{\Huge \bfseries Notebook ICPC}

\vspace{0.3cm}
{\Large \textcolor{accent}{Programación Competitiva}}

\vspace{1cm}
\rule{0.6\columnwidth}{0.5pt}

\vspace{0.5cm}

{\large Equipo XYZ}

\vspace{0.3cm}
{\small UNSAAC / INFO XD}

\vspace{0.5cm}

{\small
-------- \\
-------- \\
--------
}

\vspace{1cm}

{\small \today}

\end{center}

\vfill
\columnbreak

% ====== INDICE ======
\tableofcontents

\end{multicols}

\newpage

% ================= CONTENIDO =================
\begin{multicols}{2}
"""

TEMPLATE_TABLES = r"""
\end{multicols}

\newpage

% ================= TABLAS GRANDES =================

\newcommand{\problemstable}{
\renewcommand{\arraystretch}{1.8}
\begin{center}
\begin{tabular}{|c|p{5cm}|c|p{14cm}|c|}
\hline
\textbf{Problem} & \textbf{Tags} & \textbf{Complexity} & \textbf{Observations} & \textbf{\checkmark} \\
\hline
A & & & & \\
\hline
B & & & & \\
\hline
C & & & & \\
\hline
D & & & & \\
\hline
E & & & & \\
\hline
F & & & & \\
\hline
G & & & & \\
\hline
H & & & & \\
\hline
I & & & & \\
\hline
J & & & & \\
\hline
K & & & & \\
\hline
L & & & & \\
\hline
M & & & & \\
\hline
N & & & & \\
\hline
\end{tabular}
\end{center}
}

% ====== TABLAS ======
\section*{Concursante 1}
\problemstable

\newpage

\section*{Concursante 2}
\problemstable

\newpage

\section*{Concursante 3}
\problemstable

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
    for file in sorted(source_dir.rglob('*')):
        if file.suffix.lower() not in {'.cpp', '.txt'}:
            continue
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
        raise SystemExit('No se encontraron archivos .cpp o .txt en ' + str(source_dir))

    body_lines = [TEMPLATE_HEADER]

    for rel_dir in sorted(files_by_dir.keys(), key=lambda x: str(x).lower()):
        section_title = format_section_name(rel_dir)
        body_lines.append(f"\\section{{{latex_escape(section_title)}}}\n")

        files = sorted(files_by_dir[rel_dir], key=lambda p: p.name.lower())
        for fp in files:
            display = fp.stem.replace('_', ' ').title()
            body_lines.append(f"\\subsection{{{latex_escape(display)}}}\n")
            relative_cpp_path = fp.as_posix()
            safe_path = f"\\detokenize{{{relative_cpp_path}}}"
            body_lines.append('\n'.join([
                f"\\lstinputlisting[style=Competitive, caption={{ {latex_escape(fp.name)} }}, label={{lst:{latex_escape(fp.stem)}}}]{{{safe_path}}}",
                ""
            ]))

    body_lines.append(TEMPLATE_TABLES)

    output_file.write_text('\n'.join(body_lines), encoding='utf-8')
    print(f"main.tex generado: {output_file}")


def main():
    parser = argparse.ArgumentParser(description='Generar main.tex para notebook competitivo a partir de .cpp y .txt')
    parser.add_argument('--source', default='notebook', help='Directorio raíz de notebook (default notebook)')
    parser.add_argument('--output', default='main.tex', help='Archivo TeX de salida (default main.tex)')
    parser.add_argument('--ignore', nargs='*', default=[], help='Nombres de archivos a ignorar (test.cpp)')
    args = parser.parse_args()

    source_dir = Path(args.source)
    output_file = Path(args.output)

    if not source_dir.exists() or not source_dir.is_dir():
        fallback_steps = [Path('notebook'), Path('note book')]
        if source_dir in fallback_steps:
            fallback_steps = [p for p in fallback_steps if p != source_dir]
        found = None
        for candidate in fallback_steps:
            if candidate.exists() and candidate.is_dir():
                found = candidate
                break
        if found is not None:
            print(f"Atención: carpeta {source_dir} no existe; usando {found} en su lugar.")
            source_dir = found
        else:
            raise SystemExit(f"Directorio de source no existe: {source_dir}. Prueba con 'notebook' o 'note book'.")

    ignore_names = IGNORE_DEFAULT.union({n.strip() for n in args.ignore})

    generate_main_tex(source_dir, output_file, ignore_names)


if __name__ == '__main__':
    main()
