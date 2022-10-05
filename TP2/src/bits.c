#include <stdio.h>

short bytesCheck(int d);

void printIntToBinairy(int number);

int main() {
  // 4eme bit à 0 et 20 à 0
  short byte = bytesCheck(0x00000000);
  printf("Réponse 1: %hd\n", byte);
  // 4eme bit à 0 et 20 à 1
  byte = bytesCheck(0x00001000);
  printf("Réponse 2: %hd\n", byte);
  // 4eme bit à 1 et 20 à 1
  byte = bytesCheck(0x10001000);
  printf("Réponse 3: %hd\n", byte);
  // 4eme bit à 1 et 20 à 0
  byte = bytesCheck(0x10000000);
  printf("Réponse 4: %hd\n", byte);
  return 0;
}

short bytesCheck(int d){
  // printIntToBinairy(d);
  short size0 = sizeof(d)*8;
  return ((d >> (size0-20)) & 1) && ((d >> (size0-4)) & 1);
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
