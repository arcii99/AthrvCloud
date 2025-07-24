//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

// Function to display the board
void display_board(char board[8][8]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board
void initialize_board(char board[8][8]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                board[i][j] = '-';
            } else if(i < 3) {
                board[i][j] = 'b';
            } else if(i > 4) {
                board[i][j] = 'w';
            } else {
                board[i][j] = '-';
            }
        }
    }
}

// Function to check if piece is movable
int is_valid_move(char board[8][8], int from_row, int from_column, int to_row, int to_column, char current_player) {
    // Check if to position already has a piece
    if(board[to_row][to_column] != '-') {
        return 0;
    }
    // Check for diagonal movement by one step
    if((abs(from_row - to_row) == 1) && (abs(from_column - to_column) == 1)) {
        // Check for valid move direction based on current player
        if(current_player == 'w') {
            if(from_row > to_row) {
                return 0;
            }
        } else {
            if(from_row < to_row) {
                return 0;
            }
        }
        return 1;
    }
    // Check for diagonal movement by two steps (jump move)
    if((abs(from_row - to_row) == 2) && (abs(from_column - to_column) == 2)) {
        // Check for valid move direction based on current player
        if(current_player == 'w') {
            if(from_row > to_row) {
                return 0;
            }
        } else {
            if(from_row < to_row) {
                return 0;
            }
        }
        // Check if the middle position has an opponent piece
        int i = (from_row + to_row) / 2;
        int j = (from_column + to_column) / 2;
        if(board[i][j] == '-' || board[i][j] == current_player) {
            return 0;
        }
        return 1;
    }
    return 0;
}

// Function to perform move
void perform_move(char board[8][8], int from_row, int from_column, int to_row, int to_column) {
    board[to_row][to_column] = board[from_row][from_column];
    board[from_row][from_column] = '-';
    // Check if move was a jump move and remove the opponent piece
    if((abs(from_row - to_row) == 2) && (abs(from_column - to_column) == 2)) {
        int i = (from_row + to_row) / 2;
        int j = (from_column + to_column) / 2;
        board[i][j] = '-';
    }
}

// Function to check if game is over
int is_game_over(char board[8][8]) {
    int white_pieces_remaining = 0;
    int black_pieces_remaining = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'w') {
                white_pieces_remaining++;
            } else if(board[i][j] == 'b') {
                black_pieces_remaining++;
            }
        }
    }
    if(white_pieces_remaining == 0 || black_pieces_remaining == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char board[8][8];
    initialize_board(board);
    display_board(board);
    char current_player = 'w'; // white starts first
    while(1) {
        // Get move from current player
        printf("Current player: %c\n", current_player);
        int from_row, from_column, to_row, to_column;
        printf("Enter row and column of piece to move: ");
        scanf("%d %d", &from_row, &from_column);
        printf("Enter row and column of new position: ");
        scanf("%d %d", &to_row, &to_column);
        // Check if move is valid and perform the move
        if(is_valid_move(board, from_row, from_column, to_row, to_column, current_player)) {
            perform_move(board, from_row, from_column, to_row, to_column);
            // Check if game is over
            if(is_game_over(board)) {
                display_board(board);
                printf("Game Over!\nFinal Board:\n");
                if(current_player == 'w') {
                    printf("Black wins!\n");
                } else {
                    printf("White wins!\n");
                }
                break;
            }
            // Switch to next player
            if(current_player == 'w') {
                current_player = 'b';
            } else {
                current_player = 'w';
            }
        } else {
            printf("Invalid move!\n");
        }
        // Display current board position
        display_board(board);
    }
    return 0;
}