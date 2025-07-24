//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randomNumber, guess;
    int counter = 0;

    srand(time(NULL));

    randomNumber = rand() % 100 + 1;

    printf("Try to guess the number between 1 to 100: ");

    do {
        scanf("%d", &guess);
        counter++;

        if (guess > randomNumber) {
            printf("Too high, try again: ");
        } else if (guess < randomNumber) {
            printf("Too low, try again: ");
        } else {
            printf("Congratulations, you guessed it in %d tries!", counter);
        }

    } while (guess != randomNumber);

    return 0;
}