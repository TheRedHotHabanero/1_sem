#include <iostream>

#include <cstdlib>
#include <cstring>
#include <chrono>

#include "n_2.h"
#include "nlogn.h"

using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono;

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

void print(int* arr, int size)
{
  for (int i = 0; i < size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

const int N = 10;

int main()
{
  cout << "name arr_len time(microsec)\n";
  for (int i = 10; i <= 10000; i *= 10)
  {
    int arr_orig[i];
    arr_filler(arr_orig, i);

    int arr1[i], arr2[i], arr3[i],
        arr4[i], arr5[i], arr6[i];
    
    size_t size = i * sizeof(int) / sizeof(char);
    
    memcpy(arr1, arr_orig, size);
    memcpy(arr2, arr_orig, size);
    memcpy(arr3, arr_orig, size);
    memcpy(arr4, arr_orig, size);
    memcpy(arr5, arr_orig, size);
    memcpy(arr6, arr_orig, size);
    
    
    auto begin = high_resolution_clock::now();
    bubble(arr1, i);
    auto end = high_resolution_clock::now();

    cout << "bubble " << i << " " << duration_cast<microseconds>(end - begin).count() << "\n";

    begin = high_resolution_clock::now();
    choice(arr2, i);
    end = high_resolution_clock::now();

    cout << "choice " << i << " " << duration_cast<microseconds>(end - begin).count() << "\n";

    begin = high_resolution_clock::now();
    insert(arr3, i);
    end = high_resolution_clock::now();

    cout << "insert " << i << " " << duration_cast<microseconds>(end - begin).count() << "\n";

    // new sorts

    cout << endl;
  }
  // ----------------------------------------------------
  /*if (check_up(arr, N))
    cout << "ALL RIGHT, BOIIII\n";
  else
    cout << "SORRY, U R WRONG(\n";*/

  return 0;
}
