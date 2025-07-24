//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Initialize variables
    int totalScore[2] = {0}; // Total score for each player
    int currentScore;        // Current score for each turn
    int currentPlayer = 0;   // Current player (0 or 1)
    int roundNumber = 1;     // Current round number (1 to 5)

    // Welcome message
    printf("Welcome to Curious Cup Table Game!\n\n");

    // Game instructions
    printf("Instructions:\n");
    printf("Each round, players take turns rolling a cup on a table.\n");
    printf("The cup will stop at a random number between 1 and 6.\n");
    printf("The player with the highest total score after 5 rounds wins!\n\n");

    // Start the game
    printf("Let's start the game!\n\n");

    // Loop through 5 rounds
    while (roundNumber <= 5)
    {
        printf("Round %d\n", roundNumber);

        // Loop through each turn
        for (int turn = 1; turn <= 2; turn++)
        {
            printf("Player %d's turn\n", turn);

            // Roll the cup and generate a random number
            int numRolled = generateRandomNumber(1, 6);
            printf("The cup landed on: %d\n", numRolled);

            // Add the current score to the total score
            currentScore = numRolled;
            totalScore[turn - 1] += currentScore;

            // Display the total score for the player
            printf("Player %d's total score: %d\n\n", turn, totalScore[turn - 1]);

            // Check if the game is over
            if (roundNumber == 5 && turn == 2)
            {
                printf("The game has ended!\n\n");

                // Determine the winner
                if (totalScore[0] > totalScore[1])
                {
                    printf("Player 1 wins with a total score of %d!\n", totalScore[0]);
                }
                else if (totalScore[1] > totalScore[0])
                {
                    printf("Player 2 wins with a total score of %d!\n", totalScore[1]);
                }
                else
                {
                    printf("It's a tie! Both players have a total score of %d.\n", totalScore[0]);
                }

                // End the game
                return 0;
            }
        }

        // Increase the round number
        roundNumber++;
    }

    // End the game
    return 0;
}