//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("@cls||clear");
}

int main() {
    int guess, number, tries = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("\n\n\tWelcome to the Number Guessing Game!\n");
    printf("\n\t#############################################\n");
    printf("\n\nI'm thinking of a number between 1 and 100. Can you guess it?\n\n");
    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > number) {
            printf("Sorry, your guess is too high. Try again.\n");
        } else if (guess < number) {
            printf("Sorry, your guess is too low. Try again.\n");
        }
    } while (guess != number);

    printf("\nCongratulations! You guessed the number in %d tries!\n\n", tries);
    printf("\t ################################\n");
    printf("\nDo you want to play again? (Y/N)\n");
    char playAgain;
    scanf(" %c", &playAgain);
    if (playAgain == 'Y' || playAgain == 'y') {
        clearScreen();
        main();
    } else {
        printf("\n\nThanks for playing! Come back soon.\n");
    }
    return 0;
}