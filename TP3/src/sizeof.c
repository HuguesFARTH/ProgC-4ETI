#include <stdio.h>

int main() {
  int monInt = 100;
  int* monIntcpt = &monInt;
  int ** test = &monIntcpt;
  printf("%d\n", monInt);
  printf("%d\n", &monInt);
  printf("%ld %ld\n", *monInt);
  printf("%ld %ld\n", monIntcpt);
  printf("%ld %ld\n", &monIntcpt);
  printf("%ld %ld\n", *monIntcpt);
  printf("%ld %ld\n", test);
  printf("%ld %ld\n", &test);
  printf("%ld %ld\n", *test);
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
