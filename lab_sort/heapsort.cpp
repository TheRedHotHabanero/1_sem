#include <iostream>
using std::cout;
using std::cin;
using std::swap;
const int size = 10;

void heapify(int* arr, int n, int i)
{
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if ((l < n) && (arr[l] > arr[largest]))
    largest = l;

  if ((r < n) && (arr[r] > arr[largest]))
    largest = r;
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int* arr, int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n-1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{

  int arr[size] = {0};
  srand(time(nullptr));
  for (int i = 0; i < size; ++i)
  {
    arr[i] = rand() % 10000;
  }
  int n = sizeof(arr)/sizeof(arr[0]);

  heapsort(arr, n);

  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      cout << "WRONG";
  }
  return 0;
}