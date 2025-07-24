//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>

// Define the chess board as a 2D array of chars
char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

// Function to print the chess board
void print_board()
{
    printf("\n A B C D E F G H");
    for (int i = 0; i < 8; i++)
    {
        printf("\n%d", i + 1);
        for (int j = 0; j < 8; j++)
        {
            printf(" %c", board[i][j]);
        }
    }
    printf("\n\n");
}

// Function to move a piece on the board
void move_piece(int start_row, int start_col, int end_row, int end_col)
{
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
}

int main()
{
    printf("Initial chess board:\n");
    print_board();

    printf("Moving pawn from A2 to A4\n");
    move_piece(1, 0, 3, 0);
    print_board();

    printf("Moving knight from G8 to F6\n");
    move_piece(7, 6, 5, 5);
    print_board();

    printf("Moving bishop from F1 to C4\n");
    move_piece(0, 5, 3, 2);
    print_board();

    printf("Moving queen from D1 to E2\n");
    move_piece(0, 3, 1, 4);
    print_board();

    return 0;
}