//FormAI DATASET v1.0 Category: Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function to generate a random number within the given range*/
int generate_random_number(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

/*Main program*/
int main() {
    int num;
    int guess;
    int attempts = 0;
    int max_attempts = 10;
    int min = 1;
    int max = 100;

    /*Seed the random number generator*/
    srand(time(0));

    /*Generate a random number for the player to guess*/
    num = generate_random_number(min, max);

    /*Keep asking for guesses until the player guesses correctly or runs out of attempts*/
    while (1) {
        printf("Guess the number between %d and %d:\n", min, max);
        scanf("%d", &guess);

        attempts++;

        if (guess == num) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (attempts == max_attempts) {
            printf("Sorry, you have run out of attempts. The number was %d.\n", num);
            break;
        } else if (guess < num) {
            printf("Too low! Guess again.\n");
        } else if (guess > num) {
            printf("Too high! Guess again.\n");
        }
    }

    return 0;
}