#include <stdio.h>

int main() {

  printf("----Taille de différentes variables de types différents----\n");

  printf("---Signed---\n");
  char varChar = 'r';
  printf("char: %luo\n", sizeof(varChar));
  short varShort = -10;
  printf("short: %luo\n", sizeof(varShort));
  short varInt = 10;
  printf("int: %luo\n", sizeof(varInt));
  short varLongInt = -10;
  printf("long int: %luo\n", sizeof(varLongInt));
  short varLongLongInt = 10;
  printf("long long int: %luo\n", sizeof(varLongLongInt));
  short varFloat = 10.10;
  printf("float: %luo\n", sizeof(varFloat));
  short varDouble = 10.045;
  printf("double: %luo\n", sizeof(varDouble));
  short varLongDouble = 10000;
  printf("long double: %luo\n", sizeof(varLongDouble));

  printf("---Unsigned---\n");
  unsigned char varUnsignedChar = 'r';
  printf("unsigned char: %luo\n", sizeof(varUnsignedChar));
  unsigned short varUnsignedShort = 10;
  printf("unsigned short: %luo\n", sizeof(varUnsignedShort));
  unsigned int varUnsignedInt = 10;
  printf("unsigned int: %luo\n", sizeof(varUnsignedInt));
  unsigned long int varUnsignedLongInt = 10000;
  printf("unsigned long int: %luo\n", sizeof(varUnsignedLongInt));
  unsigned long long int varUnsignedLongLongInt = 1000000;
  printf("unsigned long long int: %luo\n", sizeof(varUnsignedLongLongInt));
  return 0;
}
