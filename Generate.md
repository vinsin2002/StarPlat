## Generate

### MacOS | MPI

#### Prerequisites for Running the StarPlat Library

Ensure the following before attempting to run the `StarPlat` library on your MacOS:

1. **Dependencies**: Confirm that all necessary dependencies, with particular attention to MPI, are properly installed.
2. **Directory Structure**: The directory structure should be as specified, with the `StarPlat` binary and required files located within the `/path/to/StarPlat/src` directory.

#### Execution Steps

1. **Navigate to the Source Directory**:
    Open a terminal and execute:
    ```bash
    cd /path/to/StarPlat/src
    ```

2. **Execute the Library**:
    Run the `StarPlat` library using the command below:
    ```bash
    ./StarPlat -s -f ../graphcode/staticDSLCodes/sssp_dslV2 -b mpi
    ```
    The command arguments are as follows:
    - `-s`: [This flag's description will be added here.]
    - `-f`: Designates the DSL file; for this example, it is `sssp_dslV2`.
    - `-b mpi`: Sets the backend to MPI.

3. **Verify the Output**:
    Check for a `.cc` file generated in the directory where the `StarPlat` binary is located after successful execution.

#### Troubleshooting

If you encounter issues, consider the following solutions:

- **Permission Denied**: If you get `bash: ./StarPlat: Permission denied`, change the executable permissions by running:
  ```bash
  chmod a+x StarPlat
  ```
- **Cannot Execute Binary File**: A `bash: ./StarPlat: cannot execute binary file` error might indicate an architecture mismatch. Confirm that the `Makefile` has the correct settings for your system architecture. Verify the compiler path with `which gcc`.
- **No Such File or Directory**: If `bash: ./StarPlat: No such file or directory` is displayed, check that the binary path is correct and all necessary files are in their proper locations.
- **Library Not Loaded**: Should you encounter an error like `dyld: Library not loaded: /path/to/library`, you need to ensure that all the dynamic libraries required by `StarPlat` are installed, or adjust the `DYLD_LIBRARY_PATH` environment variable to include the path where the libraries reside.
- **Unsupported Architecture**: If you're on Apple Silicon and encounter architecture-related issues, try using `arch -x86_64 ./StarPlat` to run the binary under Rosetta 2, or recompile the library for ARM architecture.