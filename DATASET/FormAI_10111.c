//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Welcome to the Guessing Game*/
int main()
{
    int secret_number = 42;
    char player_name[50];
    int player_guess;
    int guesses_left = 5;

    printf("Welcome to the Guessing Game! What is your name? ");
    scanf("%s", &player_name);
    printf("\n");

    while (guesses_left > 0) {
        printf("Guesses left: %d\n", guesses_left);
        printf("%s, please enter your guess (between 1 and 100): ", player_name);
        scanf("%d", &player_guess);
        printf("\n");

        if (player_guess == secret_number) {
            printf("Congratulations, %s! You've guessed the number!\n", player_name);
            printf("You won the game in %d guesses\n", 5 - guesses_left + 1);
            exit(0);
        } else if (player_guess < secret_number) {
            printf("Your guess is too low! Try again.\n");
        } else if (player_guess > secret_number) {
            printf("Your guess is too high! Try again.\n");
        }

        guesses_left--;
    }

    printf("Sorry, %s. You've run out of guesses. The secret number was %d.\n", player_name, secret_number);

    return 0;
}