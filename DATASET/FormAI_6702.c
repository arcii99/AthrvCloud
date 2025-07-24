//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input, num, guessCount = 0;
    char response;

    srand(time(NULL));
    num = rand() % 101;

    printf("\nWelcome to the Peaceful Guessing Game!\nGuess a number between 0 and 100 inclusive.\n");

    do {
        printf("\nGuess: ");
        scanf("%d", &input);
        guessCount++;

        if (input == num) {
            printf("\nCongratulations! You guessed the correct number in %d attempt(s)!\n", guessCount);
            printf("Would you like to play again? (y/n) ");
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                guessCount = 0;
                num = rand() % 101;
                printf("\nGreat! Guess another number between 0 and 100 inclusive.\n");
            }
            else {
                printf("\nThanks for playing! Have a great day!\n");
                break;
            }
        }
        else if (input < num) {
            printf("Higher!\n");
        }
        else {
            printf("Lower!\n");
        }

    } while (1);

    return 0;
}