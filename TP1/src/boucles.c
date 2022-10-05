#include <stdio.h>

void bouclev1(int compteur);
void bouclev2(int compteur);

int main(int argc, char **argv) {
  int compteur = 10;
  bouclev2(compteur);
}
/*
  Affiche un triangle rectangle avec des boucles for
*/
void bouclev1(int compteur){
  printf("*\n");
  for(int i = 1; i < compteur ; i++){
    printf("*");
    for(int j = 1; j < i; j++){
      printf("#");
    }
    printf("*\n");
  }
  return;
}
/*
  Affiche un triangle rectangle avec des boucles while
*/
void bouclev2(int compteur){
  printf("*\n");
  int i = 1;
  while(i < compteur){
    printf("*");
    int j = 1;
    while(j < i){
      printf("#");
      j++;
    }
    printf("*\n");
    i++;
  }
  return;
}
