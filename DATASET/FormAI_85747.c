//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNum = rand() % 10 + 1;
    int guess;
    int numGuesses = 0;

    printf("Welcome to the Haunted House Simulator!\n\n");

    printf("You find yourself in a dark, eerie room. The walls are lined with old, musty books, and the air is thick with a musty scent that lingers in your nostrils. Suddenly, you hear a strange noise coming from the corner of the room...\n\n");

    printf("You cautiously creep towards the corner to investigate, and discover a wooden chest filled with treasure. However, as you reach for it, a ghost appears out of nowhere, blocking your path!\n\n");

    printf("In order to get past the ghost and claim your prize, you must correctly guess a random number between 1 and 10. You have 3 chances to guess correctly...Good Luck!\n\n");

    while(numGuesses < 3) {
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &guess);
        numGuesses++;

        if(guess == randomNum) {
            printf("\nCongratulations! You have successfully defeated the ghost and claimed your treasure!\n");
            return 0;
        }
        else if(numGuesses == 3) {
            printf("\nSorry, you have run out of guesses. The ghost has claimed your soul as its prize...\n\n");
        }
        else {
            printf("\nSorry, that was incorrect. You have %d guesses remaining.\n\n", 3 - numGuesses);
        }
    }
    return 0;
}