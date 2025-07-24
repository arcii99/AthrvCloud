//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int lives = 3;
    int num;
    srand(time(NULL)); // seed random number generator
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("You have 3 lives. Guess the number between 1 and 10.\n");
    while (lives > 0) {
        num = rand() % 10 + 1; // generate random number between 1 and 10
        int guess;
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        if (guess == num) {
            printf("Congratulations, you guessed the number!\n");
            score++;
        } else {
            printf("Wrong guess. The number was %d\n", num);
            lives--;
            printf("You have %d lives left\n", lives);
        }
        // check if game is over
        if (lives == 0) {
            printf("\nGame over. Your final score is %d\n", score);
        } else {
            printf("\nPress any key to continue\n");
            getchar(); // flush input buffer
            getchar(); // wait for user input
        }
    }
    return 0;
}