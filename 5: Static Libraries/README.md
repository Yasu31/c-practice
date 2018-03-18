# Static libraries
Static libraries are mostly taken over by dynamic libraries, but it's sometimes still useful

the archiver tool **ar** is available when creating static libraries from object files
```
$ gcc -c first.c second.c
// compile into object files first.o and second.o
$ ar rcs libstaticlib.a first.o second.o
```
Linux naming convention is that static libraries are named like "lib???.a"

To use the static library, load the header files for it in program, like in main.c
```c
#include "first.h"
#include "second.h"

int main(){
  hello_world_first(5);
  hello_world_second(5);
  return 1;
}
```
Compile into object file `$ gcc -c main.c`, then link it:
```
$ gcc main.c -o main -L. libstaticlib.a
```
This creates an executable that can be run with `./main`, linking the static library (which is in the same directory, as indicated by `-L.`) libstaticlib.a.

* [Static and Dynamic Libraries | Set 1](https://www.geeksforgeeks.org/static-vs-dynamic-libraries/)
