//FormAI DATASET v1.0 Category: Checkers Game ; Style: optimized
#include <stdio.h>
#define BOARD_SIZE 8
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY ' '

void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
int game_over(char board[BOARD_SIZE][BOARD_SIZE], char player);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int row1, int col1, int row2, int col2);
int is_capture_move(int row1, int col1, int row2, int col2);
void make_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int row1, int col1, int row2, int col2);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    display_board(board);

    char current_player = PLAYER_1;
    int game_status = 0;
    int row1, col1, row2, col2;

    while (!game_status) {
        printf("Player %c's turn\n", current_player);

        do {
            printf("Enter piece coordinates: ");
            scanf("%d %d", &row1, &col1);
        } while (board[row1][col1] != current_player);

        do {
            printf("Enter move coordinates: ");
            scanf("%d %d", &row2, &col2);
        } while (!is_valid_move(board, current_player, row1, col1, row2, col2));

        make_move(board, current_player, row1, col1, row2, col2);
        display_board(board);

        game_status = game_over(board, current_player);
        if (game_status) {
            printf("Player %c wins!\n", current_player);
            break;
        }

        current_player = (current_player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }

    return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = PLAYER_1;
                } else if (i > 4) {
                    board[i][j] = PLAYER_2;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int game_over(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                if (is_valid_move(board, player, i, j, i+1, j+1) ||
                    is_valid_move(board, player, i, j, i+1, j-1) ||
                    is_valid_move(board, player, i, j, i-1, j+1) ||
                    is_valid_move(board, player, i, j, i-1, j-1)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int row1, int col1, int row2, int col2) {
    if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
        return 0;
    }
    if (board[row2][col2] != EMPTY) {
        return 0;
    }

    if (player == PLAYER_1) {
        if (row2 > row1) {
            return 0;
        }
    } else {
        if (row2 < row1) {
            return 0;
        }
    }

    if (abs(row2 - row1) == 1 && abs(col2 - col1) == 1) {
        return 1;
    } else if (abs(row2 - row1) == 2 && abs(col2 - col1) == 2) {
        int capture_row = (row1 + row2) / 2;
        int capture_col = (col1 + col2) / 2;
        if (is_capture_move(row1, col1, capture_row, capture_col)) {
            return 1;
        }
    }

    return 0;
}

int is_capture_move(int row1, int col1, int row2, int col2) {
    int capture_row = (row1 + row2) / 2;
    int capture_col = (col1 + col2) / 2;
    if (row1 - row2 == 2) {
        if (col1 - col2 == 2) {
            return (row1-1 == capture_row && col1-1 == capture_col);
        } else if (col2 - col1 == 2) {
            return (row1-1 == capture_row && col1+1 == capture_col);
        }
    } else if (row2 - row1 == 2) {
        if (col1 - col2 == 2) {
            return (row1+1 == capture_row && col1-1 == capture_col);
        } else if (col2 - col1 == 2) {
            return (row1+1 == capture_row && col1+1 == capture_col);
        }
    }

    return 0;
}

void make_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int row1, int col1, int row2, int col2) {
    board[row1][col1] = EMPTY;
    board[row2][col2] = player;

    if (is_capture_move(row1, col1, row2, col2)) {
        int capture_row = (row1 + row2) / 2;
        int capture_col = (col1 + col2) / 2;
        board[capture_row][capture_col] = EMPTY;
    }
}