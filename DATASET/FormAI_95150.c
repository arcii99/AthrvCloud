//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESS 10

int main(void) {
    srand(time(NULL)); // Initialize random seed

    int num = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess;
    int tries = 0;

    printf("Guess a number between 1 and 100: ");

    do {
        scanf("%d", &guess);
        tries++;

        if(guess < num) {
            printf("Too low, try again: ");
        } else if(guess > num) {
            printf("Too high, try again: ");
        }
    } while(guess != num && tries < MAX_GUESS);

    if(guess == num) {
        printf("Congratulations, you guessed the number in %d tries!\n", tries);
    } else {
        printf("Sorry, you have used up all your attempts. The number was: %d\n", num);
    }

    return 0;
}