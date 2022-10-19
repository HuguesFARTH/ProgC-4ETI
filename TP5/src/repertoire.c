#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "repertoire.h"

int main(){
  char path[100] = "C:\\Users\\hugue\\Documents\\ProgC-4ETI";
  //printf("Dossier à scanner: ");
  //scanf("%100s",path);
  lire_dossier_recursif(path);
  return 0;
}
