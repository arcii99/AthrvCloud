//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialises random seed
    int guess, number = rand() % 100 + 1; // selects random number between 1 and 100
    int count = 0;

    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Guess #%d: ", count+1);
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too high. Guess again.\n");
        } else if (guess < number) {
            printf("Too low. Guess again.\n");
        }

        count++;
    } while (guess != number && count < 10);

    if (guess == number) {
        printf("Congratulations! You guessed the number in %d tries.\n", count);
    } else {
        printf("Sorry, you did not guess the number in time. The number was %d.\n", number);
    }

    return 0;
}