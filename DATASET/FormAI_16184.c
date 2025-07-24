//FormAI DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>

int main()
{
    int board[8][8] = {0}, i, j, turn = 1, x, y, x1, y1, count, winner = 0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i+j)%2 == 0) // Making the checkers board pattern
            {
                board[i][j] = -1;
            }
            else if(i<3)
            {
                board[i][j] = 2; // Player 2's checker piece
            }
            else if(i>4)
            {
                board[i][j] = 1; // Player 1's checker piece
            }
        }
    }
    while(!winner)
    {
        printf("\n");
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j] == -1)
                {
                    printf("  "); // Printing empty spot
                }
                else
                {
                    printf("%d ", board[i][j]); // Printing checker piece
                }
            }
            printf("\n");
        }
        printf("\nPlayer %d's turn\nEnter the coordinates of the piece you want to move (x y): ", turn);
        scanf("%d %d", &x, &y);
        count = 0;
        while(count<=0)
        {
            if((turn == 1 && board[x][y] == 1) || (turn == 2 && board[x][y] == 2)) // Validating player's turn and checker piece
            {
                count++;
            }
            else
            {
                printf("Invalid move, please enter a valid checker piece (x y): ");
                scanf("%d %d", &x, &y);
            }
        }
        count = 0;
        while(count<=0)
        {
            printf("Enter the coordinates of the spot you want to move to (x y): ");
            scanf("%d %d", &x1, &y1);
            if(board[x1][y1] != -1) // Validating empty spot
            {
                printf("Invalid move, please enter an empty spot (x y): ");
                continue;
            }
            if(turn == 1 && (x1-x == 1) && (y1-y == 1 || y1-y == -1)) // Validating Player 1's move
            {
                board[x1][y1] = 1;
                board[x][y] = -1;
                count++;
            }
            else if(turn == 2 && (x-x1 == 1) && (y1-y == 1 || y1-y == -1)) // Validating Player 2's move
            {
                board[x1][y1] = 2;
                board[x][y] = -1;
                count++;
            }
            else
            {
                printf("Invalid move, please enter a valid move (x y): ");
            }
            if(board[x][y] == 1 && x1 == 7) // Checking if Player 1 has won
            {
                winner = 1;
                printf("\nPlayer 1 has won!\n");
                break;
            }
            else if(board[x][y] == 2 && x1 == 0) // Checking if Player 2 has won
            {
                winner = 1;
                printf("\nPlayer 2 has won!\n");
                break;
            }
        }
        if(turn == 1)
        {
            turn = 2; // Changing turn to Player 2
        }
        else
        {
            turn = 1; // Changing turn to Player 1
        }
    }
    return 0;
}