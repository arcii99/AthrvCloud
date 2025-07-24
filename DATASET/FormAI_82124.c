//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\n*** WELCOME TO THE GUESSING GAME ***\n\n");
    printf("Instructions: Guess a number between 1 and 100.\n"
           "You have 10 attempts to guess the correct number.\n\n");
    
    int secret_number = rand() % 100 + 1;
    int user_guess, attempts = 0;

    while (attempts < 10) {
        printf("Attempt #%d:\n", attempts + 1);
        scanf("%d", &user_guess);

        if (user_guess < secret_number) {
            printf("Too low! Try a higher number.\n\n");
        } 
        else if (user_guess > secret_number) {
            printf("Too high! Try a lower number.\n\n");
        } 
        else {
            printf("\nWOW! You guessed the secret number %d!\n"
                   "You guessed it in %d attempt(s).\n\n"
                   "Thanks for playing the guessing game!\n", 
                   user_guess, attempts + 1);
            return 0;
        }
        attempts++;
    }
    printf("Sorry, you couldn't guess the secret number %d.\n"
           "Better luck next time!\n", secret_number);
    return 0;
}