//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int player_turn = 1;

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = 2;
                } else if (i > 4) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board() {
    printf("\n     0   1   2   3   4   5   6   7\n");
    printf("   +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0:
                    printf("   |");
                    break;
                case 1:
                    printf(" 1 |");
                    break;
                case 2:
                    printf(" 2 |");
                    break;
                case 3:
                    printf("*1 |");
                    break;
                case 4:
                    printf("*2 |");
                    break;
            }
        }
        printf("\n");
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
}

int is_valid_move(int start_row, int start_col, int end_row, int end_col) {
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0;
    }
    if (board[end_row][end_col] != 0) {
        return 0;
    }
    int diff_row = end_row - start_row;
    int diff_col = end_col - start_col;
    if (player_turn == 1) {
        if (diff_row == 1 && (diff_col == 1 || diff_col == -1)) {
            return 1;
        } else if (diff_row == 2 && (diff_col == 2 || diff_col == -2)) {
            if (board[start_row+1][start_col+diff_col/2] == 2) {
                return 2;
            }
        }
    } else if (player_turn == 2) {
        if (diff_row == -1 && (diff_col == 1 || diff_col == -1)) {
            return 1;
        } else if (diff_row == -2 && (diff_col == 2 || diff_col == -2)) {
            if (board[start_row-1][start_col+diff_col/2] == 1) {
                return 2;
            }
        }
    }
    return 0;
}

void make_move(int start_row, int start_col, int end_row, int end_col) {
    int is_jump = is_valid_move(start_row, start_col, end_row, end_col);
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = 0;
    if (is_jump == 2) {
        int middle_row = (start_row + end_row) / 2;
        int middle_col = (start_col + end_col) / 2;
        board[middle_row][middle_col] = 0;
    }
    if (player_turn == 1 && end_row == BOARD_SIZE-1 && board[end_row][end_col] == 1) {
        board[end_row][end_col] = 3;
    }
    if (player_turn == 2 && end_row == 0 && board[end_row][end_col] == 2) {
        board[end_row][end_col] = 4;
    }
}

int get_opponent() {
    if (player_turn == 1) {
        return 2;
    } else {
        return 1;
    }
}

int count_pieces(int player) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player+2) {
                count++;
            }
        }
    }
    return count;
}

int check_winner() {
    int player1_count = count_pieces(1);
    int player2_count = count_pieces(2);
    if (player1_count == 0) {
        return 2;
    } else if (player2_count == 0) {
        return 1;
    }
    return 0;
}

int main() {
    initialize_board();
    int winner = 0;
    while (1) {
        print_board();
        if (player_turn == 1) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }
        printf("Enter starting row: ");
        int start_row;
        scanf("%d", &start_row);
        printf("Enter starting column: ");
        int start_col;
        scanf("%d", &start_col);
        printf("Enter ending row: ");
        int end_row;
        scanf("%d", &end_row);
        printf("Enter ending column: ");
        int end_col;
        scanf("%d", &end_col);
        int is_valid = is_valid_move(start_row, start_col, end_row, end_col);
        if (is_valid == 0) {
            printf("Invalid move\n");
        } else {
            make_move(start_row, start_col, end_row, end_col);
            int opponent = get_opponent();
            int is_jump = is_valid_move(end_row, end_col, end_row-2, end_col+2);
            if (is_jump == 2 || is_jump == 3) {
                int can_jump = 0;
                if (is_valid_move(end_row, end_col, end_row-2, end_col-2)) {
                    can_jump = 1;
                }
                if (is_valid_move(end_row, end_col, end_row+2, end_col+2)) {
                    can_jump = 1;
                }
                if (is_valid_move(end_row, end_col, end_row+2, end_col-2)) {
                    can_jump = 1;
                }
                if (!can_jump) {
                    player_turn = opponent;
                }
            } else {
                player_turn = opponent;
            }
            winner = check_winner();
            if (winner != 0) {
                break;
            }
        }
    }
    print_board();
    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else if (winner == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}