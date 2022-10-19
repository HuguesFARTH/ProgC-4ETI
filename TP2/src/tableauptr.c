//
//  main.c
//  tableauptr
//
//  Created by Martin Cova on 12/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int tableauInt[10];
    int *ptrInt = &tableauInt;

    float tableauFloat[10];
    float *ptrFloat = &tableauFloat;

    for (short i = 0; i < 10; i++) {
        *(ptrInt+i)= rand()%100;
        *(ptrFloat+i) = (rand()%100)*0.95f;
        printf("Int n°%hu: %d\n",i,*(ptrInt+i));
        printf("Float n°%hu: %f\n",i,*(ptrFloat+i));
    }
    //printf("%d", tableauInt[1]);
    printf("----Modification----\n");
    for (short i = 0; i < 10; i++){
      if(i%2 == 0){
        *(ptrInt+i) *= 3;
        *(ptrFloat+i) *= 3;
      }
    }
    for (short i = 0; i< 10; i++){
      printf("Int n°%hu: %d\n",i,*(ptrInt+i));
      printf("Float n°%hu: %f\n",i,*(ptrFloat+i));
    }
    printf("Fin du prgm\n");
    return 0;
}
