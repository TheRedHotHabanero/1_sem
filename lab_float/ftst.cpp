#include <iostream>

int main( )
{
  FILE * fd_out;

  fd_out = fopen("tst.txt", "w");

  fprintf(fd_out, "Hello world!\n");

  fclose(fd_out);

  FILE * fd_in = fopen("tst.txt", "r");
  char tmp[300] = {};
  fscanf(fd_in, "%s", tmp);
  fclose(fd_in);

  std::cout << tmp << "\n";

  return 0;
}