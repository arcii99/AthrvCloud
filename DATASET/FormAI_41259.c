//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);

int main(void) {
    int roll1, roll2, total;
    srand((unsigned) time(NULL));       // "seed" the rand() function with current time
    
    printf("Welcome to the Dice Roller program!\n\n");
    printf("Press ENTER to roll the dice...\n\n");
    
    while (getchar() == '\n') {         // continue looping as long as the user presses ENTER
        roll1 = roll_dice();
        roll2 = roll_dice();
        total = roll1 + roll2;
        
        printf("You rolled a %d and a %d\n", roll1, roll2);
        printf("For a total of %d\n", total);
        
        if (total == 7 || total == 11) {
            printf("Congratulations, you win!\n\n");
        }
        else if (total == 2 || total == 3 || total == 12) {
            printf("Sorry, you lose!\n\n");
        }
        else {
            printf("Roll again! Press ENTER to roll the dice...\n\n");
        }
    }
    
    printf("Thanks for playing!\n");
    return 0;
}

int roll_dice(void) {
    return (rand() % 6) + 1;
}