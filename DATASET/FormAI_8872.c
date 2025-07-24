//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include<stdio.h>

int main()
{
    int player1, player2, i, n1, n2;

    //Getting inputs from the players
    printf("Player 1, enter a number: ");
    scanf("%d", &n1);
    printf("Player 2, enter a number: ");
    scanf("%d", &n2);
  
    //Bitwise operation between the two numbers
    player1 = n1 & n2;
    player2 = n1 ^ n2;

    //Displaying the result to the players
    printf("\n\nResult after bitwise operation:\n");
    printf("Player 1: %d\n", player1);
    printf("Player 2: %d\n", player2);

    //Checking who won the game
    if (player1 > player2)
    {
        printf("\n\nPlayer 1 won the game!!");
    }
    else if (player2 > player1)
    {
        printf("\n\nPlayer 2 won the game!!");
    }
    else
    {
        printf("\n\nIt's a tie!");
    }

    return 0;
}