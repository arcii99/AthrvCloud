//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random number generator
    srand(time(NULL));

    // ask the user for their name
    printf("Welcome to the Guessing Game! What is your name?\n");
    char name[20];
    scanf("%s", name);
    printf("Nice to meet you, %s!\n", name);

    // generate random number between 1 and 100
    int secret_num = rand() % 100 + 1;
   
    // initialize variables
    int num_guesses = 0;
    int guess = 0;

    // start game loop
    while (guess != secret_num) {
        // ask user for their guess
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        // check if guess is within range
        if (guess < 1 || guess > 100) {
            printf("That's not a valid guess. Please try again.\n");
            continue;
        }

        // increment number of guesses
        num_guesses++;

        // provide feedback on guess
        if (guess < secret_num) {
            printf("Sorry, %s. Your guess is too low. Try again.\n", name);
        } else if (guess > secret_num) {
            printf("Sorry, %s. Your guess is too high. Try again.\n", name);
        }
    }

    // game over - user guessed correctly!
    printf("Congratulations, %s! You guessed the secret number in %d guesses.\n", name, num_guesses);

    return 0;
}