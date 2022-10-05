#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tplib.c"
#include "hashmap.c"


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
  int size = 100;
  struct Color *colors = malloc(size*4*1);
  time_t t;
  srand((unsigned)time(&t));
  short numberOfAllowedColors = 5;
  int *colorsAllowed = malloc(numberOfAllowedColors * sizeof(int));
  for(int i = 0; i < numberOfAllowedColors; i++){
    *(colorsAllowed+i) = rand();
    // printf("%d,\n",*(colorsAllowed+i));
  }
  // printf("\n");
  for(int i = 0; i < size; i++){
    int random = *(colorsAllowed+(rand()%numberOfAllowedColors));
    colors[i].r=(char)random;
    colors[i].g=(char)random>>2;
    colors[i].b=(char)random>>4;
    colors[i].a=(char)random>>6;
    // printColor(colors[i]);
  }


  HASHMAP map = createHashMap();
  // printHashMap(&map);
  for(int i = 0; i < size; i++){
    struct Color color = colors[i];
    int c = calcColor(&color);
    putHashMapInc(&map,c,1,1);
  }
  // printHashMap(&map);
  printf("\n---------Résultat---------\n");
  printf("\n");
  for (int i = 0; 0 < map.size; i++) {
    ENTRY ent = getFirstEntryHashMap(&map);
    printf("key:%u value:%u\n", ent.key,ent.value);
    __printHexa(&ent.key,4);
    printf(": %i\n",ent.value);
    removeHashMap(&map,ent.key);
    printf("\n");
  }
  printf("--------------------------\n");
  return 0;
}

short compareColors(struct Color *c1,struct Color *c2){
  return calcColor(c1) == calcColor(c2);
}

int calcColor(struct Color *color){
  int value = 0;
  int *ptrValue = color;
  value = *ptrValue;
  // __printHexa(&value,sizeof(value));
  return value;
}

void printColor(struct Color color){
    printf("Couleur r=%#02x, g=%#02x, b=%#02x, a=%#02x\n", color.r,color.g,color.b,color.a);
}

struct Color colorFromCalc(int calc){
  struct Color color;
  color.r=(char)calc;
  color.g=(char)calc>>2;
  color.b=(char)calc>>4;
  color.a=(char)calc>>6;
  return color;
}
