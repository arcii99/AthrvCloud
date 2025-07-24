//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int secret_num = rand() % 100 + 1;
    int guess, num_guesses = 0;
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;
        if (guess == secret_num) {
            printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
            break;
        } else if (guess < secret_num) {
            printf("Too low. Guess again.\n");
        } else {
            printf("Too high. Guess again.\n");
        }
    }
    return 0;
}