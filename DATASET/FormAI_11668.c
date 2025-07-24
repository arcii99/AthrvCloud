//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int num1, num2, guess;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    do {
        // Generate two random numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Prompt user to guess the sum of the numbers
        printf("What is %d + %d? ", num1, num2);
        scanf("%d", &guess);

        // Calculate the correct sum and compare with user's guess
        if (guess == num1 + num2) {
            printf("Correct! You earned 10 points!\n");
            score += 10;
        }
        else {
            printf("Sorry, the correct answer is %d. You earned 0 points.\n", num1 + num2);
        }

        // Prompt user to play again
        printf("Play again? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display final score and exit
    printf("Thanks for playing! Your final score is %d.\n", score);
    return 0;
}