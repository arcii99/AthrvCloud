//FormAI DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(char board[][BOARD_SIZE]) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  +--------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf("  +--------+\n");
    }
}

int is_valid_move(char board[][BOARD_SIZE], int current_player, int row, int col, int new_row, int new_col) {
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0;
    }
    
    char current_piece = board[row][col];
    char new_piece = board[new_row][new_col];
    
    if (new_piece != '_' && new_piece != ' ') {
        return 0;
    }
    
    if (current_player == 1 && current_piece == 'o') {
        if (new_row == row - 1 && (new_col == col - 1 || new_col == col + 1)) {
            return 1;
        } else if (new_row == row - 2 && new_col == col - 2 && board[row - 1][col - 1] == 'x') {
            return 1;
        } else if (new_row == row - 2 && new_col == col + 2 && board[row - 1][col + 1] == 'x') {
            return 1;
        } else {
            return 0;
        }
    } else if (current_player == 2 && current_piece == 'x') {
        if (new_row == row + 1 && (new_col == col - 1 || new_col == col + 1)) {
            return 1;
        } else if (new_row == row + 2 && new_col == col - 2 && board[row + 1][col - 1] == 'o') {
            return 1;
        } else if (new_row == row + 2 && new_col == col + 2 && board[row + 1][col + 1] == 'o') {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void make_move(char board[][BOARD_SIZE], int current_player, int row, int col, int new_row, int new_col) {
    char current_piece = board[row][col];
    board[row][col] = '_';
    if (current_player == 1 && new_row == 0) {
        board[new_row][new_col] = 'k';
    } else if (current_player == 2 && new_row == BOARD_SIZE - 1) {
        board[new_row][new_col] = 'K';
    } else {
        board[new_row][new_col] = current_piece;
    }
    if (abs(new_row - row) == 2) {
        board[(row + new_row) / 2][(col + new_col) / 2] = '_';
    }
}

int is_game_over(char board[][BOARD_SIZE]) {
    int num_x = 0;
    int num_o = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'x' || board[i][j] == 'k') {
                num_x++;
            } else if (board[i][j] == 'o' || board[i][j] == 'K') {
                num_o++;
            }
        }
    }
    if (num_x == 0 || num_o == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'_', 'x', '_', 'x', '_', 'x', '_', 'x'},
        {'x', '_', 'x', '_', 'x', '_', 'x', '_'},
        {'_', 'x', '_', 'x', '_', 'x', '_', 'x'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '_'},
        {'o', '_', 'o', '_', 'o', '_', 'o', '_'},
        {'_', 'o', '_', 'o', '_', 'o', '_', 'o'},
        {'o', '_', 'o', '_', 'o', '_', 'o', '_'}
    };
    
    printf("Welcome to Checkers!\n");
    printf("Player 1 (x) goes first.\n");
    
    int current_player = 1;
    while (1) {
        print_board(board);
        int row, col, new_row, new_col;
        printf("Player %d's turn.\n", current_player);
        printf("Enter row of piece to move: ");
        scanf("%d", &row);
        printf("Enter column of piece to move: ");
        scanf("%d", &col);
        printf("Enter row of destination: ");
        scanf("%d", &new_row);
        printf("Enter column of destination: ");
        scanf("%d", &new_col);
        if (is_valid_move(board, current_player, row, col, new_row, new_col)) {
            make_move(board, current_player, row, col, new_row, new_col);
        } else {
            printf("Invalid move!\n");
            continue;
        }
        if (is_game_over(board)) {
            printf("Game over! Player %d wins!\n", current_player);
            break;
        }
        current_player = current_player == 1 ? 2 : 1;
    }
    
    return 0;
}