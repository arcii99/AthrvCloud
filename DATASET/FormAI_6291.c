//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int main()
{
    //Initialize the chess board
    int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
    //Set the seed for the random number generator
    srand(time(NULL));
    //Set the initial position of the knight
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;
    //Mark the initial position of the knight on the board
    board[row][col] = 1;

    //Possible knight moves
    int moves[8][2] = { {-2,-1},{-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1} };

    //Loop through 63 moves (8x8 board - 1 initial move)
    for (int i = 1; i < BOARD_SIZE * BOARD_SIZE; i++)
    {
        int valid_moves[8][2] = { 0 };
        int num_valid_moves = 0;

        //Check each possible move
        for (int j = 0; j < 8; j++)
        {
            int r = row + moves[j][0];
            int c = col + moves[j][1];

            //Check if the move is within the board
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE)
            {
                //Check if the move is not already made
                if (board[r][c] == 0)
                {
                    valid_moves[num_valid_moves][0] = r;
                    valid_moves[num_valid_moves][1] = c;
                    num_valid_moves++;
                }
            }
        }

        //Check if there are any valid moves available
        if (num_valid_moves > 0)
        {
            //Choose a random valid move
            int index = rand() % num_valid_moves;
            row = valid_moves[index][0];
            col = valid_moves[index][1];
            board[row][col] = i + 1;
        }
        else
        {
            //No valid moves available, exit the loop
            break;
        }
    }

    //Print the final board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}