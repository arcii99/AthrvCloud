//FormAI DATASET v1.0 Category: Chess engine ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board()
{
    // Initialize the board with empty squares
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }

    // Place the black pieces on the board
    board[0][0] = 'r';
    board[0][1] = 'n';
    board[0][2] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'b';
    board[0][6] = 'n';
    board[0][7] = 'r';

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        board[1][i] = 'p';
    }

    // Place the white pieces on the board
    board[7][0] = 'R';
    board[7][1] = 'N';
    board[7][2] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';
    board[7][5] = 'B';
    board[7][6] = 'N';
    board[7][7] = 'R';

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        board[6][i] = 'P';
    }
}

void print_board()
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    initialize_board();
    print_board();
    return 0;
}