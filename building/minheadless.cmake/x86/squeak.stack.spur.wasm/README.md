# squeak.stack.spur.wasm

Compiles OSVM Stack interpreter to WebAssembly using the Emscripten compiler.
Emscripten can be used as a drop-in replacement for gcc/clang and cmake.
Based on MinHeadless Linux 32bit sources, as Emscripten provides Linux-like environment (pthreads, nanosleep, dlopen, file system).
Check the latest few commits of maenu to see changed files.

## Build & Run

### 1. Install Emscripten

I installed [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) to get an all-in-one package.

### 2. Grab an image

Grab a 32bit Smalltalk image and but it in the `image` folder, next to `build`, named `trunk6.image`.

### 3. Build VM

```./mvm_configure_variant release Release && make -C release install```

### 4. Run a web server

```emrun --port 9090 --serve_root ../../../../ --no_browser .```

### 5. Launch VM

[http://localhost:9090/building/minheadless.cmake/x86/squeak.stack.spur.wasm/release/dist/squeak.html](http://localhost:9090/building/minheadless.cmake/x86/squeak.stack.spur.wasm/release/dist/squeak.html)

### 6. Inspect running VM

The VM is compiled with DWARF debug information, which is understood by the Chrome debugger.
So we can step through the C sources of the WebAssembly, pretty nifty.
