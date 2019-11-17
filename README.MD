# The Book

The goal of this project is to learn high-level languages (C/C++ for now), LLVM IR and x86 assembly in parallel.
I have a collection a many source code examples (from really simple to complex), some from me, others from github repos.
The code is compiled to LLVM IR and assembly to understand it.

## Scripts

All scripts must be run from the root of the repo.

Generate .ll / .s files from a source directory:
```
CC=/home/obs/local/llvm10/bin/clang CXX=/home/obs/local/llvm10/bin/clang++ python3 scripts/gen_code.py myalgos/
```

Generate .ll / .s files from a git repo
```
CC=/home/obs/local/llvm10/bin/clang CXX=/home/obs/local/llvm10/bin/clang++ ./scripts/gen_from_git.sh <url> <branch> <dir>
```

Files are stored in the extern directory.

Generate from all sources:
```
CC=/home/obs/local/llvm10/bin/clang CXX=/home/obs/local/llvm10/bin/clang++ ./scripts/gen_all.sh ./extern/sources.txt
```

./extern/sources.txt is a list of github repos with C code.

## Code

### basics/c

Examples of really basic operations (function calls, structs, loops, ...)