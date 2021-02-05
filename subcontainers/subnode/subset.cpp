#include <iostream>
#include <cassert>
using std::cin;
using std::cout;
using std::max;

struct subset_node
{
  int key;
  subset_node* left;
  subset_node* right;
  subset_node* parent;
};

bool init(subset_node** sn) //инициализация пустого дерева
{
  assert(sn != nullptr);
  *sn = nullptr;

  return true;
}

bool insert(subset_node** sn, int k, subset_node* parent = nullptr) //добавление элемента в дерево
{
  if ((*sn) == nullptr)
  {
    *sn = new subset_node; //теперь тут не пустой узел, а наманый такой, закинули адрес на него
    (*sn)->key = k; //запихнули значение узла
    (*sn)->left = nullptr; //говорим, что в новом созданном узле слева нул
    (*sn)->right = nullptr; //и справа тоже нулл
    (*sn)->parent = parent;
    return true;
  }

  if (k < (*sn)->key) //если новое значение меньше значения нынешнего узла, то
    return insert(&((*sn)->left), k, *sn); //спускаемся на узел ниже и вызываем от него инсерт, тут от левого;
  else if (k > (*sn)->key)
    return insert(&((*sn)->right), k, *sn); //если не от левого, то значит от правого вызовем, фигли нам

  return false;
}

subset_node* find(subset_node* sn, int k) //поиск элемента в дереве
{
  if (sn == nullptr)
    return nullptr;

  if ((*sn).key == k) //если совпал ключ и искомая фигня, сразу делаем возврат указателя
    return sn;
  if ((*sn).key < k) //если наш ключ меньше искомого, прыгаем вправо, потому что там больше
    return find((*sn).right, k);
  else
    return find((*sn).left, k); //а если сюда дошло, то значит влево прыгаем
}

bool remove(subset_node** sn, int k) //удаление элемента из дерева, подвешивание оставшейся части наверх
{
  assert(sn != nullptr);

  subset_node* node = find(*sn, k); //схавали укзатель на элемент, который надо выкинуть
  if (node == nullptr)
    return false;

  //if (node->right == nullptr && node->parent != nullptr)



}

uint size(subset_node* sn) //количество элементов в дереве
{
  if (sn == nullptr)
    return 0;

  return (1 + size(sn->right) + size(sn->left)); //сумма по ветке справа, слева и еще сам элемент
}

uint height(subset_node* sn) //высота дерева
{
  if (sn == nullptr)
    return 0;

  return (1 + max(size(sn->right), size(sn->left)));
}

/*
void destructor(subset_node* sn) //очистить всю используемую память
{
взять эелементы сзади наперед из разложения обхода в глубину, поиском и и ремувом постирать
}
*/

void help(subset_node* sn, int* arr, int i)
{
  if (sn == nullptr)
    return;
  help(sn->left, arr, i);
  arr[i] = sn->key;
  ++i;
  help(sn->right, arr, i);
}

int* DFS(subset_node* sn)
{
  size_t size_arr = size(sn);
  int* arr = new int [size_arr];

  int i = 0;
  help(sn, arr, i);
  return arr;
}

/*
int* BFS(subset_node* sn) //обход в ширину, возвращает указатель на массив
{

}

subset_node* merge(subset_node *sn1, subset_node *sn2) //слияние двух деревьев
{

}
*/
/*
int main( )
{
  int k = 1000;
  subset_node* sn;
  init(&sn);
  for (int i = 0; i < k; ++i)
  {
    insert(&sn, i);
    cout << "i = " << i << ", size = " << size(sn) << std::endl;
  }

  insert(&sn, k);
  remove(&sn, k);
  find(sn, k);
  height(sn);
  cout << size(sn) << std::endl;
  int* arr = DFS(sn);
  delete sn;
  delete [] arr;
  return 0;
}
 */