//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_guess, random_number;
    int number_of_guesses = 0;
    time_t t;
    srand((unsigned) time(&t)); /* seed random number generator */

    random_number = rand() % 100 + 1; /* random number between 1 and 100 */

    printf("Can you guess the number between 1 and 100?\n");

    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &user_guess);
        number_of_guesses++;

        if (user_guess > random_number) {
            printf("Your guess was too high. Try again.\n");
        } else if (user_guess < random_number) {
            printf("Your guess was too low. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d guesses.\n", number_of_guesses);
        }
    } while (user_guess != random_number);

    return 0;
}