# pharo.stack.spur.wasm

Compiles OSVM Stack interpreter to WebAssembly using the Emscripten compiler.
Emscripten can be used as a drop-in replacement for gcc/clang and cmake.
Based on MinHeadless Linux 32bit sources, as Emscripten provides Linux-like environment (pthreads, nanosleep, dlopen, file system).
Check the latest few commits of maenu to see changed files.

## Build & Run

### 1. Install Emscripten

I installed [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) to get an all-in-one package.

### 2. Grab an image

Grab a 32bit Smalltalk image and but it in the `image` folder. I used Pharo 9.

```
cd building/minheadless.cmake/x86/pharo.stack.spur.wasm
mkdir image
cd image
curl https://get.pharo.org/32/90 | bash
```

### 3. Build VM

```./mvm_configure_variant release Release && make -C release install```

### 4. Run a web server

```emrun --port 9090 --serve_root ../../../../ --no_browser .```

### 5. Launch VM

[http://localhost:9090/building/minheadless.cmake/x86/pharo.stack.spur.wasm/release/dist/pharo.html](http://localhost:9090/building/minheadless.cmake/x86/pharo.stack.spur.wasm/release/dist/pharo.html)

### 6. Inspect running VM

The VM is compiled with DWARF debug information, which is understood by the Chrome debugger.
So we can step through the C sources of the WebAssembly, pretty nifty.

## Resources

* [Inspect WebAssembly (at the bottom)](https://webassembly.org/getting-started/developers-guide/)
* [Emscripten doc (Porting)](https://emscripten.org/docs/porting/index.html)
* [Emscripten settings](https://emsettings.surma.technology/)
