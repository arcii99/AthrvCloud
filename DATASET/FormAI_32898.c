//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char guess;
    int num, tries = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is in 7 tries or less?\n");
    while (tries < 7) {
        printf("Guess a number: ");
        scanf(" %c", &guess);
        if (!isdigit(guess)) {
            printf("That is not a valid number. Try again.\n");
            continue;
        }
        if (guess == num) {
            printf("Congratulations! You guessed the number in %d tries.\n", tries + 1);
            return 0;
        }
        else if (guess < num) {
            printf("Too low. Guess again.\n");
        }
        else {
            printf("Too high. Guess again.\n");
        }
        tries++;
    }
    printf("Sorry, you did not guess the number. It was %d.\n", num);
    return 0;
}