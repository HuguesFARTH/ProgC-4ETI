#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void lire_fichier(char* nom_de_fichier){
  FILE* fichier = fopen(nom_de_fichier,"r");
  struct stat sf;
  stat(nom_de_fichier,&sf);
  int max_size = sf.st_size;
  char ligne[max_size];
  char lignes[max_size];
  if(fichier != NULL){
    fgets(lignes,max_size,fichier);
    while(fgets(ligne,max_size,fichier)){
      strcat(lignes,ligne);
    }
    fclose(fichier);
  }
  printf("%s",lignes);
  //TODO return lignes;
}

void ecrire_dans_fichier(char* nom_de_fichier, char* value){
  FILE* fichier = fopen(nom_de_fichier,"w");
  if(fichier != NULL){
    printf("Write: %s\n", value);
    fputs(value, fichier);
    fclose(fichier);
  }
}
