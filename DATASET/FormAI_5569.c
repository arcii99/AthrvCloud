//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// function to print the board
void print_board(int board[][SIZE]) {
    int i, j;
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == 2)
                printf("O ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

// get user input for piece to move and desired location
void get_input(int *choice, int *new_row, int *new_col) {
    printf("\nEnter row and column of piece to move: ");
    scanf("%d %d", &choice[0], &choice[1]);
    printf("Enter row and column of new location: ");
    scanf("%d %d", new_row, new_col);
}

// validate user input
int validate_input(int board[][SIZE], int *choice, int new_row, int new_col) {
    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        printf("\nNew location is not on the board.\n");
        return 0;
    }
    else if (board[new_row][new_col] != 0) {
        printf("\nNew location already has a piece.\n");
        return 0;
    }
    else if (new_row == choice[0] || new_col == choice[1]) {
        printf("\nMust move diagonally.\n");
        return 0;
    }
    else {
        int row_dir, col_dir;
        row_dir = new_row - choice[0];
        col_dir = new_col - choice[1];
        if (abs(row_dir) != abs(col_dir)) {
            printf("\nNot a valid move.\n");
            return 0;
        }
        else if (abs(row_dir) > 2) {
            printf("\nCan only move up to 2 spaces.\n");
            return 0;
        }
        else if (abs(row_dir) == 2) {
            if (board[(new_row + choice[0])/2][(new_col + choice[1])/2] == 0) {
                printf("\nMust jump over a piece.\n");
                return 0;
            }
            else if (board[new_row][new_col] == board[choice[0]][choice[1]]) {
                printf("\nCan't jump over own pieces.\n");
                return 0;
            }
            else {
                board[(new_row + choice[0])/2][(new_col + choice[1])/2] = 0;
                return 1;
            }
        }
        else {
            return 1;
        }
    }
}

// update the board after a move has been made
void update_board(int board[][SIZE], int *choice, int new_row, int new_col) {
    board[new_row][new_col] = board[choice[0]][choice[1]];
    board[choice[0]][choice[1]] = 0;
}

// check if a player has won the game
int check_win(int board[][SIZE], int player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player + 2) {
                if (i < SIZE - 2 && j < SIZE - 2) {
                    if (board[i+1][j+1] == 0) {
                        if (player == 1 && board[i+2][j+2] == 0)
                            return 0;
                        else if (player == 2 && board[i+2][j+2] == 0)
                            return 0;
                        else if (board[i+2][j+2] == 3 - player || board[i+2][j+2] == 3 - player + 2)
                            return 0;
                    }
                }
                if (i > 1 && j < SIZE - 2) {
                    if (board[i-1][j+1] == 0) {
                        if (player == 1 && board[i-2][j+2] == 0)
                            return 0;
                        else if (player == 2 && board[i-2][j+2] == 0)
                            return 0;
                        else if (board[i-2][j+2] == 3 - player || board[i-2][j+2] == 3 - player + 2)
                            return 0;
                    }
                }
                if (player == 1 && board[i][j] == 1) {
                    if ((i > 0 && j > 0 && board[i-1][j-1] == 0) ||
                        (i > 0 && j < SIZE - 1 && board[i-1][j+1] == 0)) {
                        return 0;
                    }
                }
                if (player == 2 && board[i][j] == 2) {
                    if ((i < SIZE - 1 && j > 0 && board[i+1][j-1] == 0) ||
                        (i < SIZE - 1 && j < SIZE - 1 && board[i+1][j+1] == 0)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    // initialize the board
    int board[SIZE][SIZE] = {{0, 1, 0, 1, 0, 1, 0, 1},
                             {1, 0, 1, 0, 1, 0, 1, 0},
                             {0, 1, 0, 1, 0, 1, 0, 1},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {2, 0, 2, 0, 2, 0, 2, 0},
                             {0, 2, 0, 2, 0, 2, 0, 2},
                             {2, 0, 2, 0, 2, 0, 2, 0}};

    int player = 1;
    int choice[2], new_row, new_col, valid_move;

    while (check_win(board, player) == 0) {
        printf("\nPlayer %d's turn:\n", player);
        print_board(board);
        valid_move = 0;

        while (valid_move == 0) {
            get_input(choice, &new_row, &new_col);
            valid_move = validate_input(board, choice, new_row, new_col);
            if (valid_move == 0)
                printf("Invalid move, try again.\n");
        }

        update_board(board, choice, new_row, new_col);

        if (player == 1 && new_row == SIZE - 1)
            board[new_row][new_col] = player + 2;
        else if (player == 2 && new_row == 0)
            board[new_row][new_col] = player + 2;

        if (valid_move == 1 && abs(new_row - choice[0]) == 2) {
            if (player == 1)
                player = 2;
            else
                player = 1;
        }
    }

    print_board(board);
    printf("\nPlayer %d wins!\n", player);

    return 0;
}