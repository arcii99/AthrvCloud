//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int randomNumber;
    int guess;
    int attempts = 0;

    srand(time(0));
    randomNumber = rand() % 100 + 1;

    printf("Guess the random number between 1 and 100\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess < randomNumber) {
            printf("Your guess is too low. Try again.\n");
        } else if(guess > randomNumber) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while(guess != randomNumber);

    return 0;
}