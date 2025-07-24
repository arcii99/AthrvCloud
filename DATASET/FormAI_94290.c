//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, randomNumber, guess, attempts = 0;

    printf("Hello, what's your name? ");
    scanf("%s", name);

    printf("Welcome %s, how old are you? ", name);
    scanf("%d", &age);

    printf("Great, let's play a game!\nI'm thinking of a number between 1 and 100. You have 5 attempts to guess it.\n");

    srand(time(0));
    randomNumber = rand() % 100 + 1;

    while (attempts < 5) {
        printf("Guess #%d: ", attempts+1);
        scanf("%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid guess! Your guess should be between 1 and 100.\n");
            continue;
        }

        if (guess == randomNumber) {
            printf("Congratulations, you guessed the number in %d attempt%s!\n", attempts+1, attempts > 0 ? "s" : "");
            break;
        } else if (guess < randomNumber) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }

        attempts++;
    }

    if (attempts >= 5) {
        printf("Sorry, you couldn't guess the number in 5 attempts. The number was %d.\n", randomNumber);
    }

    printf("Thank you for playing, %s. Goodbye!\n", name);

    return 0;
}