//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Welcome message
    printf("Welcome to the Amazing Number Game!\n");

    // Generate a random secret number between 1 and 100
    srand(time(0));
    int secret_number = rand() % 100 + 1;

    // Game instructions
    printf("\nThe rules of the game are simple. You need to guess the secret number.\n"
           "Each time you guess, I will tell you if the number you guessed is higher or lower than the secret number.\n"
           "You have five chances to guess the secret number.\n");

    int num_guesses = 0;
    int guess = 0;
    while (num_guesses < 5) {
        printf("\nGuess #%d: ", num_guesses + 1);
        scanf("%d", &guess);
        if (guess == secret_number) {
            // User guessed correctly, end game
            printf("Congratulations! You've guessed the secret number (%d) in %d tries!", 
                    secret_number, num_guesses + 1);
            break;
        } else if (guess < secret_number) {
            printf("Sorry, your guess (%d) is too low. Try again.", guess);
        } else {
            printf("Sorry, your guess (%d) is too high. Try again.", guess);
        }
        num_guesses++;
    }
    if (num_guesses == 5) {
        printf("Oops, you've run out of guesses! The secret number was %d. Better luck next time!", 
               secret_number);
    }

    return 0;
}