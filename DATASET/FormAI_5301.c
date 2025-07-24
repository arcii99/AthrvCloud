//FormAI DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[][COLS]);
int check_winner(int board[][COLS]);

int main() {
    // Initialize the board
    int board[ROWS][COLS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    int player = 1;
    int row, col;

    // Print the empty board
    print_board(board);

    // Game loop
    while(1) {
        // Get user input
        printf("Player %d enter row and column (example: 1 2): ", player);
        scanf("%d %d", &row, &col);

        // Check if input is valid
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input\n");
            continue;
        }

        // Check if cell is already occupied
        if(board[row][col] != 0) {
            printf("Cell is already occupied\n");
            continue;
        }

        // Update board
        board[row][col] = player;

        // Print updated board
        print_board(board);

        // Check for winner
        int winner = check_winner(board);
        if(winner != 0) {
            printf("Player %d wins!\n", winner);
            break;
        }

        // Check for tie
        int tie = 1;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == 0) {
                    tie = 0;
                    break;
                }
            }
            if(!tie) break;
        }
        if(tie) {
            printf("It's a tie!\n");
            break;
        }

        // Switch player
        player = player == 1 ? 2 : 1;
    }

    return 0;
}

void print_board(int board[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(int board[][COLS]) {
    // Check rows
    for(int i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return board[i][0];
        }
    }

    // Check columns
    for(int j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0) {
            return board[0][j];
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return board[0][2];
    }

    // If no winner, return 0
    return 0;
}