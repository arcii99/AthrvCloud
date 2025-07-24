//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int score = 0;
    int round = 1;
    int guess;
    int secret_number;
    int min = 1;
    int max = 100;

    srand(time(NULL)); //initialize random seed

    printf("***********************************************************\n");
    printf("            Welcome to the Guessing Game!\n");
    printf("***********************************************************\n\n");

    //start game loop
    while (round <= 5) {
        secret_number = rand() % (max - min + 1) + min; //generate secret number

        printf("Round %d: Guess a number between %d and %d\n", round, min, max);
        scanf("%d", &guess); //get user's guess

        if (guess == secret_number) {
            score += 10;
            printf("Congratulations! You guessed the secret number!\n");
            printf("Your score is now %d\n\n", score);
        } else if (guess < min || guess > max) {
            printf("Invalid guess! Please guess a number between %d and %d\n", min, max);
            printf("Your score is still %d\n\n", score);
        } else {
            printf("Sorry, that is not the secret number. The secret number was %d\n", secret_number);
            printf("Your score is still %d\n\n", score);
        }

        round++; //increment round number
    }

    printf("***********************************************************\n");
    printf("                Final Score: %d\n", score);
    printf("***********************************************************\n");

    return 0; //end program
}