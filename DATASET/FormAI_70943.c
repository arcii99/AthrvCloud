//FormAI DATASET v1.0 Category: Random ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num[10];
    int i, j, temp;
    time_t t;
    
    srand((unsigned) time(&t)); // Initialize random number generator

    // Generate 10 random numbers between 1 and 100
    printf("Generated numbers: ");
    for(i = 0; i < 10; i++){
        num[i] = (rand() % 100) + 1;
        printf("%d ", num[i]);
    }

    // Sort the array in descending order
    for(i = 0; i < 9; i++){
        for(j = i+1; j < 10; j++){
            if(num[j] > num[i]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    // Print sorted array
    printf("\nSorted numbers: ");
    for(i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }

    return 0;
}