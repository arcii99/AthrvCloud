//FormAI DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1 = 0, player2 = 0; //initially, both players have a score of 0
    int rounds = 1;
    printf("\nWelcome to the Cyberpunk C Table Game example!\n");
    printf("Player 1 starts!\n");
    srand(time(NULL));

    while (player1 < 100 && player2 < 100)
    {
        int p1_roll = (rand() % 6) + 1; //random number between 1 and 6
        int p2_roll = (rand() % 6) + 1;
        printf("\n\nRound %d\n", rounds++);
        printf("Player 1: %d\n", player1);
        printf("Player 2: %d\n", player2);
        printf("Player 1 rolls the dice...\n");
        printf("Player 1: %d\n", p1_roll);
        printf("Player 2 rolls the dice...\n");
        printf("Player 2: %d\n", p2_roll);

        if (p1_roll > p2_roll)
        {
            printf("Player 1 wins this round!\n");
            player1 += p1_roll;
        }
        else if (p2_roll > p1_roll)
        {
            printf("Player 2 wins this round!\n");
            player2 += p2_roll;
        }
        else
        {
            printf("It's a tie!\n");
        }
    }

    if (player1 >= 100)
    {
        printf("\n\nPlayer 1 wins the game with a score of %d!\n", player1);
    }
    else
    {
        printf("\n\nPlayer 2 wins the game with a score of %d!\n", player2);
    }

    return 0;
}