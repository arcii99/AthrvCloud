//FormAI DATASET v1.0 Category: Table Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l;
    int player1_score = 0, player2_score = 0;

    // Generate random numbers for each player
    srand(time(NULL));
    int player1[3], player2[3];
    for (i = 0; i < 3; i++)
    {
        player1[i] = rand() % 6 + 1;
        player2[i] = rand() % 6 + 1;
    }

    // Print the values of each player's numbers
    printf("Player 1:");
    for (i = 0; i < 3; i++)
        printf(" %d", player1[i]);
    printf("\n");

    printf("Player 2:");
    for (i = 0; i < 3; i++)
        printf(" %d", player2[i]);
    printf("\n");

    // Check for matches and add scores
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (player1[i] == player2[j])
            {
                player1_score += player1[i];
                player2_score += player2[j];
            }

    // Determine and display the winner
    if (player1_score > player2_score)
        printf("Player 1 wins with a score of %d!\n", player1_score);
    else if (player2_score > player1_score)
        printf("Player 2 wins with a score of %d!\n", player2_score);
    else
        printf("It's a tie!\n");

    return 0;
}