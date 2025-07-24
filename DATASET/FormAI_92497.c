//FormAI DATASET v1.0 Category: Checkers Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Initialize the board with pieces
void initialize_board(char board[][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i%2 == 0) && (j%2 == 0)) {
                if(i < 3) {
                    board[i][j] = 'x';   // 'x' represents player 1's pieces
                } else if(i > 4) {
                    board[i][j] = 'o';   // 'o' represents player 2's pieces
                } else {
                    board[i][j] = ' ';   // ' ' represents empty squares
                }
            } else if((i%2 == 1) && (j%2 == 1)) {
                if(i < 3) {
                    board[i][j] = 'x';
                } else if(i > 4) {
                    board[i][j] = 'o';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Print the board
void print_board(char board[][BOARD_SIZE]) {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c | %c | %c | %c | %c | %c\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7]);
        if(i != BOARD_SIZE-1) {
            printf("---+---+---+---+---+---+---+---\n");
        }
    }
    printf("\n");
}

// Check if a move is valid
bool is_valid_move(char player, int from_row, int from_col, int to_row, int to_col, char board[][BOARD_SIZE]) {
    if((to_row < 0) || (to_row >= BOARD_SIZE) || (to_col < 0) || (to_col >= BOARD_SIZE)) {
        // The move is out of the board
        return false;
    }
    if(board[to_row][to_col] != ' ') {
        // The move destination already contains a piece
        return false;
    }
    if((player == 'x') && (board[from_row][from_col] == 'o')) {
        // Player 1 is trying to move player 2's pieces
        return false;
    }
    if((player == 'o') && (board[from_row][from_col] == 'x')) {
        // Player 2 is trying to move player 1's pieces
        return false;
    }
    if((abs(to_row-from_row) != 1) || (abs(to_col-from_col) != 1)) {
        // The move is not a diagonal one
        return false;
    }
    if((player == 'x') && (to_row <= from_row)) {
        // Player 1 is trying to move backwards
        return false;
    }
    if((player == 'o') && (to_row >= from_row)) {
        // Player 2 is trying to move backwards
        return false;
    }
    return true;
}

// Move a piece and capture opponent's pieces if possible
bool move_piece(char player, int from_row, int from_col, int to_row, int to_col, char board[][BOARD_SIZE]) {
    if(is_valid_move(player, from_row, from_col, to_row, to_col, board)) {
        board[to_row][to_col] = board[from_row][from_col];
        board[from_row][from_col] = ' ';
        if((to_row - from_row == 2) && (abs(to_col - from_col) == 2)) {
            // The move is a capture
            int captured_row = (to_row + from_row) / 2;
            int captured_col = (to_col + from_col) / 2;
            board[captured_row][captured_col] = ' ';
        }
        return true;
    }
    return false;
}

// Check if there are any valid moves for a player
bool has_valid_moves(char player, char board[][BOARD_SIZE]) {
    bool can_move = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                // This piece belongs to the player
                if(is_valid_move(player, i, j, i+1, j+1, board) ||
                   is_valid_move(player, i, j, i+1, j-1, board) ||
                   is_valid_move(player, i, j, i-1, j+1, board) ||
                   is_valid_move(player, i, j, i-1, j-1, board)) {
                    // There is at least one valid move for the player
                    can_move = true;
                    break;
                }
            }
        }
        if(can_move) {
            break;
        }
    }
    return can_move;
}

// Check if a player has won
bool has_won(char player, char board[][BOARD_SIZE]) {
    bool has_pieces = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                // The player has at least one piece left on the board
                has_pieces = true;
                if(has_valid_moves(player, board)) {
                    // The player can still make moves
                    return false;
                }
            }
        }
    }
    return has_pieces;   // The player has no pieces left or cannot move
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player = 'x';   // Player 1 starts first

    initialize_board(board);
    print_board(board);

    while(!has_won('x', board) && !has_won('o', board)) {
        // Loop until one of the players wins
        int from_row, from_col, to_row, to_col;
        do {
            printf("Player %c's turn. Enter move (row from, column from, row to, column to): ", player);
            scanf("%d%d%d%d", &from_row, &from_col, &to_row, &to_col);
        } while(!move_piece(player, from_row, from_col, to_row, to_col, board));
        print_board(board);
        if(has_won(player, board)) {
            printf("Player %c has won the game!\n", player);
            break;
        }
        if(has_valid_moves(player == 'x' ? 'o' : 'x', board)) {
            // Switch player if the current player can no longer make moves
            player = player == 'x' ? 'o' : 'x';
        } else {
            printf("Player %c has no valid moves. Skipping turn...\n", player);
        }
    }

    return 0;
}