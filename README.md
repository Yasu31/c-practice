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

# template

# vectors, arrays
std::vector::data(), std::array::data()- returns pointer to first element of std::vector / std::array
```cpp
// this type of array is not used much, since it has problems such as not knowing how long itself is.
int a[MAX_LEN] = {};
int b[MAX_LEN];

std::vector<int> a(MAX_LEN);
std::vector<int> b;
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

ser::OStream stream(buffer.get(), serial_size);
ser::serialize(stream, my_value);
```

# ostream
http://stlalv.la.coocan.jp/Stream.html

Output stream.

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

# shared_ptr

# ROS parameter server

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
