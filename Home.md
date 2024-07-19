<h1 align="center">StarPlat</h1>
<p align="center">A Versatile DSL for Graph Analytics</p>


### What is StarPlat?

StarPlat is a graph DSL that simplifies parallelizing graph algorithms across different architectures. It generates code for OpenMP, MPI, and CUDA from the exact high-level algorithmic specification, offering a solution to the challenge of parallel programming complexity. With its focus on abstraction, it enables domain experts to concentrate on algorithm design, effectively tackling various graph algorithms. The DSL's constructs, including `forAll` and `fixed-point`, facilitate parallelization and iterative procedures, easing the implementation of algorithms. Additionally, StarPlat supports data types like `Graph`, `node`, `edge`, and `properties`. Its code generator optimizes code for shared memory, distributed, and many-core platforms, handling graph representation and storage. By streamlining the complexities of parallelization, StarPlat enables domain experts to implement and optimize graph algorithms for diverse architectures efficiently.

### Installation Requirements

#### Installation and Usage Instruction for linux/WSL

##### Make sure you have build-essential (latest), bison 3.8.2, gcc 11, g++ 11, flex 2.6.4, libomp-dev
 Use the following command in the debian terminal to install all the required tools
 ``` sudo apt install build-essential gcc g++ bison flex libomp-dev ```

### Quickstart Guide

#### Making the StarPlat src

Get to the src folder of the repository and run the following command in the terminal
``` make ```

#### Compiling the DSL Codes
To Compile the dsl codes to generate OMP specific code use the following command in the terminal
```
./StarPlat [-s|-d] -f <dsl.sp> -b [cuda|omp|mpi|acc|sycl]

#Example
./StarPlat -s -f ../graphcode/staticDSLCodes/triangle_counting_dsl -b omp

-s for static and -d for dynamic
-b select the type of backend
-f the dsl file to input
```
>Once the omp code is generated it would be reflected in generated_omp folder of the graphcode directory in the repository

#### Running the OMP code

In the graphcode folder there is a main.cpp file, edit out the dsl file name in the header and modify path for the loading different graphs and then compile and run using g++.
```  
export OMP_NUM_THREADS=16
g++ main.cpp -o main -fopenmp 
./main
```

### Wiki Guidelines

Notice that cloning this Wiki would point all the URLs to `/durwasa-chakraborty/StarPlat` which is a forked repository of the original `ashwina` Starplat. In order to point to the Username one run the following command - 

``` bash
inserted_string="YOUR_NEW_USERNAME" # replace with your desired string
git clone https://github.com/durwasa-chakraborty/StarPlat/wiki
cd /path/to/clone
find . -name "*.md" -exec sed -i '' \
"s|https://github.com/durwasa-chakraborty/StarPlat/wiki/|\
https://github.com/$inserted_string/StarPlat/wiki/|g" {} +

```

Thank you for contributing to our wiki! To ensure uniformity and readability across our documentation, please adhere to the following guidelines when creating or editing content:

**Page Titles**
- Every page should begin with a primary title using `h2` or preceded by `##`.

  **Example:** 
  ```
  ## Introduction to Parallel Programming
  ```
**Operating System or Architecture Subsections**
- When mentioning a specific OS or architecture, pair it with the type of parallelization framework.
- Use `h4` or precede with `####` for these subsections.

  **Example:** 
  ```
  #### Windows | OpenMP
  ```
**File Names**
- Whenever referring to a file name, wrap the name with single backticks.

  **Example:** 
  ```
  Open the `README.md` file for more instructions.
  ```
**Code Snippets**
- For code snippets or command examples, always enclose them with three backticks. If possible, specify the programming language immediately after the first three backticks for syntax highlighting.

  **Example:** 
```markdown
  ```python
  def hello_world():
      print("Hello, world!")
  ```


