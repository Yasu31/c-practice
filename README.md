# c-practice
playground for learning the intricacies I've previously avoided of the C(and C++) language.

Somewhat based on the book [**Advanced C and C++ Compiling**](https://doc.lagout.org/programmation/C/Advanced%20C%20and%20C%20%20%20Compiling%20%5BStevanovic%202014-04-28%5D.pdf) by Milan Stevanovic

The directories that begin with numbers indicate the chapters in the book. They contain program samples from the book, and also some more stuff I found relevant.

# Commenting
## comments for classes in C++
in header file or in code??

>>My view...
Document how to use the function in the header file, or more accurately close to the declaration.
Document how the function works (if it's not obvious from the code) in the source file, or more accurately, close to the definition.
For the birds-eye thing in the header, you don't necessarily need the documentation that close - you can document groups of declarations at once.
Broadly speaking, the caller should be interested in errors and exceptions (if only so they can be translated as they propogate through the layers of abstraction) so these should be documented close to the relevant declarations.

# environment for C++
use combination of linter-cpplint and atom-beautify(with the clang-format beautifier) on Atom to write nicely

# classes in C++
## initializing a member variable later
use pointers and stuff
```cpp
class MyClass{
  MyClass();
  CommandListener* commandListener;
};
MyClass::MyClass(){
  commandListener = new CommandListener(???);
  commandListener->start()
}
```

# what's the deal with `chmod`??
`$ chmod +x ????`

# gcc

# header file
