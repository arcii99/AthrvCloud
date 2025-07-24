//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0:
                    printf("[ ]");
                    break;
                case 1:
                    printf("[%s]", "B");
                    break;
                case 2:
                    printf("[%s]", "W");
                    break;
                case 3:
                    printf("[%s]", "BK");
                    break;
                case 4:
                    printf("[%s]", "WK");
                    break;
                default:
                    printf("[?]");
                    break;
            }
        }
        printf(" %d\n", i + 1);
    }

    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'a' + i);
    }
    printf("\n\n");
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int start_row, int start_col, int end_row, int end_col) {
    if (board[start_row][start_col] == 0 || board[end_row][end_col] != 0) {
        return 0;   // invalid move
    }
    int move_row = end_row - start_row;
    int move_col = end_col - start_col;
    if (player == 1) {
        if (move_row != -1) {
            return 0;   // invalid move
        }
        if (move_col == -1 || move_col == 1) {
            return 1;   // valid move
        }
        if (move_col == -2) {
            return (board[start_row-1][start_col-1] == 2 || board[start_row-1][start_col-1] == 4);   // valid move if enemy piece is present
        }
        if (move_col == 2) {
            return (board[start_row-1][start_col+1] == 2 || board[start_row-1][start_col+1] == 4);   // valid move if enemy piece is present
        }
    } else {
        if (move_row != 1) {
            return 0;   // invalid move
        }
        if (move_col == -1 || move_col == 1) {
            return 1;   // valid move
        }
        if (move_col == -2) {
            return (board[start_row+1][start_col-1] == 1 || board[start_row+1][start_col-1] == 3);   // valid move if enemy piece is present
        }
        if (move_col == 2) {
            return (board[start_row+1][start_col+1] == 1 || board[start_row+1][start_col+1] == 3);   // valid move if enemy piece is present
        }
    }
    return 0;   // invalid move
}

int is_become_king(int player, int row) {
    if (player == 1) {
        return (row == 0);
    } else {
        return (row == BOARD_SIZE - 1);
    }
}

void make_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int start_row, int start_col, int end_row, int end_col) {
    int piece = board[start_row][start_col];
    board[start_row][start_col] = 0;
    board[end_row][end_col] = piece;
    if (is_become_king(player, end_row)) {
        if (piece == 1) {
            board[end_row][end_col] = 3;
        } else {
            board[end_row][end_col] = 4;
        }
    }
    if (abs(start_row - end_row) == 2) {
        int enemy_row = (start_row + end_row) / 2;
        int enemy_col = (start_col + end_col) / 2;
        board[enemy_row][enemy_col] = 0;
    }
}

int game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    int bk_count = 0, wk_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 1:
                    return 0;   // black piece is still on the board
                case 2:
                    return 0;   // white piece is still on the board
                case 3:
                    bk_count++;
                    break;
                case 4:
                    wk_count++;
                    break;
                default:
                    break;
            }
        }
    }
    if (bk_count == 0 || wk_count == 0) {
        return 1;   // one of the kings is captured
    } else {
        return 0;   // game is not over yet
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i <= 2) {
                    board[i][j] = 1;   // black piece
                } else if (i >= 5) {
                    board[i][j] = 2;   // white piece
                } else {
                    board[i][j] = 0;   // empty cell
                }
            } else {
                board[i][j] = 0;   // empty cell
            }
        }
    }
    printf("Welcome to the Peaceful Checkers Game!\n");
    printf("======================================\n\n");
    print_board(board);
    int player = 1;
    while (!game_over(board)) {
        printf("Player %d's turn:\n", player);
        int start_row, start_col, end_row, end_col;
        while (1) {
            printf("Enter start position (e.g. a3): ");
            char start_pos[3];
            scanf("%s", start_pos);
            start_col = start_pos[0] - 'a';
            start_row = start_pos[1] - '1';
            if (start_col < 0 || start_row < 0 || start_col >= BOARD_SIZE || start_row >= BOARD_SIZE || board[start_row][start_col] == 0 || (player == 1 && (board[start_row][start_col] == 2 || board[start_row][start_col] == 4)) || (player == 2 && (board[start_row][start_col] == 1 || board[start_row][start_col] == 3))) {
                printf("Invalid start position. Try again.\n");
            } else {
                break;
            }
        }
        while (1) {
            printf("Enter end position (e.g. b4): ");
            char end_pos[3];
            scanf("%s", end_pos);
            end_col = end_pos[0] - 'a';
            end_row = end_pos[1] - '1';
            if (end_col < 0 || end_row < 0 || end_col >= BOARD_SIZE || end_row >= BOARD_SIZE || !is_valid_move(board, player, start_row, start_col, end_row, end_col)) {
                printf("Invalid end position. Try again.\n");
            } else {
                break;
            }
        }
        make_move(board, player, start_row, start_col, end_row, end_col);
        print_board(board);
        if (is_become_king(player, end_row)) {
            printf("Player %d's piece becomes king!\n", player);
        }
        if (abs(start_row - end_row) == 2) {
            printf("Player %d captured an enemy piece!\n", player);
        }
        player = (player == 1) ? 2 : 1;
    }
    printf("Player %d wins!\n", player);
    return 0;
}