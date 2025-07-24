//FormAI DATASET v1.0 Category: Random ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number_of_guesses = 0, random_num;
    srand(time(0));
    random_num = rand() % 100 + 1; // generates random number between 1 and 100
    printf("Welcome to the random number guessing game!\n");

    do {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        number_of_guesses++; // increment the number of guesses

        if (guess > random_num) {
            printf("Too high! Try again.\n");
        } else if (guess < random_num) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations, you guessed the correct number in %d tries!\n", number_of_guesses);
        }
    } while (guess != random_num);

    return 0;
}