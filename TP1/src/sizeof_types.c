#include <stdio.h>

int main() {

  printf("----Taille des différents types de variable----\n");

  printf("---Signed---\n");
  printf("char: %luo\n", sizeof(char));
  printf("short: %luo\n", sizeof(short));
  printf("int: %luo\n", sizeof(int));
  printf("long int: %luo\n", sizeof(long int));
  printf("long long int: %luo\n", sizeof(long long int));
  printf("float: %luo\n", sizeof(float));
  printf("double: %luo\n", sizeof(double));
  printf("long double: %luo\n", sizeof(long double));

  printf("---Unsigned---\n");
  printf("unsigned char: %luo\n", sizeof(unsigned char));
  printf("unsigned short: %luo\n", sizeof(unsigned short));
  printf("unsigned int: %luo\n", sizeof(unsigned int));
  printf("unsigned long int: %luo\n", sizeof(unsigned long int));
  printf("unsigned long long int: %luo\n", sizeof(unsigned long long int));
  return 0;
}
