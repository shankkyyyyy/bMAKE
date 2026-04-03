# 🛠️ BMAKE - Simple C Build System

> A lightweight, command-line build tool for small to medium-sized C projects. No complexity, just compile.

---

## 🎯 Why BMAKE?

Building C projects shouldn't be complicated. While **CMake** and **Make** are powerful, they come with a steep learning curve. **BMAKE** strips away the complexity and gives you a tool that:

- ✅ **Just Works** - Simple commands, instant results
- ✅ **Lightweight** - No dependencies, just GCC and C
- ✅ **Flexible** - Supports custom flags, libraries, and outputs
- ✅ **Repeatable** - Save your build config and compile anytime
- ✅ **User-Friendly** - Colored output, clear error messages
- ✅ **Fast** - Quick compilation for small projects

Perfect for:
- Learning C programming
- Small utility projects
- Quick prototypes
- School assignments
- Personal projects

---

## 📦 Features

### 🔧 Three Essential Modes

| Command | Purpose | Example |
|---------|---------|---------|
| **`-e`** | Generate build config | `Bmake -e main.c -lcrypto -o output.elf` |
| **`-s`** | Build from saved config | `Bmake -s` |
| **`-a`** | Add arguments dynamically | `Bmake -a -lm -O2` |
| **`help`** | Show usage info | `Bmake help` |

### 🎨 User Experience

- **Colored Output**: Errors in 🔴 red, success in 🟢 green
- **Clear Messages**: Know exactly what's happening
- **Smart Config**: Save once, build multiple times
- **Append Mode**: Add libraries without regenerating

---

## 🚀 Quick Start

### Installation

```bash
# Clone the repository
git clone https://github.com/shankkyyyyy/bMAKE.git
cd bMAKE

# Compile BMAKE itself
gcc src/*.c -o bin/bmake

# Run it
./bin/bmake help
```

### Basic Usage

**Step 1: Create a config**
```bash
./bin/bmake -e main.c -lcrypto -sdl -o output.elf
```
This generates `.Bmake.txt` with your build settings.

**Step 2: Build anytime**
```bash
./bin/bmake -s
```
Compiles using the saved config.

**Step 3: Add more libraries (optional)**
```bash
./bin/bmake -a -lm
```
Appends `-lm` to your arguments without regenerating.

---

## 📁 Project Structure

```
Bmake/
├── src/               # Source code
│   ├── main.c         # Entry point & CLI handling
│   ├── parse.c        # Config file parser
│   ├── read.c         # File reading utilities
│   └── write.c        # Config file writer
├── include/           # Header files
│   ├── parse.h
│   ├── read.h
│   └── write.h
├── bin/               # Compiled binaries
│   └── bmake          # Main executable
├── docs/              # Documentation
│   ├── README.txt     # Text overview
│   ├── main.txt       # main.c details
│   ├── parse.txt      # parse.c details
│   └── io.txt         # read.c & write.c details
├── test/              # Test files
└── .Bmake.txt         # Generated config (after -e)
```

---

## 🔄 How It Works

### The Build Flow

```
┌─────────────────┐
│  Bmake -e       │  (1) Create config
└────────┬────────┘
         │
         ▼
┌─────────────────────────────────────┐
│  Generates .Bmake.txt               │  (2) File structure:
│  [FILENAME]                         │      - source file
│  main.c                             │      - arguments
│  [ARGUMENTS]                        │      - output name
│  -lcrypto                           │
│  -sdl                               │
│  [ENDOFARGUMENTS]                   │
│  [OUTPUT]                           │
│  output.elf                         │
└────────┬────────────────────────────┘
         │
         ▼
┌─────────────────┐
│  Bmake -s       │  (3) Read config & compile
└────────┬────────┘
         │
         ▼
┌─────────────────────────────────────┐
│  Runs:                              │  (4) Executes:
│  gcc main.c -lcrypto -sdl -o        │      gcc main.c -lcrypto -sdl
│  output.elf                         │      -o output.elf
└─────────────────────────────────────┘
         │
         ▼
    ✅ SUCCESS or ❌ ERROR
```

---

## 📝 Configuration File Format

BMAKE uses `.Bmake.txt` to store your build settings:

```
[FILENAME]
main.c
[ARGUMENTS]
-Wall
-Wextra
-lcrypto
-lm
[ENDOFARGUMENTS]
[OUTPUT]
output.elf
```

Easy to read, easy to modify manually if needed.

---

## 💡 Use Cases

### 1. Learning C
```bash
./bin/bmake -e hello.c -o hello
./bin/bmake -s
# ./hello
```

### 2. Multi-File Project
```bash
./bin/bmake -e main.c -Wall -Wextra -lm -o calculator
./bin/bmake -s
```

### 3. Library Linking
```bash
./bin/bmake -e server.c -pthread -lcrypto -lssl -o myserver
./bin/bmake -s
```

### 4. Adding More Flags Later
```bash
./bin/bmake -a -O3      # Add optimization
./bin/bmake -a -g       # Add debugging symbols
./bin/bmake -s          # Compile with all flags
```

---

## 🧪 Testing

Navigate to the `test/` folder:
```bash
cd test
../bin/bmake -e test.c -o test_app
../bin/bmake -s
```

---

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| `ERROR: Missing .Bmake.txt` | Run `Bmake -e <source> -o <output>` first |
| `ERROR: cannot open file` | Check file path and permissions |
| Compilation fails | Review flags and library names in the config |
| Colors not showing | Some terminals need `--color=always` |

---

## 🔐 Memory & Safety

- ✅ All allocated memory is freed
- ✅ File pointers properly closed
- ✅ No memory leaks (verified with Valgrind)
- ✅ Error handling on all critical operations

---

## 🤝 Contributing

Found a bug? Have an idea? Pull requests welcome!

1. Fork the repo
2. Create a feature branch (`git checkout -b feature/cool-feature`)
3. Commit your changes (`git commit -am 'Add cool feature'`)
4. Push to the branch (`git push origin feature/cool-feature`)
5. Open a Pull Request

---

## 📄 License

MIT License - See LICENSE file for details.

---

## 👨‍💻 Authors

- **Shankkyyyyy** - Main developer
- **Ninefour** - Contributions

---

## 📞 Support

For issues, questions, or suggestions:
- Open an issue on GitHub
- Check the `docs/` folder for detailed documentation
- Review code comments in `src/` files

---

## 🎉 Future Improvements

- [ ] Support for multiple source files
- [ ] Automatic dependency generation
- [ ] Configuration templates
- [ ] Build optimization profiles
- [ ] Cross-platform support (Windows batch files)

---

**Happy Building! 🚀**

*BMAKE - Where simplicity meets functionality.*