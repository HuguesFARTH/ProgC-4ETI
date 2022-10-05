#include <stdio.h>

void printHexa(void *variable, int size);

int main() {
  int test1 = 0xa47865ff;
  printHexa(&test1,sizeof(test1));
  float test2 = 1;
  printHexa(&test2,sizeof(test2));
  char *test3 = "blabla";
  printHexa(&test3,sizeof(test3));
  return 0;
}

void printHexa(void* variable, int size){
  printf("Sur %d octets:\n", size);
  unsigned char *ptrChar = variable + size;
  printf("->");
  for (int i = size; i > 0; i--) {
    ptrChar--;
    printf("%02x ", *ptrChar);
  }
  printf("\n");
}
