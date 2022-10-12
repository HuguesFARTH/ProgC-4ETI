#include <stdio.h>

void printIntToBinairy(int number);

int main() {
  // int number = 1024*2*2*2;
  int number = 255;
  printIntToBinairy(number);
  return 0;
}

void printIntToBinairy(int number){
  long int size = sizeof(number);
  int compteur = 0;
  for (long int i = size*8 -1; i >= 0 ;i--) {
    if(compteur%4 == 0){
      printf(" ");
    }
    int bt =  (number >> i) & 1;
    printf("%u", bt);
    compteur += 1;
  }
  printf("\n");
}
