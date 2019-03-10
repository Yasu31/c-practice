# [template](https://en.wikipedia.org/wiki/Template_(C%2B%2B))
this is apparently a very strong concept...
## function templates
works like a function but its arguments can be many different types

``` cpp
template <typename T>
T max(T x, T y)
{
    if (x < y)
        return y;
    else
        return x;
}
```

## class templates
https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
see class_template.cpp

## template specialization
If we want to define a different implementation for a template when a specific type is passed as template parameter, we can declare a specialization of that template.
see template_specialization.cpp

``` cpp
template <class T> class myClass {};
template <> class myClass <char> {};
```
