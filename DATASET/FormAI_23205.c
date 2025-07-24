//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Random seed generator
    srand(time(0));

    // Initial instructions
    printf("Welcome to the Guessing Game!\n\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have 10 attempts to guess the number.\n");
    printf("Let's start!\n\n");

    int secret_number = rand() % 100 + 1;
    int attempts = 0;
    int guess = -1;

    while( attempts < 10 && guess != secret_number){
        printf("Attempt %d: Enter your guess (between 1 and 100): ", attempts + 1);
        scanf("%d", &guess);

        if(guess < 1 || guess > 100){
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
        } else {
            if(guess < secret_number){
                printf("Your guess is too low.\n");
            } else if(guess > secret_number){
                printf("Your guess is too high.\n");
            }
            attempts++;
        }
    }

    if(guess == secret_number){
        printf("Congratulations! You guessed the secret number (%d) in %d attempts.\n", secret_number, attempts);
    } else {
        printf("Sorry, you did not guess the secret number (%d).\n", secret_number);
    }

    return 0;
}