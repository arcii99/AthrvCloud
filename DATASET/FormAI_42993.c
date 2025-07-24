//FormAI DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 8 /* size of the playing grid */
#define RED 'R'
#define BLACK 'B'
#define EMPTY '-'

void init_board(char board[][GRID_SIZE]);
void print_board(char board[][GRID_SIZE]);
int make_move(char board[][GRID_SIZE], char player);
void move_input(int *row, int *col);
int check_valid_move(char board[][GRID_SIZE], int from_row, int from_col, int to_row, int to_col, char player);
int check_valid_capture(char board[][GRID_SIZE], int from_row, int from_col, int to_row, int to_col, char player);
int check_for_winner(char board[][GRID_SIZE]);

int main() {
    char board[GRID_SIZE][GRID_SIZE];
    char player = RED; /* RED goes first */
    int move_result = 0; /* stores the result of a move */
    int winner;

    init_board(board);
    print_board(board);

    while (1) {
        printf("Player %c's turn:\n", player);
        move_result = make_move(board, player);

        if (move_result == 0) {
            printf("Invalid move - please try again.\n");
            continue;
        }

        print_board(board);

        winner = check_for_winner(board);
        if (winner != 0) {
            printf("Player %c wins!\n", winner);
            break;
        }

        if (player == RED) player = BLACK;
        else player = RED;
    }

    return 0;
}

/* sets up the board with starting positions */
void init_board(char board[][GRID_SIZE]) {
    int i,j;

    for (i=0;i<GRID_SIZE;i++) {
        for (j=0;j<GRID_SIZE;j++) {
            if (i < 3) {
                if ((i+j)%2 == 0) board[i][j] = BLACK;
                else board[i][j] = EMPTY;
            } else if (i >= GRID_SIZE-3) {
                if ((i+j)%2 == 0) board[i][j] = RED;
                else board[i][j] = EMPTY;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

/* prints the board */
void print_board(char board[][GRID_SIZE]) {
    int i,j;

    for (i=0;i<GRID_SIZE;i++) {
        for (j=0;j<GRID_SIZE;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

/* prompts the user for a move and makes it */
int make_move(char board[][GRID_SIZE], char player) {
    int from_row, from_col, to_row, to_col, valid_move, valid_capture;

    move_input(&from_row, &from_col);
    move_input(&to_row, &to_col);

    valid_move = check_valid_move(board, from_row, from_col, to_row, to_col, player);
    if (!valid_move) return 0;

    valid_capture = check_valid_capture(board, from_row, from_col, to_row, to_col, player);
    if (valid_capture) {
        board[to_row][to_col] = player;
        board[from_row][from_col] = EMPTY;
        int row_diff = to_row - from_row;
        int col_diff = to_col - from_col;
        board[from_row+row_diff/2][from_col+col_diff/2] = EMPTY;
        return 1;
    }

    if (valid_move) {
        board[to_row][to_col] = player;
        board[from_row][from_col] = EMPTY;
        return 1;
    }

    return 0;
}

/* prompts the user for a row and column */
void move_input(int *row, int *col) {
    printf("Enter row:");
    scanf("%d", row);
    printf("Enter column:");
    scanf("%d", col);
}

/* checks if a move is valid */
int check_valid_move(char board[][GRID_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    int valid_move = 0;
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    if (board[to_row][to_col] != EMPTY) return 0;

    if (player == RED) {
        if (row_diff == -1 && abs(col_diff) == 1) {
            valid_move = 1;
        } else if (row_diff == -2 && abs(col_diff) == 2) {
            if (board[from_row-1][from_col+(col_diff/2)] == BLACK) {
                valid_move = 1;
            }
        }
    } else {
        if (row_diff == 1 && abs(col_diff) == 1) {
            valid_move = 1;
        } else if (row_diff == 2 && abs(col_diff) == 2) {
            if (board[from_row+1][from_col+(col_diff/2)] == RED) {
                valid_move = 1;
            }
        }
    }

    return valid_move;
}

/* checks if a capture is valid */
int check_valid_capture(char board[][GRID_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    int valid_capture = 0;
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    if (board[to_row][to_col] != EMPTY) return 0;

    if (player == RED) {
        if (row_diff == -2 && abs(col_diff) == 2) {
            if (board[from_row-1][from_col+(col_diff/2)] == BLACK) {
                valid_capture = 1;
            }
        }
    } else {
        if (row_diff == 2 && abs(col_diff) == 2) {
            if (board[from_row+1][from_col+(col_diff/2)] == RED) {
                valid_capture = 1;
            }
        }
    }

    return valid_capture;
}

/* checks if there is a winner */
int check_for_winner(char board[][GRID_SIZE]) {
    int i,j;
    int red_count = 0, black_count = 0;

    for (i=0;i<GRID_SIZE;i++) {
        for (j=0;j<GRID_SIZE;j++) {
            if (board[i][j] == RED) red_count++;
            else if (board[i][j] == BLACK) black_count++;
        }
    }

    if (red_count == 0) return BLACK;
    if (black_count == 0) return RED;

    return 0;
}