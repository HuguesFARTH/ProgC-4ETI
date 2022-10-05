#include <stdio.h>
long int puisssance(int a, int b);

int main() {
  long int puissance = puisssance(2,10);
  printf("Réponse: %ld\n", puissance);
  return 0;
}

long int puisssance(int a, int b){
  long int puiss = b == 0 ? 1 : a;
  for(int i = 1; i < b ; i++){
    puiss *= a;
  }
  return puiss;
}
