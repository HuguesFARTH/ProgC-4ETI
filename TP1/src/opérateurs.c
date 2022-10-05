#include <stdio.h>
int main() {
  short a = 16;
  short b = 3;
  printf("a: %hd\n", a);
  printf("b: %hd\n", b);
  printf("a+b: %d\n", a+b);
  printf("a-b: %d\n", a-b);
  printf("a*b: %d\n", (a*b));
  printf("a/b: %g\n", (a/b));
  printf("a%%b: %d\n", a%b);
  return 0;
}
