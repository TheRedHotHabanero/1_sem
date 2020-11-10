#include <iostream>
using namespace std;

int main()
{
  union fu {
    float    f;
    unsigned u;
  };

  unsigned int n = 0, ndouble;
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

  cout << "\n" << newdv.u;
  //cout << "\n" << newdv.f;
  return 0;
}
