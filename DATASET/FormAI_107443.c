//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A cheerful C program to roll a dice

int main() {
    int diceNum, rollNum;
    srand(time(NULL));
    
    printf("Welcome to the Happy Dice Roller! Let's roll some dice!\n\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &diceNum);
    
    printf("How many times would you like to roll each die? ");
    scanf("%d", &rollNum);
    
    printf("\nRolling %d dice %d times each...\n\n", diceNum, rollNum);
    
    for(int i = 0; i < diceNum; i++) {
        int total = 0;
        for(int j = 0; j < rollNum; j++) {
            int diceRoll = rand() % 6 + 1;
            total += diceRoll;
            printf("Dice %d Roll %d: %d\n", i+1, j+1, diceRoll);
        }
        printf("\nTotal for dice %d: %d\n\n", i+1, total);
    }
    
    printf("Thanks for rolling with the Happy Dice Roller! Have a nice day!\n");
    return 0;
}