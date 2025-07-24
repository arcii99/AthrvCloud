//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>

// global variables
int board[8][8] = {
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}
};

int player = 1; // 1 for white, -1 for black

// function prototypes
void display_board();
int get_move();
int make_move(int row1, int col1, int row2, int col2);
int validate_move(int row1, int col1, int row2, int col2);
int check_for_winner();

int main() {
    int end_game = 0;
    int row1, col1, row2, col2;
    
    while (!end_game) {
        display_board();
        printf("Player %d's turn.\n", player);
        int move_result = make_move(row1, col1, row2, col2);
        if (move_result == -1) {
            printf("Invalid move. Try again.\n");
        } else if (move_result == 1) {
            printf("Jump move completed. Player %d's turn again.\n", player);
        } else {
            // switch players
            player *= -1;
        }
        int winner = check_for_winner();
        if (winner) {
            printf("Player %d wins!\n", winner);
            end_game = 1;
        }
    }
    
    return 0;
}

void display_board() {
    printf("   0  1  2  3  4  5  6  7\n");
    for (int i=0; i<8; i++) {
        printf("%d ", i);
        for (int j=0; j<8; j++) {
            if (board[i][j] == -1) {
                printf("|%s", " B");
            } else if (board[i][j] == 1) {
                printf("|%s", " W");
            } else {
                printf("|%s", "  ");
            }
        }
        printf("|\n");
    }
}

int get_move() {
    int row1, col1, row2, col2;
    printf("Enter the row and column of the piece you want to move: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the row and column of the space you want to move to: ");
    scanf("%d %d", &row2, &col2);
    return make_move(row1, col1, row2, col2);
}

int make_move(int row1, int col1, int row2, int col2) {
    printf("%d %d %d %d\n", row1, col1, row2, col2);
    if (!validate_move(row1, col1, row2, col2)) {
        return -1;
    }
    int move_result;
    if (row2 == row1 + 2 || row2 == row1 - 2) {
        int captured_row = (row1 + row2) / 2;
        int captured_col = (col1 + col2) / 2;
        board[captured_row][captured_col] = 0;
        move_result = 1; // jump move
    } else {
        move_result = 0; // plain move
    }
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = 0;
    return move_result;
}

int validate_move(int row1, int col1, int row2, int col2) {
    if (row1 < 0 || col1 < 0 || row2 < 0 || col2 < 0) {
        return 0;
    }
    if (row1 > 7 || col1 > 7 || row2 > 7 || col2 > 7) {
        return 0;
    }
    if (board[row1][col1] == 0) {
        return 0;
    }
    if (board[row2][col2] != 0) {
        return 0;
    }
    if (board[row1][col1] == -1 && player == 1) {
        return 0;
    }
    if (board[row1][col1] == 1 && player == -1) {
        return 0;
    }
    int row_diff = row2 - row1;
    int col_diff = col2 - col1;
    if (board[row1][col1] == 1 && row_diff > 0) {
        return 0;
    }
    if (board[row1][col1] == -1 && row_diff < 0) {
        return 0;
    }
    if (row_diff == 2 || row_diff == -2) {
        int captured_row = (row1 + row2) / 2;
        int captured_col = (col1 + col2) / 2;
        if (board[captured_row][captured_col] * player >= 0) {
            return 0;
        }
    }
    if (row_diff != 1 && row_diff != -1 && row_diff != 2 && row_diff != -2) {
        return 0;
    }
    if (col_diff != 1 && col_diff != -1 && col_diff != 2 && col_diff != -2) {
        return 0;
    }
    if (row_diff == 0 || col_diff == 0) {
        return 0;
    }
    return 1;
}

int check_for_winner() {
    int white_pieces = 0;
    int black_pieces = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j] == 1) {
                white_pieces++;
            } else if (board[i][j] == -1) {
                black_pieces++;
            }
        }
    }
    if (white_pieces == 0) {
        return -1; // black wins
    }
    if (black_pieces == 0) {
        return 1; // white wins
    }
    return 0; // no winner yet
}