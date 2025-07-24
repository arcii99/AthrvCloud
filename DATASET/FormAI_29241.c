//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, count = 0;
    char choice;

    srand(time(0));                 // initialize random seed

    printf("Welcome to the Number Guessing Game!\n\n");
    printf("I'm thinking of a number between 1 and 100.\n\n");

    do {
        num = rand() % 100 + 1;     // generate a random number between 1 and 100
        count = 0;                  // reset guess count

        do {
            printf("Guess the number: ");
            scanf("%d", &guess);
            count++;                // increment guess count

            if (guess > num) {
                printf("Too high! Try again.\n");
            } else if (guess < num) {
                printf("Too low! Try again.\n");
            } else {
                printf("\nCongratulations! You guessed the number in %d tries!\n", count);
            }
        } while (guess != num);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("Thanks for playing. Goodbye!\n");

    return 0;
}