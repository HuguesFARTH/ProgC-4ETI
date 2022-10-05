#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "tplib.c"
short chercherDichotomie(int *ptrTableau, int size, int value);

int main() {
  time_t t;
  srand((unsigned)time(&t));
  int tableauInt[10];
  short size = sizeof(tableauInt)/sizeof(int);
  printf("size: %hu\n", size);
  int maxValue = 10;
  for (short i = 0; i < size; i++) {
    tableauInt[i] = (int)(maxValue+1)*((float)rand()/(float)INT_MAX);
  }
  __tri(&tableauInt, size);
  __printTableau(&tableauInt,size);
  printf("-----Dichotomie-----\n");
  int value = 8;
  printf("Recherche de %d",value);
  printf("\nRésultat: %s\n", chercherDichotomie(&tableauInt,size,value) ? "entier présent" : "entier absent");
  return 0;
}

short chercherDichotomie(int *ptrTableau, int size, int value){
  printf(".");
  if(size <= 1){
    return *ptrTableau == value;
  }
  else{
    int i = size/2;
    int *addr = (int *)(ptrTableau+i);
    if(*addr > value){
      return chercherDichotomie(ptrTableau, i, value);
    }else if(*addr < value){
      return chercherDichotomie(addr, i, value);
    }else{
      return 1;
    }
  }
}
