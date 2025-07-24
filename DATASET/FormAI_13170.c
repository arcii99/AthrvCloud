//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int rollDice();
void printStatus(int player, int score);
void playGame();

int main()
{
    // seed the random number generator
    srand(time(NULL));

    // print game title
    printf("\n=== WELCOME TO C TABLE GAME ===\n\n");

    // start the game
    playGame();

    return 0;
}

/**
 * Simulates the roll of two dice and returns their sum.
 */
int rollDice()
{
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

/**
 * Prints the status of the game.
 */
void printStatus(int player, int score)
{
    printf("Player %d | Score: %d\n", player, score);
}

/**
 * Plays the game.
 */
void playGame()
{
    // set initial values
    int player1Score = 0;
    int player2Score = 0;
    int currentPlayer = 1;

    // loop until one player reaches 100 points
    while (player1Score < 100 && player2Score < 100)
    {
        // display status
        printf("\n");
        printStatus(1, player1Score);
        printStatus(2, player2Score);

        // prompt current player to roll dice
        printf("\nPlayer %d, press Enter to roll dice...", currentPlayer);
        getchar();

        // roll dice and update score
        int roll = rollDice();
        if (currentPlayer == 1)
        {
            player1Score += roll;
        }
        else
        {
            player2Score += roll;
        }

        // check for special cases
        if (roll == 12)
        {
            // player loses all points and forfeits turn
            printf("\nOh no! Player %d rolled a 12 and loses all points!\n", currentPlayer);
            if (currentPlayer == 1)
            {
                player1Score = 0;
            }
            else
            {
                player2Score = 0;
            }
        }
        else if (roll % 2 == 0)
        {
            // player gains an extra turn
            printf("\nPlayer %d rolled an even number and gets an extra turn!\n", currentPlayer);
        }
        else
        {
            // switch players
            currentPlayer = 3 - currentPlayer;
        }
    }

    // print winner
    printf("\n");
    if (player1Score >= 100)
    {
        printf("Player 1 Wins!\n");
    }
    else
    {
        printf("Player 2 Wins!\n");
    }
}