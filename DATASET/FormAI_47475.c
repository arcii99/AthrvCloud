//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int score = 0; // Initialize the score to zero

    while (1) { // Loop infinitely until the player decides to quit
        int random_num = rand() % 100; // Generate a random number between 0 and 99
        int guess; // Initialize the variable to store the player's guess

        printf("Guess the number between 0 and 99:\n");
        scanf("%d", &guess); // Read the player's guess from stdin

        if (guess == random_num) { // If the guess is correct, increment the score
            score++;
            printf("You guessed the number correctly! Your score is now %d.\n", score);
        } else {
            printf("Sorry, that was not the correct number. The number was %d. Your final score is %d.\n", random_num, score);
            break; // Exit the loop
        }
    }

    return 0; // Exit the program
}