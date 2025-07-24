//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    srand(time(NULL));  // Set seed for random number generator
    int secret_number = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess_count = 0;  // Initialize guess count to 0

    printf("\tGuess the secret number between 1 and 100!\n");

    while (guess_count < MAX_GUESSES) {  // Loop until guess count exceeds maximum guesses
        printf("\nGuess %d: ", guess_count+1);  // Prompt user for guess
        int guess;
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {  // Check if guess is out of bounds
            printf("Invalid guess. Guess must be between 1 and 100.\n");
        } else if (guess == secret_number) {  // Check if guess is correct
            printf("Congratulations! You guessed the secret number in %d guesses!\n", guess_count+1);
            return 0;  // Exit program
        } else {  // Guess is incorrect
            printf("Incorrect guess. ");
            if (guess < secret_number) {  // Check if guess is too low
                printf("The secret number is higher.\n");
            } else {  // Guess is too high
                printf("The secret number is lower.\n");
            }
            guess_count++;  // Increment guess count
        }
    }

    printf("You failed to guess the secret number in %d guesses. The secret number was %d.\n", MAX_GUESSES, secret_number);
    return 0;  // Exit program
}