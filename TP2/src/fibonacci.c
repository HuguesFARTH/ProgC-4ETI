#include <stdio.h>

void printFibonacci(int n);

int main() {
  int n = 10;
  printFibonacci(n);
  return 0;
}

void printFibonacci(int n){
  int u0 = 0;
  int u1 = 1;
  int un = 0;
  for (int i = 0; i < n+1; i++) {
    if(i == 0){
      printf("%d", u0);
      continue;
    }
    if(i==1){
      printf(", %d", u1);
      continue;
    }
    un = u0 + u1;
    u0 = u1;
    u1 = un;
    printf(", %d", un);
  }
}
