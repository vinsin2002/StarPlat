## Build
#### Linux | MPI
This section is for Linux MPI
#### MacOS | MPI
By default, MacOS comes with the `clang` compiler, which can cause syntax errors when running the `make` command due to differences between `gcc` and `clang` semantics. To resolve this, follow these steps:

### Installation:

1. Install `gcc` using Homebrew:

   ```sh
   brew install gcc
   ```

2. Check the installation location of the `g++` binaries:

   ```sh
   which brew
   ll /opt/homebrew/bin/g++-*
   ```

3. Create symbolic links to the installed version, (presumes that the above command returns gcc-13):

   ```sh
   sudo ln -sf /opt/homebrew/bin/gcc-13 /usr/local/bin/gcc
   sudo ln -sf /opt/homebrew/bin/g++-13 /usr/local/bin/g++
   sudo ln -sf /opt/homebrew/bin/c++-13 /usr/local/bin/c++
   sudo ln -sf /opt/homebrew/bin/cpp-13 /usr/local/bin/cpp
   ```

   Note: Modifying anything in `/usr/bin/*` is discouraged and may require disabling SIP (System Integrity Protection). Therefore, we create symlinks to `/usr/local/bin/*`.

4. After installation, check the versions:

   ```sh
   g++ --version # Should return clang version
   g++-13 --version # Should return (Homebrew GCC)
   ```

5. Update the Makefile (`StarPlat/src/Makefile`) to use the symlinked `g++`:

   ```make
   CC = /usr/local/bin/g++
   ```
6. Add `%token return_func` in the file `lrparser.y` (`StarPlat/src/parser/lrparser.y`)