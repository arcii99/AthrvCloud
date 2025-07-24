//FormAI DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guesses[100];
    int guess_count = 0;
    int random_number;
    int guess;

    srand(time(0));
    random_number = rand() % 100 + 1;

    printf("***Welcome to the Number Guessing Game!***\n\n");

    while(1) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        guesses[guess_count] = guess;
        guess_count++;

        if(guess == random_number) {
            printf("\nCongratulations! You guessed the number in %d tries.\n", guess_count);
            break;
        } else if(guess < random_number) {
            printf("Too low! Guess again.\n\n");
        } else {
            printf("Too high! Guess again.\n\n");
        }

        if(guess_count == 10) {
            printf("Sorry, you did not guess the number in 10 tries.\n");
            break;
        }
    }

    printf("\nHere are your guesses:\n");
    for(int i = 0; i < guess_count; i++) {
        printf("%d ", guesses[i]);
    }

    return 0;
}