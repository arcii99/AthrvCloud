//FormAI DATASET v1.0 Category: Chess engine ; Style: optimized
#include <stdio.h>

// Define the chess board size
#define BOARD_SIZE 8

// Define the pieces on the chess board
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Define the colors of the chess pieces
#define WHITE 0
#define BLACK 1

// Define the starting position of each piece on the board
int starting_piece_positions[2][7][2] = {
    {
        {1, 0},  // Pawn
        {0, 1},  // Knight
        {0, 2},  // Bishop
        {0, 3},  // Rook
        {0, 4},  // Queen
        {0, 5},  // King
    },
    {
        {6, 0},  // Pawn
        {7, 1},  // Knight
        {7, 2},  // Bishop
        {7, 3},  // Rook
        {7, 4},  // Queen
        {7, 5},  // King
    }
};

// Define a function to initialize the board
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    
    // Set the board to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    
    // Add the pieces to the board
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 7; j++) {
            board[starting_piece_positions[i][j][0]][starting_piece_positions[i][j][1]] = j + 1;
        }
    }
}

// Define a function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    
    printf("  ");
    
    // Print the column headers
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    
    printf("\n");
    
    // Print the rows
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case PAWN:
                    printf("P ");
                    break;
                case KNIGHT:
                    printf("N ");
                    break;
                case BISHOP:
                    printf("B ");
                    break;
                case ROOK:
                    printf("R ");
                    break;
                case QUEEN:
                    printf("Q ");
                    break;
                case KING:
                    printf("K ");
                    break;
            }
        }
        
        printf("%d\n", BOARD_SIZE - i);
    }
    
    printf("  ");
    
    // Print the column headers
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    
    printf("\n");
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    
    // Initialize the board
    initialize_board(board);
    
    // Print the board
    print_board(board);
    
    return 0;
}