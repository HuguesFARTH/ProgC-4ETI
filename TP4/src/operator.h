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
