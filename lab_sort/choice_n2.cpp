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
  int min_mas_local = mas[0];
  int ind_local = 0;
  for (int iteration = 0; iteration < N - 1; iteration++)
  {
    for (int ind = iteration + 1; ind < N; ind++)
    {
      if (mas[ind] < min_mas_local)
      {
        min_mas_local = mas[ind];
        ind_local = ind;
      }
    }

    int wasted      = mas[iteration];
    mas[iteration]  = mas[ind_local];
    mas[ind_local]  = wasted;

    min_mas_local = mas[iteration + 1];
    ind_local = iteration + 1;
  }
  // ----------------------------------------------
  cout << "\n";
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
