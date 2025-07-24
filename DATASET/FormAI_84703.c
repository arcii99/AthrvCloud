//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, num_guesses=0;

    srand(time(0)); // generating random number
    num = rand() % 100 + 1; // number between 1 and 100

    printf("***Welcome to the Number Guessing Game!***\n");
    printf("You have 10 attempts to guess the number between 1 and 100\n");

    while (num_guesses < 10) {
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) { // checking if guess is valid
            printf("Invalid guess! Please enter a number between 1 and 100\n");
            continue;
        }

        if (guess == num) { // correct guess
            printf("Congratulations! You guessed the number in %d attempts!\n", num_guesses+1);
            return 0;
        } else if (guess < num) { // guess is too low
            printf("Too low!\n");
        } else { // guess is too high
            printf("Too high!\n");
        }

        num_guesses++;
    }

    printf("Sorry, the number was %d. Better luck next time!\n", num);
    return 0;
}