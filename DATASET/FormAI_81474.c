//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secret_num, guess, num_guesses = 0;
    srand(time(NULL)); // random seed
    secret_num = rand() % 100 + 1; // generate secret number between 1 and 100
    
    printf("Welcome to the Guessing Game!\n");
    printf("*****************************\n\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess < secret_num) {
            printf("Too low!\n\n");
        } else if (guess > secret_num) {
            printf("Too high!\n\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d tries!\n", num_guesses);
        }
    } while (guess != secret_num);

    return 0;
}