#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void tri(int *ptrTableau, int size);
void swap(int *a,int *b);

int main() {
  time_t t;
  srand((unsigned)time(&t));
  int tableauInt[100];
  int *ptrInt = &tableauInt;
  short size = sizeof(tableauInt)/sizeof(int);
  printf("size: %hu\n", size);
  int maxValue = 10;
  printf("[");
  for (short i = 0; i < size; i++) {
    tableauInt[i] = (int)maxValue*((float)rand()/(float)INT_MAX);
    ptrInt++;
    if(i == 0){
      printf("%d", tableauInt[i]);
      continue;
    }
    printf(", %d", tableauInt[i]);
  }
  printf("]\n");
  tri(&tableauInt, size);
  printf("[");
  for (short i = 0; i < size; i++) {
    if(i == 0){
      printf("%d", tableauInt[i]);
      continue;
    }
    printf(", %d", tableauInt[i]);
  }
  printf("]\n");
  return 0;
}


void tri(int *ptrTableau, int size){
  int *addr = ptrTableau;
  int current;
  int min;
  int *ptnMin;
  int swapCpt = 0;
  for (int i = 0; i < size; i++) {
    ptrTableau = (int *)addr + i;
    current = *ptrTableau;
    min = current;
    ptnMin = ptrTableau;
    for (int j = i+1; j < size; j++) {
      ptrTableau = (int *) addr + j;
      current = *ptrTableau;
      if(min > current){
        min = current;
        ptnMin = ptrTableau;
      }
    }
    if(ptnMin != (int *) (addr + i)){
      swap((int *) (addr + i), ptnMin);
      swapCpt++;
    }
  }
  printf("End in %d swap\n", swapCpt);
}

void swap(int *a,int *b){
  // printf("a:%d b:%d\n",*a,*b);
  int tmp = *b;
  *b = *a;
  *a = tmp;
}
