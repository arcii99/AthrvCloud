//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int score = 0;
    int guess;
    int secret_num;
    char play_again = 'y';
    srand(time(NULL));

    // game loop
    while (play_again == 'y') {
        score = 0;
        printf("\nWelcome to the Number Guessing Game!\n\n");
        printf("I'm thinking of a number between 1 and 100.\n");
        printf("Guess what number I'm thinking of: ");
        secret_num = rand() % 100 + 1;

        do {
            scanf("%d", &guess);
            score++;
            if (guess > secret_num) {
                printf("Too high, guess again: ");
            } else if (guess < secret_num) {
                printf("Too low, guess again: ");
            }
        } while (guess != secret_num);

        printf("\nCongrats, you guessed the secret number! It took you %d guesses.\n", score);
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing the Number Guessing Game!\n");
    return 0;
}