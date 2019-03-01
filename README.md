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
changing permissions
# gcc
the compiler. But it's better not to use it directly but use CMake, since the gcc commands can quickly get convoluted.

# header file
Has the declarations.

>A declaration introduces an identifier and describes its type, be it a type, object, or function. A declaration is what the compiler needs to accept references to that identifier. 

>A definition actually instantiates/implements this identifier. It's what the linker needs in order to link references to those entities.

# const, constexpr
https://qiita.com/saltheads/items/dd65935878a0901fe9e7

constexpr: 変数にconstexpr指定子をつけると、それは定数となりinline展開されてプログラムに埋め込まれる。constexpr変数の値はコンパイル時に決定されROM化可能な値である。その目的は、計算処理を実行時ではなくコンパイル時に移して、実行時のプログラムを高速化することにある。

「C++11以降では、コンパイル時定数をconstexpr修飾で定義できるので、constexpr修飾による定義を使用する」と解説され、ROMに配置できる定数は、#defineによるマクロも、const修飾も、すべて使用禁止になった。

# namespace
Namespaces provide a method for preventing name conflicts in large projects. 

https://qiita.com/_EnumHack/items/430da105a541f9ecd774
```cpp
namespace A
{
    void f(){std::cout << "A" << std::endl;};
    void hoge(){
        f(); // 名前空間の中では修飾しなくても呼び出せる
    }
}

namespace B
{
    void f(){std::cout << "B" << std::endl;};
    void hoge(){
        A::f(); // 別の名前空間から呼びたいなら修飾する
    }
}

int main()
{
    A::f(); // A
    B::f(); // B
    A::hoge(); // A
    B::hoge(); // A
}
```

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
``` cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack { 
   private: 
      vector<T> elems;    // elements 

   public: 
      void push(T const&);  // push element 
      void pop();               // pop element 
      T top() const;            // return top element 
      
      bool empty() const {      // return true if empty.
         return elems.empty(); 
      } 
}; 

template <class T>
void Stack<T>::push (T const& elem) { 
   // append copy of passed element 
   elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::pop(): empty stack"); 
   }
   
   // remove last element 
   elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::top(): empty stack"); 
   }
   
   // return copy of last element 
   return elems.back();      
} 

int main() { 
   try {
      Stack<int>         intStack;  // stack of ints 
      Stack<string> stringStack;    // stack of strings 

      // manipulate int stack 
      intStack.push(7); 
      cout << intStack.top() <<endl; 

      // manipulate string stack 
      stringStack.push("hello"); 
      cout << stringStack.top() << std::endl; 
      stringStack.pop(); 
      stringStack.pop(); 
   } catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 
} 
```

# vectors, arrays
std::vector::data(), std::array::data()- returns pointer to first element of std::vector / std::array
```cpp
// this type of array is not used much, since it has problems such as not knowing how long itself is.
int a[MAX_LEN] = {};
int b[MAX_LEN];

std::vector<int> a(MAX_LEN);
td::vector<int> b;
b.push_back(1);

// with arrays, initial length must be decided first
std::array<int, MAX_LEN> c;

```

# serialization
serialization (or serialisation) is the process of translating data structures or object state into a format that can be stored (for example, in a file or memory buffer) or transmitted (for example, across a network connection link) and reconstructed later (possibly in a different computer environment).

