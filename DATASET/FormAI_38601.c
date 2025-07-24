//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * A minimalist game where the player must guess the randomly generated number between 1 and 100.
 * The player has a limited number of attempts and will receive hints after each incorrect guess.
 */

int main() {
    int number, guess, attempts = 10;
    srand(time(NULL)); // Seed random number generator with current time
    number = rand() % 100 + 1; // Generate random number between 1 and 100

    printf("Guess the number between 1 and 100\n");
    printf("You have %d attempts\n", attempts);

    while(attempts > 0) {
        printf("Guess: ");
        scanf("%d", &guess);

        if(guess < 1 || guess > 100) {
            printf("Invalid guess! Must be between 1 and 100\n");
            continue;
        }

        if(guess == number) {
            printf("Congratulations! You guessed the number in %d attempts\n", 10 - attempts + 1);
            return 0;
        } else {
            attempts--;
            printf("Incorrect guess! ");

            if(guess > number)
                printf("The number is lower\n");
            else
                printf("The number is higher\n");

            printf("You have %d attempts remaining\n", attempts);
        }
    }

    printf("Game over! The number was %d\n", number);

    return 0;
}