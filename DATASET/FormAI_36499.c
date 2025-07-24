//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, guess, attempts = 0;
    srand(time(NULL));
    num = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Can you guess it in less than 10 attempts?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > num)
            printf("Too high!\n");
        else if (guess < num)
            printf("Too low!\n");
        else {
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
            break;
        }

    } while (attempts < 10);

    if (attempts >= 10) {
        printf("Sorry, you have used all 10 attempts.\n");
        printf("The number was %d.\n", num);
    }

    return 0;
}