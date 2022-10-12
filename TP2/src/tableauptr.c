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
    int tableauInt[10] = {};
    int *ptrInt = &tableauInt[0];
    
    float tableauFloat[10] = {};
    float *ptrFloat = &tableauFloat[0];
    
    for (short i = 0; i < 10; i++) {
        *ptrInt= rand();
        *ptrFloat = rand()*0.0000033f;
        printf("Int n°%hu: %d\n",i,*ptrInt);
        printf("Float n°%hu: %f\n",i,*ptrFloat);
        ptrInt+=1;
        ptrFloat+=1;
    }
    printf("%d", tableauInt[1]);
    
    for (short i = 0; i< 10; i++){
        printf("Int n°%hu: %d\n",i,*ptrInt);
//        printf("Float n°%hu: %f\n",i,*ptrFloat);
        ptrInt+=1;
//        ptrFloat+=1;
    }

    return 0;
}

