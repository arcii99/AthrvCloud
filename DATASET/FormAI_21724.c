//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Helper function to print the current state of the board
void print_board(char board[][BOARD_SIZE])
{
    printf("\n   A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
        {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
        {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
        {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '}
    };

    // Print the starting position of the board
    print_board(board);

    // Game loop
    int turn = 1; // red goes first
    while (1) {
        // Get input from the current player
        int start_row, start_col, end_row, end_col;
        printf("\nPlayer %s's turn.\n", turn % 2 == 1 ? "red" : "black");
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter the row and column of the square where you want to move the piece: ");
        scanf("%d %d", &end_row, &end_col);

        // Check if the move is valid
        char piece = board[start_row-1][start_col-1];
        int is_valid_move = 0;
        if (piece == 'r' || piece == 'R') {
            // Red piece
            if (turn % 2 == 1) {
                // Red's turn
                if (board[end_row-1][end_col-1] == ' ') {
                    // Check if the move is diagonal
                    if (start_row - end_row == 1 && abs(start_col - end_col) == 1) {
                        is_valid_move = 1;
                    } else if (start_row - end_row == 2 && abs(start_col - end_col) == 2 &&
                               board[(start_row+end_row)/2-1][(start_col+end_col)/2-1] == 'b') {
                        // Check if the move captures a black piece
                        board[(start_row+end_row)/2-1][(start_col+end_col)/2-1] = ' ';
                        is_valid_move = 1;
                    }
                }
                // Check if the piece can be crowned
                if (piece == 'r' && end_row == 1) {
                    piece = 'R';
                    is_valid_move = 1;
                }
            }
        } else if (piece == 'b' || piece == 'B') {
            // Black piece
            if (turn % 2 == 0) {
                // Black's turn
                if (board[end_row-1][end_col-1] == ' ') {
                    // Check if the move is diagonal
                    if (end_row - start_row == 1 && abs(start_col - end_col) == 1) {
                        is_valid_move = 1;
                    } else if (end_row - start_row == 2 && abs(start_col - end_col) == 2 &&
                               board[(start_row+end_row)/2-1][(start_col+end_col)/2-1] == 'r') {
                        // Check if the move captures a red piece
                        board[(start_row+end_row)/2-1][(start_col+end_col)/2-1] = ' ';
                        is_valid_move = 1;
                    }
                }
                // Check if the piece can be crowned
                if (piece == 'b' && end_row == BOARD_SIZE) {
                    piece = 'B';
                    is_valid_move = 1;
                }
            }
        }

        // Make the move if it is valid
        if (is_valid_move) {
            board[start_row-1][start_col-1] = ' ';
            board[end_row-1][end_col-1] = piece;
            print_board(board);
            turn++;
        } else {
            printf("\nInvalid move, please try again.\n");
        }
    }

    return 0;
}