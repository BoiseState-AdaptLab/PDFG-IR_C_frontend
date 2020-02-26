## POLYHEDRAL DATA FLOW GRAPH IR (PDFG IR) FRONT END COMPILER

Author: Tobi Goodness Popoola

# Features / Overview
A compiler that detects Static Control Parts (SCoPs) in a C program and generates Polyhedral DataFlow Graph IR.

1. Parses C program 
2. Generates the Iteration Domain component of Polyhedral DataFlow Graph IR.
3. Generates the Execution Schedule component of the Polyhedral DataFlow Graph IR.


### Documentation

Generate Documentation to see source manifest


```sh
OUTPUT_DIRECTORY       = @CMAKE_CURRENT_BINARY_DIR@/doc_doxygen/
INPUT                  = @CMAKE_CURRENT_SOURCE_DIR@/src/ @CMAKE_CURRENT_SOURCE_DIR@/docs
```
To specify the location for documentation edit OUTPUT_DIRECTORY in the docs/ folder.


### Dependencies
Clang/LLVM

Clang/LLVM: Clang installation is needed

Follow installation information [here](https://clang.llvm.org/get_started.html)





### Build / Install

Set llvm path variable


```sh
$ export /path/to/llvm/bin/directory:$PATH
```



```sh
$ git clone https://github.com/BoiseState-AdaptLab/PDFG-IR_C_frontend.git
$ mkdir build
$ cd build
```


```sh
$ cmake  -DBUILD_DOC=[ON|OFF] -DLLVM_BUILD=/path/to/llvm/build -DLLVM_SRC=path/to/llvm/src ../PDFG-IR_C_frontend

```

#### CMAKE options

BUILD\_DOC: ON|OFF builds documentation using deoxygen

LLVM\_BUILD: path to llvm build

LLVM\_SRC: path to LLVM source

### Usage

```sh
 $./build/bin/pdfg-c /test/c_file/path -- -std=c++11

```


### Publications Used 

[Strout, Michelle & Lamielle, Alan & Carter, Larry & Ferrante, Jeanne & Kreaseck, Barbara & Olschanowksy, Catherine. (2013). An Approach for Code Generation in the Sparse Polyhedral Framework. Parallel Computing. 53. 10.1016/j.parco.2016.02.004.] (https://www.researchgate.net/publication/259497067_An_Approach_for_Code_Generation_in_the_Sparse_Polyhedral_Framework) 


[ENABLING POLYHEDRAL OPTIMIZATIONS IN LLVM. Tobias Christian Grosser](https://polly.llvm.org/publications/grosser-diploma-thesis.pdf)
