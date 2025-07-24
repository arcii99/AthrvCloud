//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Initialize random number generator
    int guess, secret_number, count = 0;

    printf("Welcome to the Guessing Game!\n\n");
    printf("Guess a number between 1 and 100\n");

    secret_number = rand() % 100 + 1; //Generate a random number between 1 and 100

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;
        
        if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the secret number in %d attempts.\n", count);
        }
    } while (guess != secret_number);

    return 0;
}