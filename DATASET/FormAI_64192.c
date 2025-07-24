//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // seed for random number generator
    int correct_guess = 0; 
    int attempt_count = 0; 
    int random_number = rand() % 100; // generate a random number between 0 and 99
    int guess = -1;

    printf("I'm thinking of a number between 0 and 99. Can you guess it?\n");

    while (correct_guess != 1) { // loop until guess is correct
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempt_count++;

        if (guess == random_number) {
            correct_guess = 1;
            printf("Congratulations! You guessed the number in %d attempts.\n", attempt_count);
        } 
        else if (guess < random_number) {
            printf("Your guess is too low. Try again.\n");
        } 
        else {
            printf("Your guess is too high. Try again.\n");
        }
    }

    return 0;
}