//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have 10 tries to guess the number.\n");
    srand(time(0));
    int num = rand() % 100 + 1;
    int guess, remaining = 10;
    do {
        printf("Guess #%d: ", 11 - remaining);
        scanf("%d", &guess);
        if (guess < num) {
            printf("Too low! ");
        } else if (guess > num) {
            printf("Too high! ");
        } else {
            printf("You got it! ");
            break;
        }
        printf("%d more %s.\n", --remaining, (remaining == 1) ? "try" : "tries");
    } while (remaining > 0);
    if (remaining == 0) {
        printf("You didn't guess the number - it was %d.\n", num);
    }
    return 0;
}