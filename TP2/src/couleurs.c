#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
};

int main() {
  struct Color colors[10];
  time_t t;
  srand((unsigned)time(&t));
  int size = (int)(sizeof(colors)/(sizeof(char)*4));
  for(int i = 0; i < size; i++){
    int random = rand();
    colors[i].r=(char)random;
    colors[i].g=(char)random>>2;
    colors[i].b=(char)random>>4;
    colors[i].a=(char)random>>6;
    printf("Couleur %d: r=%#x, g=%#x, b=%#x, a=%#x\n",i,colors[i].r,colors[i].g,colors[i].b,colors[i].a);
  }
  return 0;
}
