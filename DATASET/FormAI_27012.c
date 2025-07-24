//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to clear the screen */
void clear()
{
    system("clear");
}

int main()
{
    int score = 0; // Initializing score variable to keep track of the points
    char choice; // Initializing variable to store user's choice in the game
    srand(time(NULL)); // Initializing random seed

    while (1) { // Loop to keep the game running until user chooses to quit
        clear(); // Clearing the screen
        printf("Welcome to the Guessing Game\n\n");
        printf("Your current score is: %d\n\n", score);

        /* Generating a random number */
        int rand_num = rand() % 10 + 1;
        int guess;

        printf("Please guess a number between 1 and 10: ");
        scanf("%d", &guess);

        /* Checking if the guess is correct or not */
        if (guess == rand_num) {
            printf("\nCongratulations! Your guess is correct.\n");
            score += 10; // Adding 10 points to the score
        } else {
            printf("\nSorry, your guess is incorrect. The correct number is %d.\n", rand_num);
            score -= 5; // Subtracting 5 points from the score
        }

        printf("\n\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n')
            break; // Breaking the loop if user chooses to quit
    }

    printf("\n\nThanks for playing! Your final score is: %d\n", score);

    return 0;
}