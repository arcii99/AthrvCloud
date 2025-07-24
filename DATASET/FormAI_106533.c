//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY '_'
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function to print the checker board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if move is valid
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int curr_row, int curr_col, int dest_row, int dest_col, char player) {
    // Check if destination is out of bounds
    if(dest_row < 0 || dest_row >= BOARD_SIZE || dest_col < 0 || dest_col >= BOARD_SIZE) {
        return 0;
    }
    
    // Check if destination is not empty
    if(board[dest_row][dest_col] != EMPTY) {
        return 0;
    }
    
    // Check if player can move diagonally
    int diff_row = abs(dest_row - curr_row);
    int diff_col = abs(dest_col - curr_col);
    if(diff_row != 1 || diff_col != 1) {
        return 0;
    }
    
    // Check if player is moving their own piece
    if(player == PLAYER1 && board[curr_row][curr_col] != PLAYER1) {
        return 0;
    }
    if(player == PLAYER2 && board[curr_row][curr_col] != PLAYER2) {
        return 0;
    }
    
    return 1;
}

// Function to move a piece
void move_piece(char board[BOARD_SIZE][BOARD_SIZE], int curr_row, int curr_col, int dest_row, int dest_col) {
    board[dest_row][dest_col] = board[curr_row][curr_col];
    board[curr_row][curr_col] = EMPTY;
}

int main() {
    // Initialize board
    char board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(i == 0 || i == 2) {
                if(j % 2 == 0) {
                    board[i][j] = PLAYER1;
                } else {
                    board[i][j] = EMPTY;
                }
            } else if(i == 1) {
                if(j % 2 == 0) {
                    board[i][j] = EMPTY;
                } else {
                    board[i][j] = PLAYER1;
                }
            } else if(i == 5 || i == 7) {
                if(j % 2 == 0) {
                    board[i][j] = PLAYER2;
                } else {
                    board[i][j] = EMPTY;
                }
            } else if(i == 6) {
                if(j % 2 == 0) {
                    board[i][j] = EMPTY;
                } else {
                    board[i][j] = PLAYER2;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
    
    // Game loop
    int player_turn = 1;
    while(1) {
        // Print board
        printf("\nPlayer %d's turn:\n", player_turn);
        print_board(board);
        
        // Get move from player
        int curr_row, curr_col, dest_row, dest_col;
        printf("Enter current row: ");
        scanf("%d", &curr_row);
        printf("Enter current column: ");
        scanf("%d", &curr_col);
        printf("Enter destination row: ");
        scanf("%d", &dest_row);
        printf("Enter destination column: ");
        scanf("%d", &dest_col);
        
        // Check if move is valid and move the piece
        if(is_valid_move(board, curr_row-1, curr_col-1, dest_row-1, dest_col-1, player_turn == 1 ? PLAYER1 : PLAYER2)) {
            move_piece(board, curr_row-1, curr_col-1, dest_row-1, dest_col-1);
        } else {
            printf("Invalid move.\n");
            continue;
        }
        
        // Check if there are any winners
        int player1_count = 0;
        int player2_count = 0;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == PLAYER1) {
                    player1_count++;
                } else if(board[i][j] == PLAYER2) {
                    player2_count++;
                }
            }
        }
        
        if(player1_count == 0) {
            printf("\nPlayer 2 wins!\n");
            break;
        } else if(player2_count == 0) {
            printf("\nPlayer 1 wins!\n");
            break;
        }
        
        // Switch turns
        player_turn = player_turn == 1 ? 2 : 1;
    }
    
    return 0;
}