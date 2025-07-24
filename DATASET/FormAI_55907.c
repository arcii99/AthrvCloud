//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, nguesses = 1;
    srand(time(0));
    number = rand() % 100 + 1;

    printf("\n\n\t\tWelcome to the Guess the Number Game!");

    do {
        printf("\n\nGuess the number between 1 to 100: ");
        scanf("%d", &guess);

        if (guess < number) {
            printf("Higher number please!");
        } else if (guess > number) {
            printf("Lower number please!");
        } else {
            printf("\n\nCongratulations! You guessed it right in %d attempts", nguesses);
        }

        nguesses++;

    } while (guess != number);

    printf("\n\nThank you for playing...Have a nice day!");

    return 0;
}