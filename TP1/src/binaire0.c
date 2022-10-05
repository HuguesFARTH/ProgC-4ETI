#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void printIntToBinairy(int number);

int main() {
  // int number = 1024*2*2*2;
  int number = 255;
  printIntToBinairy(64);
  return 0;
  for (int i = 0; i < INT_MAX; i++) {
    printf("----%u----\n",i);
    printIntToBinairy(i);
    i=i+i;
    sleep(1);
  }
  return 0;
}

void printIntToBinairy(int number){
  short delete_0 = 1;
  long int size = sizeof(number);
  char b;
  if(delete_0){
    if(number < 0x1000000){
      // printf("%s\n", "0xf000000");
      size--;
    }
    if(number < 0x10000){
      // printf("%s\n", "0xf000");
      size--;
    }
    if(number < 0x100){
      // printf("%s\n", "0xf00");
      size--;
    }
  }

  printf("\n");
  short compteur = 0;
  for(int i = size-1; i >=0; i--){
    short startJ = 7;
    //Ici on définit la variable startJ permettant de supprimer les 0 inutiles (par pack de 4 bytes)
    if (delete_0) {
      if (i==size-1){
        if(numberO[i] == 0 && size > 1){
            startJ = -1;
        }
        // 16 car en hexa
        else if(numberO[i] < 16){
            startJ = 3;
        }
      }
    }
    for (int j = startJ; j >= 0; j--) {
      b = (numberO[i] >> j) & 1;
      printf("%u", b);
      compteur++;
      if(compteur%4==0){
        printf(" ");
      }
    }
  }
  printf("\n");
}
