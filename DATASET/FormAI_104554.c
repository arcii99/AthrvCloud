//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, randomNumber;
    int guessCount = 0;
    char response;
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;
    printf("Welcome to the number guessing game! \nTry to guess a number between 1 and 100.\n");
    while(1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guessCount++;
        if(guess < randomNumber) {
            printf("Too low, try again.\n");
        } else if(guess > randomNumber) {
            printf("Too high, try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempt%s. \n", guessCount, guessCount == 1 ? "" : "s");
            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &response);
            if(response == 'y') {
                guessCount = 0;
                randomNumber = rand() % 100 + 1;
                printf("Great! Let's play again.\n");
            } else {
                printf("Thanks for playing!\n");
                break;
            }
        }
    }
    return 0;
}