//FormAI DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

// Function to print the chess board with current positions of pieces
void print_board(char board[N][N]) {
    printf("\n  ");
    for (int i = 0; i < N; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%d|", i);
        for (int j = 0; j < N; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid or not
int is_valid(char board[N][N], int start_row, int start_col, int end_row, int end_col) {
    // Check if the start position contains a piece
    if (board[start_row][start_col] == ' ') {
        return 0;
    }

    // Check if the end position is on the board
    if (end_row > 7 || end_row < 0 || end_col > 7 || end_col < 0) {
        return 0;
    }

    // Check if the end position contains a friendly piece
    if (board[end_row][end_col] == board[start_row][start_col]) {
        return 0;
    }

    // Check if the move is valid based on the type of piece
    switch (board[start_row][start_col]) {
        case 'P':
            // Check if the pawn moves forward
            if (start_col == end_col && board[end_row][end_col] == ' ') {
                if (start_row == 1 && end_row == 3 && board[2][end_col] == ' ') {
                    return 1;
                }
                if (start_row == end_row - 1) {
                    return 1;
                }
            }

            // Check if the pawn captures diagonally
            if (abs(end_col - start_col) == 1 && end_row == start_row + 1 && 
                board[end_row][end_col] != ' ' && board[end_row][end_col] != board[start_row][start_col]) {
                return 1;
            }
            break;

        case 'R':
            // Check if the rook moves horizontally or vertically
            if (start_row == end_row) {
                int min_col = (start_col < end_col) ? start_col : end_col;
                int max_col = (start_col > end_col) ? start_col : end_col;
                for (int j = min_col + 1; j < max_col; j++) {
                    if (board[start_row][j] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            if (start_col == end_col) {
                int min_row = (start_row < end_row) ? start_row : end_row;
                int max_row = (start_row > end_row) ? start_row : end_row;
                for (int i = min_row + 1; i < max_row; i++) {
                    if (board[i][start_col] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            break;

        case 'N':
            // Check if the knight moves in an L shape
            if (abs(start_row - end_row) == 2 && abs(start_col - end_col) == 1) {
                return 1;
            }
            if (abs(start_row - end_row) == 1 && abs(start_col - end_col) == 2) {
                return 1;
            }
            break;

        case 'B':
            // Check if the bishop moves diagonally
            if (abs(start_row - end_row) == abs(start_col - end_col)) {
                int i = start_row;
                int j = start_col;
                while (i != end_row && j != end_col) {
                    i += (end_row - start_row) / abs(end_row - start_row);
                    j += (end_col - start_col) / abs(end_col - start_col);
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            break;

        case 'Q':
            // Check if the queen moves like a bishop or a rook
            if (start_row == end_row) {
                int min_col = (start_col < end_col) ? start_col : end_col;
                int max_col = (start_col > end_col) ? start_col : end_col;
                for (int j = min_col + 1; j < max_col; j++) {
                    if (board[start_row][j] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            if (start_col == end_col) {
                int min_row = (start_row < end_row) ? start_row : end_row;
                int max_row = (start_row > end_row) ? start_row : end_row;
                for (int i = min_row + 1; i < max_row; i++) {
                    if (board[i][start_col] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            if (abs(start_row - end_row) == abs(start_col - end_col)) {
                int i = start_row;
                int j = start_col;
                while (i != end_row && j != end_col) {
                    i += (end_row - start_row) / abs(end_row - start_row);
                    j += (end_col - start_col) / abs(end_col - start_col);
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            break;

        case 'K':
            // Check if the king moves one square in any direction
            if (abs(start_row - end_row) <= 1 && abs(start_col - end_col) <= 1) {
                return 1;
            }
            break;

        default:
            return 0;
    }

    return 0;
}

// Function to get the next move for the computer player
void get_computer_move(char board[N][N], int *start_row, int *start_col, int *end_row, int *end_col) {
    // Initialize the random number generator
    srand(time(NULL));

    // Loop until a valid move is found
    while (1) {
        // Generate random start and end positions
        *start_row = rand() % 8;
        *start_col = rand() % 8;
        *end_row = rand() % 8;
        *end_col = rand() % 8;

        // Check if the move is valid
        if (is_valid(board, *start_row, *start_col, *end_row, *end_col)) {
            return;
        }
    }
}

// Function to get the next move for the human player
void get_human_move(char board[N][N], int *start_row, int *start_col, int *end_row, int *end_col) {
    // Loop until a valid move is entered
    while (1) {
        printf("\nEnter the start position (row column): ");
        scanf("%d %d", start_row, start_col);
        printf("Enter the end position (row column): ");
        scanf("%d %d", end_row, end_col);

        // Check if the move is valid
        if (is_valid(board, *start_row, *start_col, *end_row, *end_col)) {
            return;
        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }
}

int main() {
    // Initialize the chess board
    char board[N][N] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
    int turn = 0;
    int start_row, start_col, end_row, end_col;

    // Loop until the game is over
    while (1) {
        // Print the current state of the board
        print_board(board);

        // Get the next move for the current player
        if (turn % 2 == 0) {
            printf("\nComputer's turn.\n");
            get_computer_move(board, &start_row, &start_col, &end_row, &end_col);
        } else {
            printf("\nYour turn.\n");
            get_human_move(board, &start_row, &start_col, &end_row, &end_col);
        }

        // Make the move on the board
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = ' ';

        // Increment the turn counter
        turn++;

        // Check if the game is over
        if (board[end_row][end_col] == 'k' || board[end_row][end_col] == 'K') {
            printf("\nCheckmate!\n");
            print_board(board);
            break;
        }
    }

    return 0;
}