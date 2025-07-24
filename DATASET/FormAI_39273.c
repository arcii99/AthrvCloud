//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int score = 0; // Initializing the score variable

    printf("Welcome to the Random Number Game!\n\n"); // Game Title
    printf("The game will generate a random number between 1 and 10.\n");
    printf("Your task is to guess the number correctly within 3 attempts.\n");

    srand(time(NULL)); // Initializing seed for random number generator

    int random_number = rand() % 10 + 1; // Generating random number

    int attempts_left = 3; // Initializing attempts left variable

    while (attempts_left > 0) {
        int guess;
        printf("\nEnter your guess (between 1 and 10): ");
        scanf("%d", &guess);

        if (guess == random_number) {
            printf("\nCongratulations! You guessed the number correctly.\n");
            score += attempts_left * 10; // Incrementing score based on the attempts remaining
            printf("Your score is: %d\n", score); // Displaying the score
            break; // Exiting the loop as the correct guess has been made
        }
        else {
            attempts_left--; // Decrementing the attempts left variable

            if (attempts_left == 0) {
                printf("\nSorry, you have used all your attempts. The correct number was %d.\n", random_number); // Displaying the correct number
                break; // Exiting the loop as attempts left have been exhausted
            }

            printf("\nIncorrect guess. %d attempts left.\n", attempts_left); // Informing the user about the wrong guess and attempts left
        }

    }

    return 0;

}