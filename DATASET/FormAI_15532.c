//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int guess, number_of_guesses = 0, random_num, play_again = 1;
    srand(time(0));

    printf("Welcome to the happy number guessing game!\n\n");

    while(play_again) {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        random_num = rand() % 100 + 1;
        number_of_guesses++;

        while(guess != random_num) {
            if(guess > random_num) {
                printf("Too high! Try again: ");
            } else {
                printf("Too low! Try again: ");
            }
            scanf("%d", &guess);
            number_of_guesses++;
        }

        printf("Congratulations! You guessed the happy number in %d attempts.\n", number_of_guesses);

        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again);
        number_of_guesses = 0;
    }

    printf("Thanks for playing the happy number guessing game! Have a great day!\n");
    return 0;
}