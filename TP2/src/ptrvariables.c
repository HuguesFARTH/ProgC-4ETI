#include <stdio.h>

int main() {
  int varInt = 0xa47865ff;
  printf("---i: %x---\n", (varInt));
  float varFloat = 1;
  float *ptrFloat = &varFloat;
  unsigned char *ptrChar = ptrFloat;
  printf("testBla\n");
  for (int i = 0; i < 4; i++) {
    printf("%#02x\n",*ptrChar);
    ptrChar++;
  }
  printf("\n");
  return 0;
}
