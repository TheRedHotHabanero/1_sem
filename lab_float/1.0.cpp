#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define SIZE 8 * sizeof(unsigned)

union fu
{
  float    f;
  unsigned u;
};

int main()
{
  /*unsigned int n = 0, ndouble;
  int len = 0;
  cin >> n;
  ndouble = n;
  unsigned mas[1000] = {0};
  int i = 0;

  while (ndouble > 0)
  {
    mas[i] = ndouble & 1;
    ndouble >>= 1;
    len += 1;
    i += 1;
  }
  unsigned mask = 1;

  fu newdv;
  for (int j = len - 1; j >= 0; j--)
  {
    unsigned number = mask & mas[j];
    newdv.u = newdv.u * 10 + number;
  }

  cout << endl << newdv.u;
  //cout << "\n" << newdv.f;
  return 0;*/

  fu num;
  cout << "ENTER NUM: ";
  cin >> num.f;

  unsigned mas[SIZE] = {};
  int len = 0;

  for (int i = 0; i < SIZE; ++i, ++len)
  {
    mas[i] = num.u & 1u;
    num.u >>= 1;
  }

  for (int i = len - 1; i >= 0; --i)
    cout << mas[i];

  cout << endl << "len: " << len << endl;

  return 0;
}


