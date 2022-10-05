#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "tplib.c"


struct Color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
};

short compareColors(struct Color *c1,struct Color *c2);
int calcColor(struct Color *color);
struct Color colorFromCalc(int calc);

int main() {
  struct Color colors[100];
  time_t t;
  srand((unsigned)time(&t));
  int size = (int)(sizeof(colors)/(sizeof(char)*4));
  for(int i = 0; i < size; i++){
    time(&t);
    int random = rand();
    colors[i].r=(char)random;
    colors[i].g=(char)random>>2;
    colors[i].b=(char)random>>4;
    colors[i].a=(char)random>>6;
  }
  printf("Couleur r=%#02x, g=%#02x, b=%#02x, a=%#02x\n",colors[0].r,colors[0].g,colors[0].b,colors[0].a);
  int calc = calcColor(&colors[0]);
  struct Color color = colorFromCalc(calc);
  printf("Couleur r=%#02x, g=%#02x, b=%#02x, a=%#02x\n",color.r,color.g,color.b,color.a);

  // int results[100][4] = malloc(100*sizeof(int)*sizeof(int));

  // struct Color colorsv2[100] = colors;
  // for(int i = 0, i < size; i++){
  //   int calc = calcColor(colorsv2[i]);
  //
  // }
  return 0;
}


short compareColors(struct Color *c1,struct Color *c2){
  return calcColor(c1) == calcColor(c2);
}

int calcColor(struct Color *color){
  int value = 0;
  int *ptrValue = &value;
  ptrValue = color;
  value = *ptrValue;
  __printHexa(&value,sizeof(value));
  return value;
}

struct Color colorFromCalc(int calc){
  struct Color color;
  color.r=(char)calc;
  color.g=(char)calc>>2;
  color.b=(char)calc>>4;
  color.a=(char)calc>>6;
  return color;
}
