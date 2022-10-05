#include <stdio.h>

int main() {
  /*
    A
  */
  printf("TestA: divisible par 2 et 15");
  int compteur = 0;
  for(int i = 0; i <= 1000; i++){
    if(i%2==0 && i%15==0){
      if(compteur%10 != 0){
        printf(",");
      }else{
        printf("\n");
      }
      printf("%d",i);
      compteur++;
    }
  }
  printf("\n");
  printf("TestA: %d nombres\n\n",compteur);

  printf("TestB: divisible par 103 ou 107");
  compteur = 0;
  for(int i = 0; i <= 1000; i++){
    if(i%103==0 || i%107==0){
      if(compteur%10 != 0){
        printf(",");
      }else{
        printf("\n");
      }
      printf("%d",i);
      compteur++;
    }
  }
  printf("\n");
  printf("TestB: %d nombres\n\n",compteur);

  printf("TestC: divisible par 7 ou 5, mais pas par 3");
  compteur = 0;
  for(int i = 0; i <= 1000; i++){
    if((i%7==0 || i%5==0) && (i%3 != 0)){
      if(compteur%10 != 0){
        printf(",");
      }else{
        printf("\n");
      }
      printf("%d",i);
      compteur++;
    }
  }
  printf("\n");
  printf("TestC: %d nombres\n\n",compteur);
  return 0;
}
