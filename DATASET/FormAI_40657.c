//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, num, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;
    printf("Welcome to Mind-Bending Guessing game!\n");
    printf("The number is between 1 and 100.\n");
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num) {
            printf("Your guess is too high!\n");
        } else if (guess < num) {
            printf("Your guess is too low!\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
        }
    } while (guess != num);
    return 0;
}