[with ROS](http://wiki.ros.org/roscpp/Overview/MessagesSerializationAndAdaptingTypes),
```cpp
namespace ser = ros::serialization;

std_msgs::UInt32 my_value;
my_value.data = 5;

uint32_t serial_size = ros::serialization::serializationLength(my_value);
boost::shared_array<uint8_t> buffer(new uint8_t[serial_size]);
// get() returns a pointer to the array
ser::OStream stream(buffer.get(), serial_size);
ser::serialize(stream, my_value);
```
only the fields of messages are serialized (and not constants), and in the order defined in the .msg file.

# ostream
http://stlalv.la.coocan.jp/Stream.html

Output stream. Can output to console, file, etc... versatile!

# pure virtual functions
```cpp
class Device{
public:
	virtual int charge() = 0;
}

class iPhone: public Device{
public:
	int charge(){
		connectLightning();
		return 1;
	}
}

class Android: public Device{
public:
	int charge(){
		connectMicroUSB();
		return 1;
	}
}
```

This means that charge() is a *pure virtual function*; A class that has even a single pure virtual function is an *abstract class*. Instances of abstract classes cannot be created; it is supposed to be used as a template for its child classes.

# virtual base class
* [VIrtual Inheritance](https://en.wikipedia.org/wiki/Virtual_inheritance)-Wiki

``` cpp
class A { public: void Foo() {} };
class B : public A {};
class C : public A {};
class D : public B, public C {};
```
results in the "dreaded diamond"
``` 
  A
 / \
B   C
 \ /
  D
```
when `D d; d.Foo();` is called is `d.Foo()` B's Foo or C's Foo?

This can be avoided by converting, such as `static_cast<B&>(d).Foo()` or `d.B::Foo()`

``` cpp
struct Animal {
  virtual ~Animal() { }
  virtual void eat(){}
};

// Two classes virtually inheriting Animal:
struct Mammal : virtual Animal {
  virtual void breathe(){}
};

struct WingedAnimal : virtual Animal {
  virtual void flap(){}
};

// A bat is still a winged mammal
struct Bat : Mammal, WingedAnimal {
};
```
> The Animal portion of Bat::WingedAnimal is now the same Animal instance as the one used by Bat::Mammal, which is to say that a Bat has only one, shared, Animal instance in its representation and so a call to Bat::eat() is unambiguous.

# Smart Pointers
why not take pointers, an already weird concept, and make that even more convoluted and confusing by making it "smart"??

[C++11スマートポインタ入門](https://qiita.com/hmito/items/db3b14917120b285112f)
Smart pointer: concept of "ownership"- self-releases memory when the memory that it owns is no longer required (uses destructor)

## unique_ptr

## shared_ptr
>shared_ptr\<T\>は、所有権を持つポインタの数を記録するカウンタを持っている。所有権を持つ shared_ptr\<T\>がコピーされると、内部でカウンタがインクリメントされ、ディストラクタや明示的解放時にデクリメントされる。全ての所有者がいなくなると、カウンタがゼロとなり、メモリが開放される。カウンタで所有者数を管理することで、複数の shared_ptr\<T\>が所有権を保持していても、適切なタイミングで一度だけメモリ解放が実行されるのである。

``` cpp


#include<memory>
#include<iostream>
int main(){
   //空のshared_ptrを作成
   std::shared_ptr<int> ptr;

   {
      //intの所有権を持つ、ptr2を作成
      std::shared_ptr<int> ptr2(new int(0));

      //ptr2の所有権をptrにコピー、共有する
      ptr=ptr2;

      *ptr+=10;
      *ptr2+=10;

   }//ここで、ptr2のディストラクタが呼ばれる
    //ptrも同一のメモリに対する所有権を持っているため、まだ解放はされない

   //当然、ptrはまだ使用可能
   std::cout<<"ptr="<<*ptr<<std::endl;  //"ptr=20"と出力

}//ここで、ptrのディストラクタが呼ばれる
 //メモリの所有権を持つポインタがいなくなったので、解放される

```

# ROS parameter server

# [ROS message](http://wiki.ros.org/msg)
consist of fields and constants. `rosmsg list` shows currently available message types.

# [ROS concepts](http://wiki.ros.org/ROS/Concepts)

## [catkin concepts](http://wiki.ros.org/catkin/conceptual_overview)
[ROSの新しいビルドシステムcatkinについて](https://myenigma.hatenablog.com/entry/20131229/1388320084)


## [catkin/CMakeLists.txt](http://wiki.ros.org/catkin/CMakeLists.txt)
The CMakeLists.txt file used for a catkin project is a standard vanilla CMakeLists.txt file with a few additional constraints. 
Your CMakeLists.txt file MUST follow this format otherwise your packages will not build correctly. The order in the configuration DOES count.

1. Required CMake Version (cmake_minimum_required)
1. Package Name (project())
1. Find other CMake/Catkin packages needed for build (find_package())
1. Enable Python module support (catkin_python_setup())
1. Message/Service/Action Generators (add_message_files(), add_service_files(), add_action_files())
1. Invoke message/service/action generation (generate_messages())
1. Specify package build info export (catkin_package())
1. Libraries/Executables to build (add_library()/add_executable()/target_link_libraries())
1. Tests to build (catkin_add_gtest())
1. Install rules (install()) 

If a package is found by CMake through find_package, it results in the creation of several CMake environment variables that give information about the found package. These environment variables can be utilized later in the CMake script. The environment variables describe where the packages exported header files are, where source files are, what libraries the package depends on, and the paths of those libraries. The names always follow the convention of \<PACKAGE NAME\>_\<PROPERTY\>:

*    \<NAME\>_FOUND - Set to true if the library is found, otherwise false
*    \<NAME\>_INCLUDE_DIRS or \<NAME\>_INCLUDES - The include paths exported by the package
*    \<NAME\>_LIBRARIES or \<NAME\>_LIBS - The libraries exported by the package
*    \<NAME\>_DEFINITIONS - ? 

## tf
* [世界で一番簡単なtfの使い方](https://myenigma.hatenablog.com/entry/20130210/1360491625)- myenigma

# what's up with the ampersand & in function parameters?
## what does an & even mean??
https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in/57492#57492

https://qiita.com/agate-pris/items/05948b7d33f3e88b8967

A pointer can be re-assigned:
```cpp
int x = 5;
int y = 6;
int *p;
p =  &x;
p = &y;
*p = 10;
assert(x == 5);
assert(y == 10);
```
A reference cannot, and must be assigned at initialization:
```cpp
int x = 5;
int y = 6;
int &r = x;
int& l = x; // same thing
```

reference shares the same memory address as the value that was assigned at initialization.

明示的な理由が無い限り組み込み型以外では値渡しを使用すべきではない.

```cpp
#include <iostream>
bool twice( int* a )
{
    if( a == nullptr )
    {
        std::cout << "null" << std::endl;
        return true;
    }
    std::cout << *a << std::endl;
    *a *= 2;
    std::cout << *a << std::endl;
    return false;
}
int main()
{
    twice( nullptr );
    int v = 16;
    std::cout << v << std::endl;
    twice( &v );
    std::cout << v << std::endl;
}
```
outputs
```
null
16
16
32
32
```

passing by reference is new in C++, and apparently the ampersand has nothing much to do with converting variables to pointers, because C++ is a very concise and logical language???
```cpp
#include <iostream>
void twice( int& a )
{
    std::cout << a << std::endl;
    a *= 2;
    std::cout << a << std::endl;
}
int main()
{
    int v = 16;
    std::cout << v << std::endl;
    twice( v );
    std::cout << v << std::endl;
}
```
outputs
```
16
16
32
32
```

# boost::bind()
https://www.boost.org/doc/libs/1_66_0/libs/bind/doc/html/bind.html
> boost::bind is a generalization of the standard functions std::bind1st and std::bind2nd.
ok....???

``` cp
int f(int a, int b)
{
    return a + b;
}

int g(int a, int b, int c)
{
    return a + b + c;
}
```
`bind(f, 1, 2)` will return a *function object* that returns f(1,2) and takes no arguments. `bind(f, _1, 5)` will return a function object that takes one argument- `bind(f, _1, 5)(x)` is `f(x, 5)`.

# boost::function


# c++ struct vs class
basically the same except that the default accessibility is **private** for class, and **public** for structs.

then why the fuck do you keep them both in the language, just pick one name and be done with it you idiots

## what is it when you call a class without instance???

