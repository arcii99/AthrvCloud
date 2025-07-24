//FormAI DATASET v1.0 Category: Table Game ; Style: Claude Shannon
// A Table Game Example Program in Claude Shannon Style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1_score = 0, player2_score = 0; // initialize player scores to 0
    int rounds = 5; // set number of rounds to play

    srand(time(0)); // seed random number generator with current time
    
    printf("Welcome to the Table Game!\n");
    printf("Objective: Roll a higher number than your opponent to score a point.\n\n");

    for(int i = 1; i <= rounds; i++)
    {
        printf("Round %d:\n", i);
        printf("Player 1: Press enter to roll the dice...\n");
        getchar(); // wait for player to press enter
        int roll1 = rand() % 6 + 1; // random number from 1 to 6
        printf("You rolled a %d!\n", roll1);

        printf("Player 2: Press enter to roll the dice...\n");
        getchar(); // wait for player to press enter
        int roll2 = rand() % 6 + 1; // random number from 1 to 6
        printf("You rolled a %d!\n", roll2);

        if (roll1 > roll2)
        {
            player1_score++;
            printf("Player 1 wins this round!\n\n");
        }
        else if (roll2 > roll1)
        {
            player2_score++;
            printf("Player 2 wins this round!\n\n");
        }
        else
        {
            printf("It's a tie!\n\n");
        }
    }

    printf("Game over!\n");
    printf("Final scores:\n");
    printf("Player 1: %d\n", player1_score);
    printf("Player 2: %d\n", player2_score);

    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}