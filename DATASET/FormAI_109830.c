//FormAI DATASET v1.0 Category: Checkers Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
int player1_count = 12;
int player2_count = 12;

bool game_over() {
    return player1_count == 0 || player2_count == 0;
}

void init_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                if(i < BOARD_SIZE / 3) {
                    board[i][j] = 'X';
                } else if(i > BOARD_SIZE - BOARD_SIZE / 3 - 1) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    printf("   ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int player, int start_row, int start_col, int end_row, int end_col) {
    // Check if the move is within the board
    if(start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return false;
    }

    // Check if the end position is empty
    if(board[end_row][end_col] != ' ') {
        return false;
    }

    char player_marker = player == 1 ? 'X' : 'O';

    // Check if the player is moving their own piece
    if(board[start_row][start_col] != player_marker) {
        return false;
    }

    // Check for valid diagonal move
    int diff_row = end_row - start_row;
    int diff_col = end_col - start_col;
    if(abs(diff_row) != abs(diff_col)) {
        return false;
    }

    // Check if the move is a jump (over an opponent piece)
    if(abs(diff_row) == 2) {
        int jumped_row = start_row + diff_row / 2;
        int jumped_col = start_col + diff_col / 2;
        char opponent_marker = player == 1 ? 'O' : 'X';
        if(board[jumped_row][jumped_col] != opponent_marker) {
            return false;
        }
    }

    return true;
}

bool perform_move(int player, int start_row, int start_col, int end_row, int end_col) {
    char player_marker = player == 1 ? 'X' : 'O';

    // If this is a jump move, remove the opponent's piece
    int diff_row = end_row - start_row;
    int diff_col = end_col - start_col;
    if(abs(diff_row) == 2) {
        int jumped_row = start_row + diff_row / 2;
        int jumped_col = start_col + diff_col / 2;
        board[jumped_row][jumped_col] = ' ';
        if(player == 1) {
            player2_count--;
        } else {
            player1_count--;
        }
    }

    // Move the piece
    board[start_row][start_col] = ' ';
    board[end_row][end_col] = player_marker;

    // Check if this piece should be crowned
    if(player == 1 && end_row == BOARD_SIZE - 1) {
        board[end_row][end_col] = 'K';
    } else if(player == 2 && end_row == 0) {
        board[end_row][end_col] = 'K';
    }

    return true;
}

bool is_valid_jump(int player, int row, int col) {
    char player_marker = player == 1 ? 'X' : 'O';
    if(board[row][col] == player_marker) {
        // This is a valid piece
        if(row < BOARD_SIZE - 2) {
            // Check jump down-right
            if(col < BOARD_SIZE - 2 && board[row+1][col+1] != ' ' && board[row+1][col+1] != player_marker && board[row+2][col+2] == ' ') {
                return true;
            }

            // Check jump down-left
            if(col > 1 && board[row+1][col-1] != ' ' && board[row+1][col-1] != player_marker && board[row+2][col-2] == ' ') {
                return true;
            }
        }

        if(row > 1) {
            // Check jump up-right
            if(col < BOARD_SIZE - 2 && board[row-1][col+1] != ' ' && board[row-1][col+1] != player_marker && board[row-2][col+2] == ' ') {
                return true;
            }

            // Check jump up-left
            if(col > 1 && board[row-1][col-1] != ' ' && board[row-1][col-1] != player_marker && board[row-2][col-2] == ' ') {
                return true;
            }
        }
    }
    return false;
}

bool should_jump(int player) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(is_valid_jump(player, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool play_turn(int player) {
    printf("Player %d's turn\n", player);

    // Check if this player has any valid jumps
    bool jumps_only = should_jump(player);

    while(true) {
        int start_row, start_col, end_row, end_col;

        printf("Enter starting position (row, col): ");
        scanf("%d%d", &start_row, &start_col);

        printf("Enter ending position (row, col): ");
        scanf("%d%d", &end_row, &end_col);

        if(is_valid_move(player, start_row-1, start_col-1, end_row-1, end_col-1)) {
            if(abs(start_row-1 - end_row-1) == 2) {
                // This is a jump move
                int diff_row = end_row-1 - start_row-1;
                int diff_col = end_col-1 - start_col-1;
                int jumped_row = start_row-1 + diff_row / 2;
                int jumped_col = start_col-1 + diff_col / 2;
                printf("Jumping over (%d, %d)\n", jumped_row+1, jumped_col+1);
            }

            perform_move(player, start_row-1, start_col-1, end_row-1, end_col-1);
            print_board();

            if(jumps_only && abs(start_row-1 - end_row-1) != 2) {
                printf("You must take a jump if possible.\n");
                continue;
            }

            if(game_over()) {
                printf("---------------Game Over---------------\n");
                if(player1_count == 0) {
                    printf("Player 2 Wins!\n");
                } else {
                    printf("Player 1 Wins!\n");
                }
                return false;
            }

            if(abs(start_row-1 - end_row-1) == 2 && is_valid_jump(player, end_row-1, end_col-1)) {
                // This player can jump again
                printf("Jump again!\n");
                continue;
            }

            return true;
        } else {
            printf("Invalid move, please try again.\n");
        }
    }
}

void run_game() {
    printf("---------------Welcome to Checkers: Post-Apocalypse Style---------------\n");
    printf("Player 1 is represented by 'X' and Player 2 is represented by 'O'\n");
    printf("Player 1 goes first.\n");

    init_board();
    print_board();

    bool p1_turn = true;
    while(true) {
        if(p1_turn) {
            if(!play_turn(1)) {
                return;
            }
            p1_turn = false;
        } else {
            if(!play_turn(2)) {
                return;
            }
            p1_turn = true;
        }
    }
}

int main() {
    run_game();
    return 0;
}