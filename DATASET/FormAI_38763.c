//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, guess, num, attempts = 5;
    srand(time(0));
    num = rand() % 10 + 1;
    printf("Welcome to the Random Number Game!\n");
    printf("You have %d attempts to guess a number between 1 and 10\n", attempts);

    for (i = 0; i < attempts; i++) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess == num) {
            printf("Congratulations, you guessed the number in %d attempts!\n", i+1);
            break;
        }
        else if (i+1 == attempts) {
            printf("Sorry, you did not guess the number. The number was %d\n", num);
        }
        else {
            printf("Sorry, that was incorrect. You have %d attempts left\n", attempts - i - 1);
        }
    }
    return 0;
}