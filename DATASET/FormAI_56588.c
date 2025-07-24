//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define WHITE 1
#define BLACK 2

int board[BOARD_SIZE][BOARD_SIZE] = {{0, BLACK, 0, BLACK, 0, BLACK, 0, BLACK},
                                      {BLACK, 0, BLACK, 0, BLACK, 0, BLACK, 0},
                                      {0, BLACK, 0, BLACK, 0, BLACK, 0, BLACK},
                                      {EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY, 0},
                                      {0, EMPTY, 0, EMPTY, 0, EMPTY, 0, EMPTY},
                                      {WHITE, 0, WHITE, 0, WHITE, 0, WHITE, 0},
                                      {0, WHITE, 0, WHITE, 0, WHITE, 0, WHITE},
                                      {WHITE, 0, WHITE, 0, WHITE, 0, WHITE, 0}};

void print_board() {
    printf("      0   1   2   3   4   5   6   7\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("   %d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf("|   ");
            } else if (board[i][j] == WHITE) {
                printf("| W ");
            } else if (board[i][j] == BLACK) {
                printf("| B ");
            } else if (board[i][j] == 3) {
                printf("|WK ");
            } else if (board[i][j] == 4) {
                printf("|BK ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

int valid_move(int player, int cur_row, int cur_col, int new_row, int new_col) {
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0;
    }
    if (board[new_row][new_col] != EMPTY) {
        return 0;
    }
    if (player == BLACK) {
        if (new_row > cur_row) {
            return 0;
        }
        if ((cur_row - 1) == new_row && abs(cur_col - new_col) == 1) {
            return 1;
        }
        if ((cur_row - 2) == new_row && abs(cur_col - new_col) == 2) {
            int jumped_piece_col = (cur_col + new_col) / 2, jumped_piece_row = (cur_row + new_row) / 2;
            if (board[jumped_piece_row][jumped_piece_col] == WHITE) {
                return 2;
            } else {
                return 0;
            }
        }
        return 0;
    } else if (player == WHITE) {
        if (new_row < cur_row) {
            return 0;
        }
        if ((cur_row + 1) == new_row && abs(cur_col - new_col) == 1) {
            return 1;
        }
        if ((cur_row + 2) == new_row && abs(cur_col - new_col) == 2) {
            int jumped_piece_col = (cur_col + new_col) / 2, jumped_piece_row = (cur_row + new_row) / 2;
            if (board[jumped_piece_row][jumped_piece_col] == BLACK) {
                return 2;
            } else {
                return 0;
            }
        }
        return 0;
    }
}

int move(int player, int cur_row, int cur_col, int new_row, int new_col) {
    int jump = valid_move(player, cur_row, cur_col, new_row, new_col);
    if (jump) {
        if (player == BLACK) {
            board[new_row][new_col] = BLACK;
            board[cur_row][cur_col] = EMPTY;
            board[(cur_row + new_row) / 2][(cur_col + new_col) / 2] = EMPTY;
            if (new_row == 0) {
                board[new_row][new_col] = 4;
            }
        } else if (player == WHITE) {
            board[new_row][new_col] = WHITE;
            board[cur_row][cur_col] = EMPTY;
            board[(cur_row + new_row) / 2][(cur_col + new_col) / 2] = EMPTY;
            if (new_row == BOARD_SIZE - 1) {
                board[new_row][new_col] = 3;
            }
        }
        return jump;
    } else {
        return 0;
    }
}

int game_over() {
    int count_white = 0, count_black = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == WHITE || board[i][j] == 3) {
                count_white++;
            } else if (board[i][j] == BLACK || board[i][j] == 4) {
                count_black++;
            }
        }
    }
    if (count_white == 0 || count_black == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_player_moves(int player) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == BLACK && (board[i][j] == BLACK || board[i][j] == 4)) {
                if (valid_move(player, i, j, i + 2, j + 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i - 2, j + 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i + 2, j - 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i - 2, j - 2)) {
                    count++;
                }
            } else if (player == WHITE && (board[i][j] == WHITE || board[i][j] == 3)) {
                if (valid_move(player, i, j, i + 2, j + 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i - 2, j + 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i + 2, j - 2)) {
                    count++;
                }
                if (valid_move(player, i, j, i - 2, j - 2)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    printf("Welcome to the game of checkers!\n\n");
    printf("Instructions:\n");
    printf("1. Moves can only be made diagonally.\n");
    printf("2. Jump over the opponent's piece to capture it.\n");
    printf("3. If you reach the opposite end of the board, your piece will be crowned as a king and can move in any direction.\n");
    printf("4. Have fun!\n\n");
    int turn = BLACK, player_moves;
    while (!game_over()) {
        print_board();
        player_moves = get_player_moves(turn);
        if (player_moves == 0) {
            if (turn == WHITE) {
                printf("Black wins!\n\n");
            } else {
                printf("White wins!\n\n");
            }
            break;
        }
        int cur_row, cur_col, new_row, new_col;
        if (turn == BLACK) {
            printf("Black's move.\n");
        } else {
            printf("White's move.\n");
        }
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &cur_row, &cur_col);
        printf("Enter the row and column of your desired move: ");
        scanf("%d %d", &new_row, &new_col);
        if (move(turn, cur_row, cur_col, new_row, new_col)) {
            if (turn == BLACK) {
                turn = WHITE;
            } else {
                turn = BLACK;
            }
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
    print_board();
    return 0;
}