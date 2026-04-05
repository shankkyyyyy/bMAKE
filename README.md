# 🚀 BMAKE - Simple C Build System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build Status](https://img.shields.io/badge/Build-Passing-green.svg)]()

> A lightweight, no-nonsense build tool for C projects. Perfect for small projects where CMake feels like overkill.

## ✨ Why BMAKE?

- **🛠️ Simplicity First**: No complex configurations or dependencies. Just compile and go.
- **🎯 Focused**: Designed for C developers who want quick builds without the bloat.
- **🔄 Repeatable**: Save your build configs and reuse them effortlessly.
- **🌈 Colored Output**: Errors in red, success in green – because who likes boring terminals?
- **📦 Portable**: Works anywhere GCC and standard C libs are available.

## 📦 Installation

```bash
# Clone the repo
git clone https://github.com/shankkyyyyy/bMAKE.git
cd bMAKE

# Compile
gcc src/*.c -o bin/bmake

# Test it
./bin/bmake help
```

## 🚀 Usage

### Create a Build Config
```bash
Bmake -e main.c -lcrypto -sdl -o output.elf
```
This generates a `.Bmake.txt` config file.

### Build from Config
```bash
Bmake -s
```
Compiles using the saved config.

### Add More Arguments
```bash
Bmake -a -lm -O2
```
Appends flags to the existing config.

### Get Help
```bash
Bmake help
```

## 📁 Project Structure

```
bMAKE/
├── src/           # Source files (main.c, parse.c, etc.)
├── include/       # Headers
├── bin/           # Compiled binary
├── docs/          # Documentation
├── test/          # Test files
└── README.md      # This file
```

## 🔧 How It Works

1. **Config Mode (-e)**: Parses your command and saves it to `.Bmake.txt`.
2. **Build Mode (-s)**: Reads the config and runs GCC.
3. **Append Mode (-a)**: Adds more flags to the config.

The config file looks like this:
```
[FILENAME]
main.c
[ARGUMENTS]
-lcrypto
-sdl
[ENDOFARGUMENTS]
[OUTPUT]
output.elf
```

## 🤝 Contributing

Found a bug or have a feature idea? Open an issue or PR on GitHub!

## 📄 License

MIT License - Free to use, modify, and distribute.

## 👨‍💻 Author

**Shankkyyyyy** (with help from ninefour)

---

*Made with ❤️ for C developers who just want to build stuff.*