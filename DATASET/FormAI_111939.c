//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_num, guess, num_guesses = 0;
    srand(time(0));
    secret_num = (rand() % 100) + 1;
    printf("Welcome to the guessing game! I'm thinking of a number between 1 and 100.\n");

    while(1) {
        printf("Guess a number: ");
        scanf("%d", &guess);
        num_guesses++;

        if(guess == secret_num) {
            printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
            break;
        }
        else if(guess < secret_num) {
            printf("Too low! Guess again.\n");
        }
        else {
            printf("Too high! Guess again.\n");
        }

        if(num_guesses == 10) {
            printf("Sorry, you have used all 10 guesses. The secret number was %d.\n", secret_num);
            break;
        }
    }

    return 0;
}