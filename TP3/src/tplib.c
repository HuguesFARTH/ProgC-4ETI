#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __swap(int *a,int *b){
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

short __chercherDichotomie(int *ptrTableau, int size, int value){
  if(size <= 1){
    return *ptrTableau == value;
  }
  else{
    int i = size/2;
    int *addr = (int *)(ptrTableau+i);
    if(*addr > value){
      return __chercherDichotomie(ptrTableau, i, value);
    }else if(*addr < value){
      return __chercherDichotomie(addr, i, value);
    }else{
      return 1;
    }
  }
}

void __tri(int *ptrTableau, int size){
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
      __swap((int *) (addr + i), ptnMin);
      swapCpt++;
    }
  }
}

void __printTableau(int *ptrTableau, int size){
  printf("[");
  for (short i = 0; i < size; i++) {
    if(i == 0){
      printf("%d", *ptrTableau);
      continue;
    }
    printf(", %d", *ptrTableau);
    ptrTableau++;
  }
  printf("]\n");
}

void __printHexa(void* variable, int size){
  // printf("%d\n", sizeof(*variable));
  unsigned char *ptrChar = variable + size;
  for (int i = size; i > 0; i--) {
    ptrChar--;
    printf("%02x ", *ptrChar);
  }
  // printf("\n");
}

short __chercher(int *ptrTableau, int size, int value){
  for (int i = 0; i < size; i++) {
    if(*ptrTableau == value){
      return 1;
    }
    ptrTableau ++;
  }
  return 0;
}
