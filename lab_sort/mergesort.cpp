#include <iostream>
using std::cout;
using std::cin;
using std::swap;
const int sizearr = 10;

void merge(int* arr, int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0;
  int j = 0;
  int k = l;

  while ((i < n1) && (j < n2))
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int* arr, int l, int r)
{
  if (l < r)
  {
    int m = (l + r - 1) / 2;

    mergeSort (arr, l, m);
    mergeSort (arr, m + 1, r);
    merge     (arr, l, m, r);
  }
}


int main()
{
  int arr[sizearr] = {0};

  srand(time(nullptr));
  for (int i = 0; i < sizearr; ++i)
  {
    arr[i] = rand() % 10000;
  }
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr, 0, arr_size - 1);

  for (int i = 0; i < sizearr - 1; i++)
  {
    //cout << "I am here";
    if (arr[i] > arr[i + 1])
    {
      cout << "WRONG";
    }
  }
  return 0;
}

