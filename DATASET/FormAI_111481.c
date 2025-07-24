//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, random_number, attempts = 1;
    srand(time(0));
    random_number = rand() % 100 + 1; // generate random number between 1 and 100

    printf("Guess the number between 1 and 100:\n");

    do {
        scanf("%d", &guess);
        if (guess > random_number) {
            printf("Too high, try again.\n");
            attempts++;
        } else if (guess < random_number) {
            printf("Too low, try again.\n");
            attempts++;
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != random_number);

    return 0;
}