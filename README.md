# mini-ncu

A simulator of the network control unit (NCU) of an optical network node. Tasks are listed in `tasks.md`.

## Building the backend

Requirements: CMake ≥ 3.20, a C++20 compiler (GCC 13+ or Clang 17+, `<format>` is required), and Ninja (optional).

Run all commands from the repository root. Sources live in `backend/`, build output goes to `build/` (ignored by git).

### 1. Configure

```sh
cmake -S backend -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DNCU_SANITIZE=ON
```

- `-S` — directory containing `CMakeLists.txt`; `-B` — build directory.
- `-G Ninja` — generator; without it CMake uses Makefiles.
- `-DCMAKE_BUILD_TYPE=Debug` — build type: `Debug`, `Release`, `RelWithDebInfo`.
- `-DNCU_SANITIZE=ON` — enable AddressSanitizer and UBSan.

You only need to reconfigure when changing options. Edits to `CMakeLists.txt` are usually picked up automatically on the next build.

### 2. Build

```sh
cmake --build build
```

### 3. Run

```sh
./build/mini-ncu
```

### Useful commands

```sh
# Clean rebuild
cmake --build build --clean-first

# Separate release build without sanitizers, next to the debug one
cmake -S backend -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DNCU_SANITIZE=OFF
cmake --build build-release

# Show current build options
cmake -L -N build | grep -E 'CMAKE_BUILD_TYPE|NCU_'

# Start from scratch (stale CMake cache or generator change)
rm -rf build
```
