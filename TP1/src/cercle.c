#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char **argv);

double aire(double rayon);

double perimetre(double rayon);

int main(int argc, char **argv) {
  double rayon = 1;
  if(argv[1]){
    /* Cette fonction, signifiant string to double,
       permet de transformer une chaîne de caractères,
       contenant la représentation textuelle d'un nombre
       flottant en une donnée typée double.*/
    rayon = strtod(argv[1], NULL);
  }
  printf("Rayon: %lf\n", rayon);
  printf("Aire: %lf\n",aire(rayon));
  printf("Périmètre: %lf",perimetre(rayon));
  return 0;
}

double aire(double rayon){
  return rayon*rayon*3.1415927;
}

double perimetre(double rayon){
  return 2.0*rayon*3.1415927;
}
