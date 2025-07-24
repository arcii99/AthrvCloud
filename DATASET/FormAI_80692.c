//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int secret_num = rand() % 100; // generate a secret number between 0 and 99
    int guess;

    printf("Welcome to the Guess the Number Game!\n"); // print welcome message

    do {
        printf("Enter your guess (between 0 and 99): ");
        scanf("%d", &guess); // read user's guess from input
        
        if(guess < secret_num) {
            printf("Too low! Try again.\n");
        } else if(guess > secret_num) {
            printf("Too high! Try again.\n");
        }
    } while(guess != secret_num); // loop until the user guesses the secret number

    printf("Congratulations! You guessed the secret number (%d).\n", secret_num); // print win message

    return 0;
}