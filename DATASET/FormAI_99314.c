//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, tries = 0;
    srand(time(0));
    secret_number = rand() % 100 + 1; // generate random number between 1 and 100
    printf("Welcome to the Guessing Game!\n");
    printf("Try to guess the secret number between 1 and 100 in 10 or fewer tries.\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries.\n", tries);
            break;
        }
    } while (tries < 10);
    if (tries == 10) {
        printf("Sorry, you reached the maximum number of tries. The secret number was %d.\n", secret_number);
    }
    return 0;
}