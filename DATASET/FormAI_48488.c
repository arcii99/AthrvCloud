//FormAI DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rollCount, sideCount, i;
    
    srand(time(NULL)); // initialize random number generator
    
    printf("Welcome to the dice roller program!\n\n");
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rollCount);
    
    printf("\nHow many sides does the dice have? ");
    scanf("%d", &sideCount);
    
    printf("\nRolling the %d-sided dice %d times:\n", sideCount, rollCount);
    
    for(i = 0; i < rollCount; i++) {
        printf("Roll %d: %d\n", i+1, rand() % sideCount + 1);
    }
    
    printf("\nThank you for using the dice roller program!\n");
    
    return 0;
}