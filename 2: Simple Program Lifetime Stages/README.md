# basics

## Demo Project, p.10
* The input(the text file with source code) to the compiler is the "translation unit"
* the output isa collection of binary "object files"
* must be then "linked", to be executable as a program

### contents
#### function.h
.h is a [header file](https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html). It contains C declarations and macro definitions to be shared between several source files.
#### function.c
contains functions that will be called from main.c
#### main.c
## Steps required to run the program
### 1. preprocessing
To only do preprocessing, `$ gcc -E function.c -o function.i`

### 2. linguistic analysis
1. lexical analysis: breaks down source code into non-divisible tokens
1. Parsing/syntax analysis: checks that the order of tokens makes sense from programming language rules.
1. Semantic analysis: checks if it actually makes sense (doesn't add two ints to make a float, etc.)

### 3. assembling
Once there are no syntax errors, goes in to assembling. Can be done by `$ gcc -S function.c -o function.s`

The generated file is the assembler instructions

### 4. optimization

### 5. Code emission
Creates **object files**, one for each translation unit. The assembly instructions are converted into binary values of corresponding machine instructions. To do so, `$ gcc -c function.c -o function.o`

To see the contents of the object file, `$ objdump -D function.o`

These object files are tiled together into the program "memory map" to make an executable file. There, the address range of each object file is considered.

The information stored in object files follow rules that vary across platforms (for Linux, Executable and Linkable Format (ELF), on Windows, PE/COFF format)

object file can be separated into **symbols**(references to memory addresses in program or data memory) and **sections**(such as code, initialized data, debugging information etc.)

### 6. linking
tile each individual sections of each object file into body of program memory map.
To do this step by step, first compile each source file:
```
$ gcc -c function.c main.c
```
This produces function.o and main.o.
Then, link both of them into output executable:
```
$ gcc function.o main.o -o demoApp
```
To do at once, `$ gcc function.c main.c -o demoApp`
## executable file properties, p.37
the modern startup routine is **crt1**

### various section types
Can be seen at http://man7.org/linux/man-pages/man5/elf.5.html
### various symbol types
provides a very wide variety of symbol types. One way to distinguish them is if they have local scope or broader access.(upper caps indicate wide scope, small caps indicate local) Other factors include if the symbol's value is absolute, if a symbol is in the text(code) section, etc.
