#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void chercher(int *ptrTableau, int size, int value);
void chercher2(char **ptrTableau, char* phrase);

int main() {
  time_t t;
  srand((unsigned)time(&t));
  int tableauInt[10];
  int *ptrInt = &tableauInt;
  short size = sizeof(tableauInt)/sizeof(int);
  printf("size: %hu\n", size);
  int maxValue = 10;
  printf("[");
  for (short i = 0; i < size; i++) {
    tableauInt[i] = (int)(maxValue+1)*((float)rand()/(float)INT_MAX);
    ptrInt++;
    if(i == 0){
      printf("%d", tableauInt[i]);
      continue;
    }
    printf(", %d", tableauInt[i]);
  }
  printf("]\n");
  chercher(&tableauInt, size,10);
  char* tableauChar[4]= {"Petite phrase n°1","Petite phrase n°2","Petite phrase n°3","Petite phrase n°4","Petite phrase n°5"};
  chercher2(&tableauChar,"Petite phrase n°2");
}

void chercher(int *ptrTableau, int size, int value){
  for (int i = 0; i < size; i++) {
    if(*ptrTableau == value){
      printf("L'enter %d est présent dans ce tableau\n", value);
      return;
    }
    ptrTableau ++;
  }
}

void chercher2(char **ptrTableau, char* phrase){
  for (int i = 0; i < 4; i++) {
    if((phrase == *(ptrTableau+i))){
      printf("Phrase retrouvée dans le tableau (index=%d)",i);
      return;
    }
  }
  printf("Phrase non présente dans le tableau");
  return;
}
