//FormAI DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, randint, attempts = 0;
    srand(time(0));
    randint = rand() % 100 + 1;
    printf("Guess a number between 1 and 100.\n");
    do {
        scanf("%d", &guess);
        attempts++;
        if(guess < randint) {
            printf("Your guess is too low. Try again.\n");
        } else if(guess > randint) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts);
        }
    } while(guess != randint);
    return 0;
}