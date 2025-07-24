//FormAI DATASET v1.0 Category: Chess AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initializing the chess board
char board[8][8] = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                     {'.', '.', '.', '.', '.', '.', '.', '.'},
                     {'.', '.', '.', '.', '.', '.', '.', '.'},
                     {'.', '.', '.', '.', '.', '.', '.', '.'},
                     {'.', '.', '.', '.', '.', '.', '.', '.'},
                     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                     {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
                   };

// Function to print the chess board
void print_board() {
    printf("-----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("|");
        for (int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

// Function to check if the given position is within the board
int is_within_board(int row, int col) {
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

// Function to move a piece from one place to another
void move_piece(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = '.';
}

// Function to check if the given move is valid or not
int is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    // If the starting position doesn't have a piece, return false
    if (board[from_row][from_col] == '.') {
        return 0;
    }

    // If the destination position has a friendly piece, return false
    if (board[to_row][to_col] != '.' && (board[from_row][from_col] == board[to_row][to_col])) {
        return 0;
    }

    // If the move isn't within the board, return false
    if (!is_within_board(to_row, to_col)) {
        return 0;
    }

    char piece = board[from_row][from_col];

    // Check if the move is valid for the given piece
    switch (piece) {
        case 'p':
        case 'P':
            // Pawn can only move forward one step, or two if it is its initial move
            if (from_col != to_col && board[to_row][to_col] == '.') {
                return 0;
            }

            if (piece == 'p') {
                if (from_row == 1) {
                    if ((to_row != 2 && to_row != 3) || (to_row == 3 && board[2][to_col] != '.')) {
                        return 0;
                    }
                } else {
                    if (to_row != from_row+1) {
                        return 0;
                    }
                }

                if (to_col != from_col && board[to_row][to_col] == '.') {
                    return 0;
                }
            } else {
                if (from_row == 6) {
                    if ((to_row != 5 && to_row != 4) || (to_row == 4 && board[5][to_col] != '.')) {
                        return 0;
                    }
                } else {
                    if (to_row != from_row-1) {
                        return 0;
                    }
                }

                if (to_col != from_col && board[to_row][to_col] == '.') {
                    return 0;
                }
            }
            break;

        case 'r':
        case 'R':
            // Rook can move only in straight lines
            if (from_row != to_row && from_col != to_col) {
                return 0;
            }

            if (from_row == to_row && from_col == to_col) {
                return 0;
            }

            if (from_col == to_col) {
                // Vertical movement
                int min_row = (from_row < to_row) ? from_row : to_row;
                int max_row = (from_row > to_row) ? from_row : to_row;

                for (int i = min_row + 1; i < max_row; i++) {
                    if (board[i][from_col] != '.') {
                        return 0;
                    }
                }
            } else {
                // Horizontal movement
                int min_col = (from_col < to_col) ? from_col : to_col;
                int max_col = (from_col > to_col) ? from_col : to_col;

                for (int i = min_col + 1; i < max_col; i++) {
                    if (board[from_row][i] != '.') {
                        return 0;
                    }
                }
            }
            break;

        case 'n':
        case 'N':
            // Knight can move in L shape
            if ((to_row == from_row + 2 && to_col == from_col + 1) || // 2 rows down, 1 column right
                (to_row == from_row + 2 && to_col == from_col - 1) || // 2 rows down, 1 column left
                (to_row == from_row - 2 && to_col == from_col + 1) || // 2 rows up, 1 column right
                (to_row == from_row - 2 && to_col == from_col - 1) || // 2 rows up, 1 column left
                (to_row == from_row + 1 && to_col == from_col + 2) || // 1 row down, 2 columns right
                (to_row == from_row - 1 && to_col == from_col + 2) || // 1 row up, 2 columns right
                (to_row == from_row + 1 && to_col == from_col - 2) || // 1 row down, 2 columns left
                (to_row == from_row - 1 && to_col == from_col - 2))   // 1 row up, 2 columns left
            {
                break;
            } else {
                return 0;
            }

        case 'b':
        case 'B':
            // Bishop can move only diagonally
            if (abs(from_row - to_row) != abs(from_col - to_col)) {
                return 0;
            }

            int diff = abs(from_row - to_row);

            if (from_row < to_row && from_col < to_col) {
                // Moving down-right
                for (int i = 1; i < diff; i++) {
                    if (board[from_row+i][from_col+i] != '.') {
                        return 0;
                    }
                }
            } else if (from_row < to_row && from_col > to_col) {
                // Moving down-left
                for (int i = 1; i < diff; i++) {
                    if (board[from_row+i][from_col-i] != '.') {
                        return 0;
                    }
                }
            } else if (from_row > to_row && from_col > to_col) {
                // Moving up-left
                for (int i = 1; i < diff; i++) {
                    if (board[from_row-i][from_col-i] != '.') {
                        return 0;
                    }
                }
            } else {
                // Moving up-right
                for (int i = 1; i < diff; i++) {
                    if (board[from_row-i][from_col+i] != '.') {
                        return 0;
                    }
                }
            }
            break;

        case 'q':
        case 'Q':
            // Queen can move like rook or bishop
            if (from_row == to_row || from_col == to_col) {
                // Rook like movement
                if (is_valid_move(from_row, from_col, to_row, to_col)) {
                    break;
                } else {
                    return 0;
                }
            } else if (abs(from_row - to_row) == abs(from_col - to_col)) {
                // Bishop like movement
                if (is_valid_move(from_row, from_col, to_row, to_col)) {
                    break;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
            break;

        case 'k':
        case 'K':
            // King can move in any direction, but only one step at a time
            if (abs(from_row - to_row) <= 1 && abs(from_col - to_col) <= 1) {
                break;
            } else {
                return 0;
            }

        default:
            printf("Invalid piece.\n");
            exit(EXIT_FAILURE);
    }

    return 1;
}

// Function to generate a random move for the AI
void generate_move(int *from_row, int *from_col, int *to_row, int *to_col) {
    srand(time(NULL));

    int valid_move_found = 0;

    while (!valid_move_found) {
        *from_row = rand() % 8;
        *from_col = rand() % 8;
        *to_row = rand() % 8;
        *to_col = rand() % 8;

        if (is_valid_move(*from_row, *from_col, *to_row, *to_col)) {
            valid_move_found = 1;
        }
    }

    printf("AI moves %c%d to %c%d.\n", *from_col+'a', 8-*from_row, *to_col+'a', 8-*to_row);
}

int main() {
    int from_row, from_col, to_row, to_col;

    print_board();

    int game_ended = 0;
    int turn = 0;

    while (!game_ended) {
        printf("Enter move for Player %d (e.g. 'a2 to a4'): ", turn+1);
        scanf(" %c%d to %c%d", &from_col, &from_row, &to_col, &to_row);

        from_row = 8 - from_row;
        to_row = 8 - to_row;
        from_col -= 'a';
        to_col -= 'a';

        if (!is_valid_move(from_row, from_col, to_row, to_col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        move_piece(from_row, from_col, to_row, to_col);

        print_board();

        if (turn == 0) {
            printf("AI's turn.\n");
            generate_move(&from_row, &from_col, &to_row, &to_col);

            move_piece(from_row, from_col, to_row, to_col);

            print_board();
        }

        turn = !turn;
    }

    return 0;
}