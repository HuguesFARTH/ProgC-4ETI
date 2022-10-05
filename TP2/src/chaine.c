#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *chaine = "0123456789";
  int size = (int)sizeof(chaine);
  // -----Calcule du nombre de caractères-----
  int cpt = 0;
  for(int i = 0; *chaine; chaine++){
      cpt += 1;
  }
  printf("Il y a %d caractères\n", cpt);

  // -----Copie de la chaine dans une autre chaine-----
  char *chaineCopy = malloc(size * sizeof(char));

  strcpy(chaineCopy, chaine);

  // ou alors

  // for(int i = 0; i < size; i++){
  //   chaineCopy[i] = chaine[i];
  // }

  printf("Message copié: %s\n", chaineCopy);

  // -----Concaténation-----
  char * chaine2 = "***est vraiment super!!!";
  int size2 = (int)sizeof(chaine2);
  char * conc = malloc((size+size2) * sizeof(char));
  strcat(conc,chaine);
  strcat(conc,chaine2);
  printf("Message concaténé: %s\n", conc);
  return 0;
}
