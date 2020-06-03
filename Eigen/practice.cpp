#include <iostream>
#include <Eigen/Dense>
 

typedef Eigen::Matrix<double, 5, 5> MatrixCustomd;
 
int main()
{
  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

  MatrixCustomd mc;
  std::cout << "coefficients not initialized\n" << mc << std::endl;
  mc.setZero();
  std::cout << "after initializing to 0:\n" << mc << std::endl;

  Eigen::MatrixXd ms(4,4);
  ms.setZero();
  std::cout << "ms:\n" << ms << std::endl;

  Eigen::Matrix2i a; a << 1, 2, 3, 4;
  std::cout << "Here is the matrix a:\n" << a << std::endl;
  // a = a.transpose(); // !!! do NOT do this !!! (will produce error)
  // std::cout << "and the result of the aliasing effect:\n" << a << std::endl;

  a.transposeInPlace();
  std::cout << "a:\n" << a << std::endl;

}
