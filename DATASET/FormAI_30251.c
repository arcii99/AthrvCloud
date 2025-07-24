//FormAI DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int main() {

    int guess_count = 0;
    int guess;
    int is_game_over = 0;

    // Generate a random number
    srand(time(NULL));
    int number = rand() % MAX_NUMBER + 1;

    printf("I'm thinking of a number between 1 and %d. Can you guess what it is? You have 10 attempts.\n", MAX_NUMBER);

    // Keep asking for guesses until game is over
    while (!is_game_over) {

        // Get input from user
        printf("Guess #%d: ", guess_count + 1);
        scanf("%d", &guess);

        // Give feedback to user and check if guess is correct
        if (guess < number && guess_count < 9) {
            printf("Too low! Try again.\n");
        } else if (guess > number && guess_count < 9) {
            printf("Too high! Try again.\n");
        } else if (guess == number) {
            printf("Congratulations! You got it in %d attempts.\n", guess_count + 1);
            is_game_over = 1;
        } else {
            printf("Sorry, you didn't guess it in time. The number was %d.\n", number);
            is_game_over = 1;
        }

        // Increase the guess count
        guess_count++;
    }

    return 0;
}