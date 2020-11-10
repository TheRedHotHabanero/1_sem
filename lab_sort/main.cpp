#include <iostream>
#include <cstdlib>
#include <ctime>

#include "n_2.h"

using std::cin;
using std::cout;
using std::endl;

void arr_filler(int* arr, int size)
{
  srand(time(nullptr));
  for (int i = 0; i < size; ++i)
    arr[i] = rand() % 10000;
}

bool check_up(int* arr, int size)
{
  for (int i = 0; i < size - 1; i++)
    if (arr[i] > arr[i + 1])
      return false;

  return true;
}

const int N = 10;

int main()
{
  int mas[N] = {0};

  arr_filler(mas, N);

  for (int i = 0; i < N; ++i)
    cout << mas[i] << " ";
  cout << endl;
  //-----------------------------------------------------

  bubble(mas, N);

  // ----------------------------------------------------
  for (int x = 0; x < N; ++x)
    cout << mas[x] << " ";
  cout << endl;

  if (check_up(mas, N))
    cout << "ALL RIGHT, BOIIII\n";
  else
    cout << "SORRY, U R WRONG(\n";

  return 0;
}
