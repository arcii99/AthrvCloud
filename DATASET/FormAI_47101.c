//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("*** Welcome to the Guessing Game! ***\n");
    printf("Guess a number between 1 and 100: ");
    do {
        scanf("%d", &guess);
        tries++;
        if (guess > num)
            printf("Too high! Guess again: ");
        else if (guess < num)
            printf("Too low! Guess again: ");
        else
            printf("Congratulations, you guessed the number in %d tries!", tries);
    } while (guess != num);
    return 0;
}