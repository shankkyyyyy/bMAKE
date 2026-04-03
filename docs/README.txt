BMAKE - Simple C Build System
==============================

Overview
--------
BMAKE is a lightweight, command-line build tool designed for small to medium-sized C projects. Unlike complex build systems like CMake or Make, BMAKE focuses on simplicity and ease of use, making it ideal for developers who want quick compilation without the overhead of advanced features.

Why BMAKE?
----------
- **Simplicity**: Easy to learn and use with minimal configuration.
- **Portability**: Works on any system with GCC and standard C libraries.
- **Flexibility**: Supports custom flags, libraries, and output files.
- **Incremental Builds**: Generate a config file for repeatable builds.
- **No Dependencies**: Just compile and run—no external tools needed.

Key Features
-------------
- Generate build configurations with `-e` (edit mode).
- Compile using saved configs with `-s` (build mode).
- Add arguments dynamically with `-a` (append mode).
- Colored output for better user experience (errors in red, success in green).
- Handles multiple source files and libraries seamlessly.

Installation
------------
1. Clone the repository: `git clone https://github.com/shankkyyyyy/bMAKE.git`
2. Navigate to the project: `cd bMAKE`
3. Compile: `gcc src/*.c -o bin/bmake`
4. Run: `./bin/bmake help`

Usage Examples
--------------
- Create a config: `Bmake -e main.c -lcrypto -sdl -o output.elf`
- Build from config: `Bmake -s`
- Add flags: `Bmake -a -lm -o2`
- Show help: `Bmake help`

File Structure
--------------
- `src/`: Source code files
- `include/`: Header files
- `bin/`: Compiled binary
- `docs/`: Documentation (this folder)
- `test/`: Test files

Contributing
------------
Feel free to submit issues or pull requests on GitHub. This project is open-source and welcomes improvements.

License
-------
MIT License - See LICENSE file for details.

Author
------
Shankkyyyyy (with contributions from ninefour)

Version
-------
1.0.0
