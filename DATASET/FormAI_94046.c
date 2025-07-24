//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int main() {
    srand(time(NULL));
    int number = rand() % MAX_NUM + 1;
    int guess, num_guesses = 0;
    printf("I'm thinking of a number between 1 and %d. Can you guess what it is?\n", MAX_NUM);
    do {
        printf("Guess: ");
        scanf("%d", &guess);
        num_guesses++;
        if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        }
    } while (guess != number);
    printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
    return 0;
}