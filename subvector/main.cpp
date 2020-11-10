#include <iostream>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;

struct subvector
{
  int* mas;
  uint top; //всегда указывет на последний полезный элемент;
  uint capacity;
};

bool init(subvector* qv) //инициализация пустого недовектора
{
  assert(qv != nullptr);
  qv->mas = nullptr;
  qv->top = 0;
  qv->capacity = 0;
  return true;
}

void expand(int** a, uint old, uint new_len)
{
  int* new_a = new int [new_len];

  for (int i = 0; i < old; i++)
    new_a[i] = (*a)[i];

  if (*a != nullptr)
    delete[] *a;

  *a = new_a;
}

bool push_back(subvector *qv, int d) //добав. элем. в конец недовектора с выдел. доп памяти при необх.
{
  assert(qv != nullptr);
  assert(qv->capacity >= qv->top);

  if (qv->capacity == qv->top) //если полезная часть равна длине недовектора
  {
    expand(&(qv->mas), qv->top, qv->capacity + 2); //то нам надо увеличить размер capacity
    qv->capacity += 2;
  }

  qv->mas[qv->top] = d;
  qv->top++;
  return true;
}

int pop_back(subvector *qv) //удаление элем. с конца недовектора
{
  assert(qv != nullptr);
  assert(qv->top > 0);

  qv->top--;
  return qv->mas[qv->top];
}

bool resize(subvector *qv, uint new_capacity) //увел емкость недовек.
{
  assert(qv != nullptr);
  if (new_capacity <= qv->capacity)
    return false;

  expand(&qv->mas, qv->capacity, new_capacity);
  qv->capacity = new_capacity;
  return true;
}

void shrink_to_fit(subvector *qv) //очистить неисп. память
{
  assert(qv != nullptr);
  assert(qv->top <= qv->capacity);

  if (qv->top == qv->capacity)
    return;

  expand(&qv->mas, qv->top, qv->top);
  qv->capacity = qv->top;
}

void clear(subvector *qv) //очистить содержимое недовект, занимаемое
{                         //место при этом не меняется
  assert(qv != nullptr);
  qv->top = 0;
}

void destructor(subvector *qv) //очистить всю исп. память, инициализировать
{                              //недовектор как пустой
  assert(qv != nullptr);
  if (qv->mas != nullptr)
  {
    delete [] qv->mas;
    qv->mas = nullptr;
  }

  qv->top = qv->capacity = 0;
}

//bool init_from_file(subvector *qv, char *filename); //инициализировать недовек. из файла, необязат задание


int main()
{
  int d = 9;
  subvector qv;
  init(&qv);

  for (int i = 0; i < 6; ++i)
    push_back(&qv, i);

  resize(&qv, 14);

  shrink_to_fit(&qv);

  clear(&qv);

  destructor(&qv);
  return 0;
}
