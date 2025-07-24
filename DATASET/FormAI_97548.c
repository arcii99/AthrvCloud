//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, tries = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;
    printf("Welcome to 'Guess the Number'!\n");
    do {
        printf("Enter a guess between 1 and 100: ");
        scanf("%d", &guess);
        tries++;
        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("You got it in %d tries!\n", tries);
        }
    } while (guess != number);
    return 0;
}