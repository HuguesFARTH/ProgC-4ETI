#include <stdio.h>
#include <string.h>

struct Etudiant{
  char nom[30];
  char prenom[30];
  char adresse[60];
  // 0 -> Programmation en C | 1 -> Système d'exploitation
  short notes[2];
};

void printEtudiant(struct Etudiant et);
void initEtudiant(struct Etudiant *et);

int main() {
  struct Etudiant etudiants[5];
  //initialisation d'un étudiant
  int size = (int)(sizeof(etudiants)/(sizeof(char)*30*4-sizeof(short)*2));
  for(int i = 0; i < size; i++){
    printf("Etudiant %d:\n",i);
    initEtudiant(&etudiants[i]);
    printEtudiant(etudiants[i]);
  }
  return 0;
}

void initEtudiant(struct Etudiant *et){
  strcpy(et->prenom, "Hugues");
  strcpy(et->nom, "Farthouat");
  strcpy(et->adresse, "qqp en France, à Villeurbanne");
  et -> notes[0]=16;
  et -> notes[1]=15;
}
void printEtudiant(struct Etudiant et){
  printf("%s %s\n", et.prenom,et.nom);
  printf("--Adresse: %s\n", et.adresse);
  printf("--Notes: Programmation en C:%hu Système d'exploitation:%hu\n", et.notes[0],et.notes[1]);
}
