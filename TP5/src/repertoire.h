#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
void lire_dossier(char *);
void lire_dossier_recursif_i(char *, int arbo_index);
void lire_dossier_recursif(char *);

void lire_dossier(char * dossier_dir){
  DIR *d = opendir(dossier_dir);
  if(d==NULL) {
    printf("%s\n", "Le dossier n'est pas valide!");
    return;
  }
  struct dirent *dnt;
  // Pour enlever le fichier précédent et courant.
  dnt = readdir(d);
  dnt = readdir(d);
  while ((dnt = readdir(d)) != NULL){
    printf("%s\n", dnt->d_name);
  }
  closedir(d);
}



void lire_dossier_recursif_i(char * dossier_dir, int arbo_index){
  DIR *d = opendir(dossier_dir);
  if(d==NULL) {
    printf("%s\n", "Le dossier n'est pas valide!");
    return;
  }
  struct dirent *dnt;
  dnt = readdir(d);
  dnt = readdir(d);
  while ((dnt = readdir(d)) != NULL){
        for (int i = 0; i < arbo_index; i++) {
          printf("  ");
        }
        printf("%s\n", dnt->d_name);
        if((dnt->d_type == 0x4)){
          //DOSSIER
          char tpDir[100];
          strcat(strcpy(tpDir, dossier_dir), "\\");
          strcat(tpDir, dnt->d_name);
          lire_dossier_recursif_i(tpDir,arbo_index+1);
        }else{
          //FICHIER
        }

  }
  closedir(d);
}

void lire_dossier_recursif(char * dossier_dir){
  lire_dossier_recursif_i(dossier_dir, 0);
}
