#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"


int main(){
  ecrire_dans_fichier("main.c","5275\n25\n255\n");
  lire_fichier("main.c");
  ecrire_dans_fichier("main.c","test\ntttt\nii\n");
  lire_fichier("main.c");
  return 0;
}
