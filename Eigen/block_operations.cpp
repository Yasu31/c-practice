#include <Eigen/Dense>
#include <iostream>
 
using namespace std;
 
int main()
{
  Eigen::MatrixXf m(4,4);
  m <<  1, 2, 3, 4,
        5, 6, 7, 8,
        9,10,11,12,
       13,14,15,16;
  cout << "Block in the middle" << endl;
  cout << m.block<2,2>(1,1) << endl << endl; // constant-size version
  for (int i = 1; i <= 3; ++i)
  {
    cout << "Block of size " << i << "x" << i << endl;
    cout << m.block(0,0,i,i) << endl; // dynamic-size version
  }

  // blocks can also be used as lvalues (i.e. you can assign values to them)
  Eigen::Array22f a = Eigen::Array22f::Constant(0.1);
  cout << "a:\n" << a << endl;
  m.block<2,2>(1,1) = a;
  cout << "m:\n" << m << endl;

  // rows & columns and corner cases can be specified with special operators:
  cout << "third row of m:\n" << m.col(2) << endl;
  cout << "top left 2x2 of m:\n" << m.topLeftCorner(2,2) << endl;


  // in case of vectors...
  Eigen::VectorXd v(5);
  v << 0,1,2,3,4 ;
  cout << "v:\n" << v << endl;
  cout << "first 2 of v:\n" << v.head(2) << endl;
  v.tail(2); v.segment(1,2);
}