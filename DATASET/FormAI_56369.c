//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceNum;
    int rollCount;
    char playerName[50];
    int totalDiceRoll = 0;
    int i;
    
    srand(time(NULL));
    
    printf("Hello there! What is your name? ");
    scanf("%s", playerName);
    printf("\n");
    
    printf("Greetings, %s. How many dice do you want to roll? ", playerName);
    scanf("%d", &diceNum);
    printf("\n");
    
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rollCount);
    printf("\n");
    
    printf("Alright, let's roll the dice!\n");
    
    for (i = 0; i < rollCount; i++) {
        int j;
        int total = 0;
        printf("Roll #%d: ", i+1);
        for (j = 0; j < diceNum; j++) {
            int roll = rand() % 6 + 1;
            printf("%d ", roll);
            total += roll;
        }
        printf("Total: %d\n", total);
        totalDiceRoll += total;
    }
    
    printf("\n");
    printf("%s, you rolled a total of %d from your %d rolls!\n", playerName, totalDiceRoll, rollCount);
    printf("I hope your heart is as full as your dice container!\n");

    return 0;
}