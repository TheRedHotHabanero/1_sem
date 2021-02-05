#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::swap;
using std::make_heap;
using std::sort_heap;
const int size = 10;

void swapValue(int* a, int* b)
{
  int* temp = a;
  a = b;
  b = temp;
}

void InsertionSort(int* arr, int* begin, int* end)
{
  int left = begin - arr;
  int right = end - arr;

  for (int i = left+1; i <= right; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= left && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int* Partition(int* arr, int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (arr + i + 1);
}

int *MedianOfThree(int* a, int* b, int* c)
{
  if ((*a < *b) && (*b < *c) || (*c <= *b) && (*b <= *a))
    return (b);

  if ((*a < *c) && (*c <= *b) || (*b < *c) && (*c <= *a))
    return (c);

  if ((*b <= *a) && (*a < *c) || (*c <= *a) && (*a < *b))
    return (a);
}

void IntrosortUtil(int* arr, int* begin, int* end, int depthLimit)
{
  int size = end - begin;

  if (size < 16)
  {
    InsertionSort(arr, begin, end);
    return;
  }

  if (depthLimit == 0)
  {
    make_heap(begin, end+1);
    sort_heap(begin, end+1);
    return;
  }
  int* pivot = MedianOfThree(begin, begin + size / 2, end);
  swapValue(pivot, end);

//Quick Sort
  int* partitionPoint = Partition(arr, begin - arr, end - arr);
  IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
  IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
}

void Introsort(int* arr, int* begin, int* end)
{
  int depthLimit = 2 * log(end - begin);
  IntrosortUtil(arr, begin, end, depthLimit);
}

int main()
{
  int arr[size] = {0};
  srand(time(nullptr));
  for (int i = 0; i < size; ++i)
  {
    arr[i] = rand() % 10000;
  }

  int n = sizeof(arr) / sizeof(arr[0]);
  Introsort(arr, arr, arr + n - 1);
  for (int i = 0; i < size - 1; i++)
  {
    //cout << "I am here";
    if (arr[i] > arr[i + 1])
    {
      cout << "WRONG";
    }
  }

  return(0);
}
