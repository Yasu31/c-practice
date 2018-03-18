# The Impact of Reusing Concept

# Static Libraries
a collection of object files. It ca easily be dismantled into separate object files from which the static library was created.

# Dynamic Libraries
shares unique system resources. but just the code(.text) section and not the data section.

* Load Time Relocation: each application does not have to store library binary, but must load their own copy of the library each time...(when library is loaded, it becomes configured to that app's memory layout)
* Position Independent Code: only one copy of the code is loaded, no matter how many applications use it. Dynamic libraries that use this concept is called **shared libraries**
