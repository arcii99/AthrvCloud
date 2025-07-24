//FormAI DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, guessCount = 0;
    srand(time(0));
    randomNumber = rand() % 100 + 1;
    printf("***Let's Play Guessing Game***\n\n");
    printf("Guess a number between 1 and 100: ");
    do {
        scanf("%d", &guess);
        guessCount++;
        if(guess > randomNumber) {
            printf("You guessed too high! Try again: ");
        } else if(guess < randomNumber) {
            printf("You guessed too low! Try again: ");
        } else {
            printf("\nCongratulations! You won in %d attempts.\n", guessCount);
        }
    } while(guess != randomNumber);

    printf("\nThanks for playing the Guessing Game!");
    return 0;
}