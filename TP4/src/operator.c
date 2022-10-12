#include <stdio.h>
#include "operator.h"

int main() {
  int num1 = 16;
  int num2 = 3;
  char op = '*';
  if(op != '+' && op != '-' && op != '*' && op != '/' && op != '%'){
    printf("Cette opération n'est pas valide\n");
    return 1;
  }
  printf("num1%cnum2: %g\n", op, tryOperation(op,num1,num2));
  return 0;
}
