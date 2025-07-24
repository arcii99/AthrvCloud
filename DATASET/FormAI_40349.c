//FormAI DATASET v1.0 Category: Funny ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Dice Game!\n");
    printf("Press enter to roll the dice...\n");
    getchar(); // waits for user to press enter
    
    srand(time(NULL)); // seed random number generator with current time
    int dice1 = (rand() % 6) + 1; // generates a number between 1 and 6
    int dice2 = (rand() % 6) + 1;
    
    printf("Dice 1: %d\n", dice1);
    printf("Dice 2: %d\n", dice2);
    
    if (dice1 == 6 && dice2 == 6) {
        printf("You rolled double 6's! You win the grand prize!\n");
    } else if ((dice1 == 1 && dice2 == 2) || (dice1 == 2 && dice2 == 1)) {
        printf("You rolled a 1 and a 2. You win a small prize!\n");
    } else {
        printf("Better luck next time!\n");
    }
    
    return 0;
}