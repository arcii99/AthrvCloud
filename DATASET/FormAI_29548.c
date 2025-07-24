//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Function to set up the game board with checkers pieces
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Set up player 1's checkers
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j] = 'O';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Set up player 2's checkers
    for(int i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j] = 'X';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to print the game board to the console
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  ┌─┬─┬─┬─┬─┬─┬─┬─┐\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d │", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c│", board[i][j]);
        }
        if(i < BOARD_SIZE - 1) {
            printf("\n  ├─┼─┼─┼─┼─┼─┼─┼─┤\n");
        } else {
            printf("\n  └─┴─┴─┴─┴─┴─┴─┴─┘\n");
        }
    }
}

// Function to check if a move is valid
bool is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    // Make sure the starting position isn't empty and contains the player's checker
    if(board[from_row][from_col] != player) {
        return false;
    }

    // Make sure the destination position is empty
    if(board[to_row][to_col] != ' ') {
        return false;
    }

    // If the player is moving diagonally, make sure it's only 1 space unless they're jumping
    if(abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) {
        return true;
    }

    // If the player is jumping, make sure there's an enemy checker to jump over and that the landing spot is empty
    if(abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
        int mid_row = (from_row + to_row) / 2;
        int mid_col = (from_col + to_col) / 2;
        if(board[mid_row][mid_col] == player || board[mid_row][mid_col] == ' ') {
            return false;
        } else {
            return true;
        }
    }

    return false; // If neither condition is met, the move is invalid
}

// Function to check if the game is over
bool is_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check if player 1 has any pieces left
    bool player_1_pieces_left = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 'O') {
                player_1_pieces_left = true;
                break;
            }
        }
        if(player_1_pieces_left) {
            break;
        }
    }
    if(!player_1_pieces_left) {
        printf("Player 2 Wins!\n");
        return true;
    }

    // Check if player 2 has any pieces left
    bool player_2_pieces_left = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 'X') {
                player_2_pieces_left = true;
                break;
            }
        }
        if(player_2_pieces_left) {
            break;
        }
    }
    if(!player_2_pieces_left) {
        printf("Player 1 Wins!\n");
        return true;
    }

    return false; // If neither condition is met, the game is not over
}

// Function to move a checker from one position to another
void move_checker(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    board[from_row][from_col] = ' ';
    board[to_row][to_col] = player;

    // If the player is jumping over an enemy checker, remove it from the board
    if(abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
        int mid_row = (from_row + to_row) / 2;
        int mid_col = (from_col + to_col) / 2;
        board[mid_row][mid_col] = ' ';
    }

    // If the player reaches the opposite side of the board, make their checker into a king
    if(player == 'O' && to_row == BOARD_SIZE - 1) {
        board[to_row][to_col] = 'K';
    } else if(player == 'X' && to_row == 0) {
        board[to_row][to_col] = 'K';
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player = 'O';
    int from_row, from_col, to_row, to_col;

    initialize_board(board);

    while(!is_game_over(board)) {
        print_board(board);
        printf("Player %c's Turn:\n", player);
        printf("From Row: ");
        scanf("%d", &from_row);
        printf("From Column: ");
        scanf("%d", &from_col);
        printf("To Row: ");
        scanf("%d", &to_row);
        printf("To Column: ");
        scanf("%d", &to_col);

        if(is_valid_move(board, from_row, from_col, to_row, to_col, player)) {
            move_checker(board, from_row, from_col, to_row, to_col, player);
            // If the player had to jump, they get to continue their turn
            if(abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
                continue;
            }
            // Switch to the other player's turn
            if(player == 'O') {
                player = 'X';
            } else {
                player = 'O';
            }
        } else {
            printf("Invalid Move, Try Again.\n");
        }
    }

    return 0;
}