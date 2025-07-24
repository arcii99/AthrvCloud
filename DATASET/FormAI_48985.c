//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int randomNumber, userGuess, attempts=0, maxAttempts=5, range=20;
    char playAgain='y';

    printf("Welcome to the GUESSING GAME!\n");
    printf("Guess a number between 1 and %d.\n", range);

    while(playAgain == 'y'){
        srand(time(NULL));
        randomNumber = rand() % range + 1;

        while(attempts < maxAttempts){
            printf("Enter your guess: ");
            scanf("%d", &userGuess);

            if(userGuess == randomNumber){
                printf("Congratulations! You guessed the number in %d attempts.\n", attempts+1);
                break;
            } else if(userGuess < randomNumber){
                printf("Too low! Guess again.\n");
            } else {
                printf("Too high! Guess again.\n");
            }

            attempts++;
        }

        if(attempts == maxAttempts){
            printf("\nGame Over! You have used all your attempts.\n");
        }

        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &playAgain);

        if(playAgain != 'y'){
            printf("\nThank you for playing the GUESSING GAME. Goodbye!\n");
        } else {
            attempts = 0;
            printf("\nGuess a number between 1 and %d.\n", range);
        }
    }

    return 0;
}