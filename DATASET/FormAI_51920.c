//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
/* Flowing Syntax */

#include<stdio.h>
#include<stdlib.h>

int main() {

    //Declare and Initialize variables
    int a = 10;
    int b = 15;
    int c = 20;

    //If else condition
    if(a > b)
        printf("a is greater than b");
    else
        printf("b is greater than a");
        
    //Switch statement
    switch (c) {
        case 10:
            printf("c is equal to 10");
            break;
        case 20:
            printf("c is equal to 20");
            break;
        case 30:
            printf("c is equal to 30");
            break;
        default:
            printf("c is not equal to 10, 20 or 30");
            break;
    }
    
    //For loop
    for(int i = 0; i < 5; i++) {
        printf("i is %d \n", i);
    }
    
    //While loop
    int j = 0;
    while(j < 5) {
        printf("j is %d \n", j);
        j++;
    }
    
    //Do while loop
    int k = 0;
    do {
        printf("k is %d \n", k);
        k++;
    } while(k < 5);

    return 0;
}