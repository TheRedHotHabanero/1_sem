#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;

const int N = 10;

int main()
{
  int mas[N] = {0};
  srand(time(NULL));
  for (int random_num = 0; random_num < N; ++random_num)
  {
    mas[random_num] = rand() % 10000;
    //cout << mas[random_num] << " ";
  }

  //-----------------------------------------------------
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < x ; y++)
    {
      if (mas[x] <= mas[y])
      {
        int wasted = mas[y]; //up sort ->
        mas[y] = mas[x];
        mas[x] = wasted;
      }
    }
  }

  // ----------------------------------------------------
  for (int x = 0; x < N; ++x)
  {
    cout << mas[x] << " ";
  }
  //==========================================================
  //----СHECK--------------------------------------------------
  for (int prov = 0; prov < N - 1; prov++)
  {
    int compare = mas[prov] < mas[prov + 1];
    if (compare == 0)
    {
      cout <<"\n" << "WRONG";
      return 0;
    }
  }
  //===========================================================
  return 0;
}

