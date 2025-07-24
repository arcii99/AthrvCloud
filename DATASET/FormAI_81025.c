//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* 
This program generates 10 random integers between 1 and 100. It uses the C standard library function rand(), which returns a random integer, and srand(), which seeds the random number generator with the current time.
*/

int main(){
    int i, randNum;
    srand(time(NULL));

    printf("Generating 10 random numbers:\n");

    for(i=0; i<10; i++){
        randNum = rand() % 100 + 1;
        printf("%d\n", randNum);
    }

    return 0;
}