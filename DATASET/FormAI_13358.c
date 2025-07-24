//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, numDice;
    int total = 0;
    
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the futuristic dice roller!\n");
    printf("How many sides does your die have?\n");
    scanf("%d", &sides);
    
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);
    
    printf("Rolling %d %d-sided dice...\n", numDice, sides);
    
    for (int i = 1; i <= numDice; i++) {
        int roll = (rand() % sides) + 1;
        printf("Die %d: %d\n", i, roll);
        total += roll;
    }
    
    printf("Total: %d\n", total);
    
    return 0;
}