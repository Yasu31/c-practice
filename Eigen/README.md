https://eigen.tuxfamily.org/dox/GettingStarted.html

# lvalues and rvalues
https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
# Fixed vs. Dynamic size
When should one use fixed sizes (e.g. Matrix4f), and when should one prefer dynamic sizes (e.g. MatrixXf)? The simple answer is: use fixed sizes for very small sizes where you can, and use dynamic sizes for larger sizes or where you have to. For small sizes, especially for sizes smaller than (roughly) 16, using fixed sizes is hugely beneficial to performance, as it allows Eigen to avoid dynamic memory allocation and to unroll loops. 

# A note about expression templates
This is an advanced topic that we explain on this page, but it is useful to just mention it now. In Eigen, arithmetic operators such as operator+ don't perform any computation by themselves, they just return an "expression object" describing the computation to be performed. The actual computation happens later, when the whole expression is evaluated, typically in operator=. While this might sound heavy, any modern optimizing compiler is able to optimize away that abstraction and the result is perfectly optimized code.
**Thus, you should not be afraid of using relatively large arithmetic expressions with Eigen: it only gives Eigen more opportunities for optimization.**