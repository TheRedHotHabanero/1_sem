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
  int wasted;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N - 1; ++j)
    {
      int compare = mas[j] > mas[j + 1];
      if (compare == 1)           //   >>> up
      {
        wasted      = mas[j];
        mas[j]      = mas[j + 1];
        mas[j + 1]  = wasted;
      }
    }
  }
  //------------------------------------------------------
  cout << "\n";
  for (int x = 0; x < N; ++x)
  {
    cout << mas[x] << " ";
  }
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
  //-----------------
  return 0;
}