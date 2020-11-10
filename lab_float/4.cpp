#include <iostream>
#include <cassert>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
using std::fixed;

unsigned long long fact( unsigned n )
{
  unsigned long long res = 1;
  for (unsigned i = 1; i <= n; ++i)
    res = res * i;

  return res;
}

float bayley( unsigned n )
{
  float pi = 0;
  for (unsigned i = 0; i < n; ++i)
    pi += (
            4 / (8 * (float)i + 1)
           -2 / (8 * (float)i + 4)
           -1 / (8 * (float)i + 5)
           -1 / (8 * (float)i + 6)
          ) / powf(16, i);

  return pi;
}

float bellard( unsigned n )
{
  float pi_x_64 = 0;
  for (unsigned i = 0; i < n; ++i)
  {
    pi_x_64 += powf(-1, i) *
              (
                - 32  / (4  * (float)i + 1)
                - 1   / (4  * (float)i + 3)
                + 256 / (10 * (float)i + 1)
                - 64  / (10 * (float)i + 3)
                - 4   / (10 * (float)i + 5)
                - 4   / (10 * (float)i + 7)
                + 1   / (10 * (float)i + 9)
              ) / pow(2, 10*i);
  }
  return pi_x_64 / 64;
}

float chud( unsigned n )
{
  float anti_pi;
  for (unsigned i = 0; i < n; ++i)
    anti_pi += pow(-1, i) * (float)fact(6*i) * (13591409 + 545140134 * i)
               / ( (float)fact(3 * i) * powf((float)fact(i), 3) * powf(640320, 3.0 * i + 3.0/2));
  anti_pi *= 12;
  return 1 / anti_pi;
}

int main( )
{
  FILE * out = fopen("lab4.csv", "w");

  fprintf(out, "Bayley\n");

  for (unsigned i = 0; i < 20; i += 1)
    fprintf(out, "%u %.25f\n", i, bayley(i));

  fprintf(out, "Bellard\n");
  for (unsigned i = 0; i < 20; i += 1)
    fprintf(out, "%u %.25f\n", i, bellard(i));

  fprintf(out, "Chudo\n");
  for (unsigned i = 0; i < 20; i += 1)
    fprintf(out, "%u %.25f\n", i, chud(i));

  fclose(out);

  return 0;
}