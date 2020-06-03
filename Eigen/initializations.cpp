#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

int main()
{
  cout << "A fixed-size array:\n";
  Array33f a1 = Array33f::Zero();
  cout << a1 << "\n\n";

  cout << "A one-dimensional dynamic-size array:\n";
  ArrayXf a2 = ArrayXf::Zero(3);
  cout << a2 << "\n\n";

  cout << "A two-dimensional dynamic-size array:\n";
  ArrayXXf a3 = ArrayXXf::Zero(3, 4);
  cout << a3 << "\n";

  MatrixXd m = MatrixXd::Constant(3,3,3.14);
  cout << "set all to constant value\n" << m << endl;
  cout << "set to identity\n" << m.setIdentity() << endl;
}