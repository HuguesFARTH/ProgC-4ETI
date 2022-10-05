#include <stdio.h>
#include "tplib.c"

int main() {
  printf("sizeof (int): %d\n", sizeof (int));
  printf("sizeof (int *): %d\n", sizeof (int *));
  printf("sizeof (int **): %d\n", sizeof (int **));
  printf("sizeof (char): %d\n", sizeof (char));
  printf("sizeof (char *): %d\n", sizeof (char *));
  printf("sizeof (char **): %d\n", sizeof (char **));
  printf("sizeof (float): %d\n", sizeof (float));
  printf("sizeof (float *): %d\n", sizeof (float *));
  printf("sizeof (float **): %d\n", sizeof (float **));
  return 0;
}
