//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int difficulty, guess, num, guessCount = 0;
    char playAgain = 'y';
    srand(time(NULL));
    printf("Welcome to the Guess the Number game!\n");
    printf("Please select difficulty level (1-5): ");
    scanf("%d", &difficulty);

    while(playAgain == 'y') {
        num = (rand() % (10 * difficulty)) + 1; // Generate a random number
        printf("I'm thinking of a number between 1 and %d. Can you guess what it is?\n", 10 * difficulty);
        do {
            printf("Guess #%d: ", guessCount + 1);
            scanf("%d", &guess);
            guessCount++;
            if(guess < num) {
                printf("Too low! ");
                if(num-guess < 3) {
                    printf("But you're getting warm!\n");
                } else if(num-guess > (difficulty*2)) {
                    printf("Not even close!\n");
                } else {
                    printf("Keep trying!\n");
                }
            }
            else if(guess > num) {
                printf("Too high! ");
                if(guess-num < 3) {
                    printf("But you're getting warm!\n");
                } else if(guess-num > (difficulty*2)) {
                    printf("Not even close!\n");
                } else {
                    printf("Keep trying!\n");
                }
            }
        } while(guess != num);
        printf("Congratulations! You guessed it in %d tries!\n", guessCount);
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        guessCount = 0;
    }

    printf("Thank you for playing Guess the Number!\n");
    return 0;
}