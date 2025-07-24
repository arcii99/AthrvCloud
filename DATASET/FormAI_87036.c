//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dieRoll;
    char playAgain;
    srand(time(NULL));

    /* repeat rolling the dice until user chooses to stop */
    do {
        printf("Rolling the dice...\n");
        dieRoll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dieRoll);

        /* prompt user to play again */
        printf("Roll again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing!\n");
    return 0;
}