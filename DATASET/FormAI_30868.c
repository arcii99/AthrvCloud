//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("I have a number between 1 and 100.\n");
    printf("Can you guess the number? You have 10 tries.\n");
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num) {
            printf("Too high! Try again.\n");
        } else if (guess < num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries!\n", tries);
            break;
        }
    } while (tries < 10);
    if (tries == 10) {
        printf("Sorry, you didn't guess the number in 10 tries.\n");
        printf("The number was %d.\n", num);
    }
    return 0;
}