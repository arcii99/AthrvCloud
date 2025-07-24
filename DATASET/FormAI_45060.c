//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate a random number between 1 and 100 */
int generate_random_number() {
    srand(time(NULL));  // seed the random number generator
    return rand() % 100 + 1;
}

/* function to handle the player's guess */
void handle_guess(int guess, int target) {
    if (guess < target) {
        printf("Too low, try again.\n");
    } else if (guess > target) {
        printf("Too high, try again.\n");
    } else {
        printf("Correct! You win!\n");
        exit(0);  // exit the program
    }
}

int main() {
    int target = generate_random_number();  // generate the target number
    int guess, num_guesses = 0;  // initialize the guess and number of guesses

    printf("Guess a number between 1 and 100.\n");

    /* loop until the player guesses correctly */
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);  // read the player's guess

        num_guesses++;  // increment the number of guesses

        handle_guess(guess, target);  // handle the player's guess
    }

    return 0;
}