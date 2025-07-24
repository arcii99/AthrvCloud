//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice()
{
    return rand() % 6 + 1;
}

int main()
{
    // Declare and initialize variables
    int player1_score = 0, player2_score = 0;
    int round = 1;

    // Seed the random number generator
    srand(time(NULL));

    // Display welcome message
    printf("Welcome to the C Table Game!\n\n");

    // Loop through five rounds
    while (round <= 5)
    {
        printf("Round %d:\n\n", round);

        // Player 1's turn
        printf("Player 1, press enter to roll the dice:");
        getchar();
        int roll1 = rollDice();
        printf("You rolled a %d!\n", roll1);
        player1_score += roll1;
        printf("Your total score is now %d.\n\n", player1_score);

        // Player 2's turn
        printf("Player 2, press enter to roll the dice:");
        getchar();
        int roll2 = rollDice();
        printf("You rolled a %d!\n", roll2);
        player2_score += roll2;
        printf("Your total score is now %d.\n\n", player2_score);

        // Increment the round counter
        round++;
    }

    // Determine the winner
    printf("The game is over!\n\n");
    if (player1_score > player2_score)
    {
        printf("Player 1 wins with a score of %d!\n", player1_score);
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 wins with a score of %d!\n", player2_score);
    }
    else
    {
        printf("It's a tie with a score of %d!\n", player1_score);
    }

    return 0;
}