//FormAI DATASET v1.0 Category: Funny ; Style: excited
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    printf("Are you ready for some fun with C programming?\n");

    printf("Here's a fun challenge for you:\n");
    printf("Let's see if you can guess the randomly generated number between 1 and 100!\n");

    int the_number = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    do {
        printf("Take a guess (between 1 and 100): ");
        scanf("%d", &guess);

        if (guess < the_number) {
            printf("Too low, try again!\n");
        } else if (guess > the_number) {
            printf("Too high, try again!\n");
        } else {
            printf("You guessed it, congratulations!\n");
        }

        attempts++;
    } while (guess != the_number);

    printf("It took you %d attempts to guess the number.\n", attempts);
    printf("What do you think, was this program fun or what?\n");

    return 0;
}