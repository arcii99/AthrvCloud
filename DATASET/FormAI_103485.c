//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input;
    int guess;
    int num_guesses = 0;
    srand(time(NULL));
    int random_num = rand() % 101;
    printf("Welcome to Guess the Number!\n");
    printf("A random number between 0 and 100 has been generated. Can you guess what it is?\n");

    while (1) {
        num_guesses++;
        printf("Enter your guess: ");
        scanf("%d", &input);
        if (input < 0 || input > 100) {
            printf("Please enter a number between 0 and 100.\n");
        } else if (input < random_num) {
            printf("Your guess is too low. Try again.\n");
        } else if (input > random_num) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);
            break;
        }
    }
    return 0;
}