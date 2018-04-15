# Qt

## what the hell is it
a cross-platform application framework that is used for developing application software that can be run on various software and hardware platforms with little or no change in the underlying codebase, while still being a native application with native capabilities and speed.

## [qmake manual](http://doc.qt.io/qt-5/qmake-manual.html)
>Projects are described by the contents of project (.pro) files. qmake uses the information within the files to generate Makefiles that contain all the commands that are needed to build each project. Project files typically contain a list of source and header files, general configuration information, and any application-specific details, such as a list of extra libraries to link against, or a list of extra include paths to use.

```qmake
SOURCES=main.c \
  first.c\
  second.c
HEADERS=first.h\
  second.h
```
generate Makefile with `qmake`, then `make all`

## variables
### DEFINES
defines a macro to be used by the preprocessor. (e.g. `gcc -D DEBUG main.c -o main`)

* [qmake variable reference](http://doc.qt.io/qt-5/qmake-variable-reference.html#qt)
