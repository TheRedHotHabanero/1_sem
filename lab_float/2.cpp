#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

int main( )
{
  cout << fixed;
  cout.precision(2);

  float num = 1.0;

  for (int i = 0; i < 20; ++i)
  {
    num *= 10;
    cout << num << endl;
  }

  return 0;
}