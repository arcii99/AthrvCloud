//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>

typedef enum {EMPTY, BLACK, WHITE} Piece; // define piece types

// define constant values for the board's size and the number of pieces
#define BOARD_SIZE 8
#define NUM_PIECES 12

// define function that initializes the game board with empty spaces
void initialize_board(Piece board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

// define function that prints the current game board
void print_board(Piece board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch(board[i][j])
            {
                case EMPTY:
                    printf(". ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case WHITE:
                    printf("W ");
                    break;
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

int main()
{
    Piece board[BOARD_SIZE][BOARD_SIZE]; // initialize game board
    initialize_board(board); // set board to empty spaces
    print_board(board); // print initial board
    
    Piece black_pieces[NUM_PIECES] = {BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};
    Piece white_pieces[NUM_PIECES] = {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
    
    // place initial black pieces on the board
    board[0][1] = black_pieces[0];
    board[0][3] = black_pieces[1];
    board[0][5] = black_pieces[2];
    board[0][7] = black_pieces[3];
    board[1][0] = black_pieces[4];
    board[1][2] = black_pieces[5];
    board[1][4] = black_pieces[6];
    board[1][6] = black_pieces[7];
    board[2][1] = black_pieces[8];
    board[2][3] = black_pieces[9];
    board[2][5] = black_pieces[10];
    board[2][7] = black_pieces[11];
    
    // place initial white pieces on the board
    board[5][0] = white_pieces[0];
    board[5][2] = white_pieces[1];
    board[5][4] = white_pieces[2];
    board[5][6] = white_pieces[3];
    board[6][1] = white_pieces[4];
    board[6][3] = white_pieces[5];
    board[6][5] = white_pieces[6];
    board[6][7] = white_pieces[7];
    board[7][0] = white_pieces[8];
    board[7][2] = white_pieces[9];
    board[7][4] = white_pieces[10];
    board[7][6] = white_pieces[11];
    
    print_board(board); // print board with initial position of pieces
    
    return 0;
}