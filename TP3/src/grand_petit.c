#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main() {
  time_t t;
  srand((unsigned)time(&t));
  int tableauInt[1000];
  int *ptrInt = &tableauInt;
  short size = sizeof(tableauInt)/sizeof(int);
  printf("size: %hu\n", size);
  int maxValue = 100;
  for (short i = 0; i < size; i++) {
    tableauInt[i] = (int)maxValue*((float)rand()/(float)INT_MAX);
    // printf("%d\n", tableauInt[i]);
    ptrInt++;
  }
  int max = INT_MIN;
  int min = INT_MAX;
  int tmp = 0;
  printf("-------Calcule-------\n");
  for (short i = 0; i < size; i++) {
    tmp = tableauInt[i];
    printf("%d\n", tmp > max);
    if(tmp > max){
      max = tmp;
      printf("Max: %d\n", tmp > max);
    }
    if(tmp < min){
      min = tmp;
      printf("Min: %d\n", min);
    }
    ptrInt+=1;
  }
  printf("Max: %d, Min: %d\n", max, min);
  return 0;
}
