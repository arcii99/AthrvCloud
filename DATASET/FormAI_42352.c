//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int player_turn = 0;    // 0: player 1, 1: player 2
char board[BOARD_SIZE][BOARD_SIZE];
char selection[3];

// prints the board
void print_board() {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("   A B C D E F G H\n");
}

// initializes the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == 2) {
                // player 1 pieces
                if (j % 2 == 0) {
                    board[i][j] = 'x';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i == 1) {
                // player 1 pieces
                if (j % 2 == 0) {
                    board[i][j] = 'x';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i == 5 || i == 7) {
                // player 2 pieces
                if (j % 2 == 0) {
                    board[i][j] = ' ';
                } else {
                    board[i][j] = 'o';
                }
            } else if (i == 6) {
                // player 2 pieces
                if (j % 2 == 0) {
                    board[i][j] = ' ';
                } else {
                    board[i][j] = 'o';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// checks if the move is legal
int is_legal_move(int start_row, int start_col, int end_row, int end_col) {
    if (player_turn == 0) {
        // player 1 can only move upwards
        if (end_row < start_row) {
            printf("Invalid move! Player 1 pieces can only move upwards.\n");
            return 0;
        }
    } else {
        // player 2 can only move downwards
        if (end_row > start_row) {
            printf("Invalid move! Player 2 pieces can only move downwards.\n");
            return 0;
        }
    }

    // check if end position is empty
    if (board[end_row][end_col] != ' ') {
        printf("Invalid move! End position is not empty.\n");
        return 0;
    }

    // check if diagonal move
    int diff_row = end_row - start_row;
    int diff_col = end_col - start_col;

    if (abs(diff_row) != 1 || abs(diff_col) != 1) {
        printf("Invalid move! Pieces can only move diagonally by one square.\n");
        return 0;
    }

    // can only move pieces, not empty squares
    if (board[start_row][start_col] == ' ') {
        printf("Invalid move! Cannot move empty square.\n");
        return 0;
    }

    return 1;
}

// checks if the move is a capturing move
int is_capturing_move(int start_row, int start_col, int end_row, int end_col) {
    // check if diagonal move by 2 squares
    int diff_row = end_row - start_row;
    int diff_col = end_col - start_col;

    if (abs(diff_row) != 2 || abs(diff_col) != 2) {
        return 0;
    }

    // check if there is a piece to capture
    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;

    if (board[mid_row][mid_col] == ' ' || board[mid_row][mid_col] == selection[0]) {
        return 0;
    }

    // capture the piece
    board[mid_row][mid_col] = ' ';
    return 1;
}

// checks if there is any capturing move available
int has_capturing_move(int row, int col) {
    // check for player 1 pieces
    if (board[row][col] == 'x') {
        if (row + 2 < BOARD_SIZE && col + 2 < BOARD_SIZE) {
            if (board[row+1][col+1] == 'o' && board[row+2][col+2] == ' ') {
                return 1;
            }
        }
        if (row + 2 < BOARD_SIZE && col - 2 >= 0) {
            if (board[row+1][col-1] == 'o' && board[row+2][col-2] == ' ') {
                return 1;
            }
        }
        if (row - 2 >= 0 && col + 2 < BOARD_SIZE) {
            if (board[row-1][col+1] == 'o' && board[row-2][col+2] == ' ') {
                return 1;
            }
        }
        if (row - 2 >= 0 && col - 2 >= 0) {
            if (board[row-1][col-1] == 'o' && board[row-2][col-2] == ' ') {
                return 1;
            }
        }
    }
    // check for player 2 pieces
    if (board[row][col] == 'o') {
        if (row + 2 < BOARD_SIZE && col + 2 < BOARD_SIZE) {
            if (board[row+1][col+1] == 'x' && board[row+2][col+2] == ' ') {
                return 1;
            }
        }
        if (row + 2 < BOARD_SIZE && col - 2 >= 0) {
            if (board[row+1][col-1] == 'x' && board[row+2][col-2] == ' ') {
                return 1;
            }
        }
        if (row - 2 >= 0 && col + 2 < BOARD_SIZE) {
            if (board[row-1][col+1] == 'x' && board[row-2][col+2] == ' ') {
                return 1;
            }
        }
        if (row - 2 >= 0 && col - 2 >= 0) {
            if (board[row-1][col-1] == 'x' && board[row-2][col-2] == ' ') {
                return 1;
            }
        }
    }
    return 0;
}

// checks if the game is over
int is_game_over() {
    int player1_pieces = 0;
    int player2_pieces = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'x' || board[i][j] == 'X') {
                player1_pieces++;
            } else if (board[i][j] == 'o' || board[i][j] == 'O') {
                player2_pieces++;
            }
        }
    }

    if (player1_pieces == 0) {
        printf("Game over! Player 2 wins!\n");
        return 1;
    } else if (player2_pieces == 0) {
        printf("Game over! Player 1 wins!\n");
        return 1;
    }

    return 0;
}

// converts the selection coordinates to row and column
void get_selection_coordinates(int* row, int* col) {
    *col = selection[0] - 'A';
    *row = selection[1] - '1';
}

// converts the move coordinates to row and column
void get_move_coordinates(int* row, int* col) {
    *col = selection[2] - 'A';
    *row = selection[3] - '1';
}

// updates the board with the move
void apply_move(int start_row, int start_col, int end_row, int end_col) {
    char piece = board[start_row][start_col];
    board[start_row][start_col] = ' ';
    board[end_row][end_col] = piece;

    // check if piece has become a king
    if (player_turn == 0 && end_row == BOARD_SIZE-1 && piece == 'x') {
        board[end_row][end_col] = 'X';
    } else if (player_turn == 1 && end_row == 0 && piece == 'o') {
        board[end_row][end_col] = 'O';
    }
}

// gets the user's move
void get_move() {
    printf("Player %d, enter your move (e.g. A1 B2): ", player_turn+1);
    scanf("%s", selection);

    int start_row, start_col, end_row, end_col;
    get_selection_coordinates(&start_row, &start_col);
    get_move_coordinates(&end_row, &end_col);

    if (is_legal_move(start_row, start_col, end_row, end_col)) {
        int captured_piece = is_capturing_move(start_row, start_col, end_row, end_col);
        apply_move(start_row, start_col, end_row, end_col);
        if (captured_piece) {
            if (has_capturing_move(end_row, end_col)) {
                printf("Captured a piece! You have another move!\n");
                selection[0] = selection[2];
                selection[1] = selection[3];
                get_move();
            }
        }
        player_turn = (player_turn + 1) % 2;
    }
}

// main function
int main() {
    initialize_board();

    while (1) {
        print_board();
        if (is_game_over()) {
            break;
        }
        get_move();
    }

    return 0;
}