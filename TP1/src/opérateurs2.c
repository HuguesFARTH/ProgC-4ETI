#include <stdio.h>

double tryOperation(char op, int num1, int num2);

int main() {
  int num1 = 16;
  int num2 = 3;
  char op = '-';
  if(op != '+' && op != '-' && op != '*' && op != '/' && op != '%'){
    printf("Cette opération n'est pas valide\n");
    return 1;
  }
  printf("num1%cnum2: %g\n", op, tryOperation(op,num1,num2));
  return 0;
}

double tryOperation(char op, int num1, int num2){
  double number = 0;
  switch (op) {
    case '+' :
      number = num1+num2;
      break;
    case '-' :
      number = num1-num2;
      break;
    case '*' :
      number = num1*num2;
      break;
    case '/' :
      number = num1/num2;
      break;
    case '%' :
      number = num1%num2;
      break;
    default :
      break;
  }
  return number;
}
