//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8 // checkers board size
#define EMPTY ' ' // represent empty space on the board
#define RED 'r' // represent red player's pieces
#define BLACK 'b' // represent black player's pieces

// function to initialize the board
void init_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if((i + j) % 2 == 0) // empty spaces on even squares
            {
                board[i][j] = EMPTY;
            }
            else if(i < 3) // red pieces on top 3 rows
            {
                board[i][j] = RED;
            }
            else if(i >= 5) // black pieces on bottom 3 rows
            {
                board[i][j] = BLACK;
            }
            else // empty middle rows
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

// function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    printf("   0 1 2 3 4 5 6 7\n");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i);
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to determine if a move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col, char player)
{
    int move_row = end_row - start_row;
    int move_col = end_col - start_col;
    if(move_row == 0 || move_col == 0) // diagonal move check
    {
        return 0;
    }
    if(abs(move_row) != abs(move_col)) // moving diagonally
    {
        return 0;
    }
    if(board[end_row][end_col] != EMPTY) // check if end space is empty
    {
        return 0;
    }
    if(player == RED)
    {
        if(board[start_row][start_col] == RED || board[start_row][start_col] == 'R')
        {
            if(move_row < 0) // red pieces only move up the board
            {
                return 0;
            }
            if(abs(move_row) > 2 || abs(move_col) > 2) // check jump moves
            {
                return 0;
            }
            if(abs(move_row) == 2 && abs(move_col) == 2) // check if jumping over an opposing piece
            {
                int mid_row = (start_row + end_row) / 2;
                int mid_col = (start_col + end_col) / 2;
                if(board[mid_row][mid_col] != BLACK && board[mid_row][mid_col] != 'B')
                {
                    return 0;
                }
            }
            return 1;
        }
    }
    else if(player == BLACK)
    {
        if(board[start_row][start_col] == BLACK || board[start_row][start_col] == 'B')
        {
            if(move_row > 0) // black pieces only move down the board
            {
                return 0;
            }
            if(abs(move_row) > 2 || abs(move_col) > 2) // check jump moves
            {
                return 0;
            }
            if(abs(move_row) == 2 && abs(move_col) == 2) // check if jumping over an opposing piece
            {
                int mid_row = (start_row + end_row) / 2;
                int mid_col = (start_col + end_col) / 2;
                if(board[mid_row][mid_col] != RED && board[mid_row][mid_col] != 'R')
                {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

// function to make a move
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col)
{
    char piece = board[start_row][start_col];
    board[start_row][start_col] = EMPTY;
    board[end_row][end_col] = piece;
    if(abs(end_row - start_row) == 2 && abs(end_col - start_col) == 2) // if jumping over a piece, remove it
    {
        int mid_row = (end_row + start_row) / 2;
        int mid_col = (end_col + start_col) / 2;
        board[mid_row][mid_col] = EMPTY;
    }
}

// function to promote a piece to a king
void promote_to_king(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    if(board[row][col] == RED && row == 0)
    {
        board[row][col] = 'R';
    }
    else if(board[row][col] == BLACK && row == BOARD_SIZE - 1)
    {
        board[row][col] = 'B';
    }
}

// function to check if a player has any valid moves left
int has_valid_moves(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    int i, j, k, l;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == player || board[i][j] == player + 32)
            {
                for(k = -2; k <= 2; k++)
                {
                    for(l = -2; l <= 2; l++)
                    {
                        int end_row = i + k;
                        int end_col = j + l;
                        if(end_row >= 0 && end_row < BOARD_SIZE && end_col >= 0 && end_col < BOARD_SIZE)
                        {
                            if(is_valid_move(board, i, j, end_row, end_col, player))
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// main function
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    char player = RED; // red player goes first
    while(1)
    {
        printf("\n\n");
        print_board(board);
        if(!has_valid_moves(board, player))
        {
            if(player == RED)
            {
                printf("Black wins!\n");
            }
            else
            {
                printf("Red wins!\n");
            }
            break;
        }
        int start_row, start_col, end_row, end_col;
        printf("%c player's turn\n", player);
        printf("Enter piece's row and column: ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter destination row and column: ");
        scanf("%d %d", &end_row, &end_col);
        if(is_valid_move(board, start_row, start_col, end_row, end_col, player))
        {
            make_move(board, start_row, start_col, end_row, end_col);
            if(player == RED && end_row == 0)
            {
                promote_to_king(board, end_row, end_col);
            }
            else if(player == BLACK && end_row == BOARD_SIZE - 1)
            {
                promote_to_king(board, end_row, end_col);
            }
            if(player == RED)
            {
                player = BLACK;
            }
            else
            {
                player = RED;
            }
        }
        else
        {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;
}