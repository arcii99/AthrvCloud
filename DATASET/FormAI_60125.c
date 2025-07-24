//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll the dice
int rollDice(void)
{
    int dice1 = rand() % 6 + 1; // generate random number between 1 and 6 for dice 1
    int dice2 = rand() % 6 + 1; // generate random number between 1 and 6 for dice 2
    return dice1 + dice2; // return the sum of the two dice
}

int main()
{
    printf("\nWelcome to the C Table Game!\n\n");

    // initialize the variables
    int playerScore = 0, computerScore = 0;
    char choice;

    // loop while both players' scores are less than 100
    while (playerScore < 100 && computerScore < 100)
    {
        printf("Press any key to roll the dice... ");
        fflush(stdout); // flush the output buffer to ensure prompt message is displayed
        getchar(); // read the input character (any key)

        // player's turn
        int playerRoll = rollDice(); // roll the dice
        playerScore += playerRoll; // update the player's score
        printf("\nYou rolled %d and your current score is %d.\n", playerRoll, playerScore);

        // if the player's score is less than 100, allow computer to take its turn
        if (playerScore < 100)
        {
            // computer's turn
            int computerRoll = rollDice(); // roll the dice
            computerScore += computerRoll; // update the computer's score
            printf("The computer rolled %d and its current score is %d.\n\n", computerRoll, computerScore);
        }
    }

    // determine the winner
    if (playerScore >= 100)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("Sorry, the computer won. Better luck next time!\n");
    }

    return 0;
}