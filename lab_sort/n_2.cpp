#include "n_2.h"

void bubble(int* arr, int size)
{
  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size - 1; ++j)
      if (arr[j] > arr[j + 1])           //   >>> up
      {
        int wasted = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1]  = wasted;
      }
}

void choice(int* arr, int size)
{
  int min_arr_local = arr[0];
  int ind_local = 0;
  for (int iteration = 0; iteration < size - 1; iteration++)
  {
    for (int ind = iteration + 1; ind < size; ind++)
      if (arr[ind] < min_arr_local)
      {
        min_arr_local = arr[ind];
        ind_local = ind;
      }

    int wasted = arr[iteration];
    arr[iteration] = arr[ind_local];
    arr[ind_local] = wasted;

    min_arr_local = arr[iteration + 1];
    ind_local = iteration + 1;
  }
}

void insert(int* arr, int size)
{
  for (int x = 0; x < size; x++)
    for (int y = 0; y < x ; y++)
      if (arr[x] <= arr[y])
      {
        int wasted = arr[y]; //up sort ->
        arr[y] = arr[x];
        arr[x] = wasted;
      }
}