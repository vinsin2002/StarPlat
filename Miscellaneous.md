## Miscellaneous

## Installing Boost Libraries to run StarPlat for MPI

On the root directory of `StarPlat`, running the command:

```sh
grep -r '<boost/' .
```

shows the files that use boost. This section provides a walkthrough of building, installing, and linking the boost libraries and source to create a program. The workflow has been tested on an arm64 architecture with a 64-bit address type on a Mac machine. While this guide is compiled from various sources, for a comprehensive understanding, please refer to the official boost documentation.

Our main goal is to build the following file with `mpic++` and run with `mpirun`:

```c++
#include <iostream>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

namespace mpi = boost::mpi;

int main() {
    mpi::environment env;
    mpi::communicator world;
    std::cout << "I am process " << world.rank() << " of " << world.size() << "." << std::endl;
    return 0;
}
```

The default compiler that comes with MacOS is clang, and StarPlat is built on `gcc`. Note that a C++ library compiled with GCC is not compatible with Clang and vice versa. So, we will build the libraries and code exclusively on one platform.

There are options to compile boost as a universal library agnostic to architecture (discussed [here](https://stackoverflow.com/questions/64553398/compile-boost-as-universal-library-intel-and-apple-silicon-architectures)), but for brevity, this walkthrough aims to run it on gcc/g++.

We will be building the boost library from the source, providing more autonomy and control over packages and libraries, and installation directories from where we can include headers and link libraries.

- **Step 1**: Download the tar file from boost/downloads.
- **Step 2**: Extract the tar file to a location using the command `tar -xvf boost.tar.gz`.
- **Step 3**: Create a directory anywhere with `mkdir -p /path/to/boost_version`.
- **Step 4**: Navigate to the extracted boost directory.
- **Step 5**: Run `./bootstrap.sh --prefix=/path/to/boost_version` to extract all the headers and binaries in the specified prefix location.
- **Step 6**: The bootstrap.sh will create a file called `project-config.jam`.
- **Step 7**: In the `project-config.jam` file, comment out the section related to the compiler configuration.

```jam
# Compiler configuration. This definition will be used unless
# you already have defined some toolsets in your user-config.jam
# file.
# if ! clang in [ feature.values <toolset> ]
# {
#    using clang ;
# }

# project : default-build <toolset>clang ;
```

- **Step 8**: Configure the project-config.jam to use gcc.

```jam
using gcc : <version> : /path/to/gcc
# Example
using gcc : 13.2 : /usr/local/bin/gcc
```

- **Step 9**: Install MPI by following the steps [here](https://docs.open-mpi.org/en/v5.0.x/installing-open-mpi/quickstart.html).
- **Step 10**: Add the following line to the `project-config.jam` file (notice the space between mpi and ;).

```jam
using mpi ;
```

- **Step 11**: Run the command `./b2 cxxflags=-std=c++17 install` to build boost with the standard library of choice and install it. If you encounter permission denied errors, use `sudo` before the command.

- **Step 12**: If your editor's autocomplete looks for environment variables for autocompletion and code completion, run:

```sh
export DYLD_LIBRARY_PATH=/path/to/boost/lib/:$DYLD_LIBRARY_PATH
```

- **Step 13**: Copy the following content:

```c++
#include <iostream>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

namespace mpi = boost::mpi;

int main() {
    mpi::environment env;
    mpi::communicator world;
    std::cout << "I am process " << world.rank() << " of " << world.size() << "." << std::endl;
    return 0;
}
```

```sh
OMPI_CXX=g++ mpic++ -I/Users/durwasa/boost/include -L/Users/durwasa/boost/lib helloworld.cpp -o helloworld -lboost_mpi
```

The `OMPI_CXX` sets the environment variable to `gcc` instead of `clang` (since `mpic++` has been installed using Homebrew/MacPorts). `-I` includes the header files, `-L` links the library, and `-lboost_mpi` links the boost.mpi, which we configured using our .jam file.

- **Step 14**: Run the command `OMPI_CXX=g++ mpirun helloworld`. If the default compiler in the system is `gcc`, omit the `OMPI_CXX` flag. `mpicxx` and other variants are technically compiler wrappers that translate the compiler commands and inject flags into it. Using the `OMPI_CXX` flag specifies which C++ compiler it should use while injecting the flags. Learn more about compiler wrappers [here](https://www.ibm.com/docs/en/smpi/10.2?topic=administering-compiling-applications).