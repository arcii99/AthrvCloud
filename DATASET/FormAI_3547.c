//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    int totalRolls = 0;
    int totalScore = 0;
    int currentRoll = 0;
    
    while (1) {
        printf("Type 'roll' to roll the dice or 'quit' to end the game: ");
        char command[50];
        scanf("%s", command);
        
        if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strcmp(command, "roll") == 0) {
            currentRoll = rollDice();
            printf("You rolled a %d!\n", currentRoll);
            totalScore += currentRoll;
            totalRolls++;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    printf("Game over! You rolled the dice %d times and scored a total of %d.\n", totalRolls, totalScore);
    
    return 0;
}