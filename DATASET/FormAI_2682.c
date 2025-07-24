//FormAI DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[10][10]; // Initialize game board
    int row, col;
    int player1_score = 0, player2_score = 0; // Initialize scores
    srand(time(NULL)); // Set seed for random numbers
    
    // Set up initial game board with tiles numbered 1-100
    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            board[row][col] = (row * 10) + col + 1;
        }
    }
    
    // Shuffle tiles randomly
    for (int i = 0; i < 100; i++) {
        int rand_row1 = rand() % 10;
        int rand_col1 = rand() % 10;
        int rand_row2 = rand() % 10;
        int rand_col2 = rand() % 10;
        int temp = board[rand_row1][rand_col1];
        board[rand_row1][rand_col1] = board[rand_row2][rand_col2];
        board[rand_row2][rand_col2] = temp;
    }
    
    // Print game board
    printf("-------------\n");
    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            printf("|%2d", board[row][col]);
        }
        printf("|\n-------------\n");
    }
    
    // Begin game loop
    for (int turn = 1; turn <= 50; turn++) {
        int tile1_row, tile1_col, tile2_row, tile2_col;
        int match = 0;
        
        // Get player 1's move
        printf("Player 1, choose your first tile (row col): ");
        scanf("%d %d", &tile1_row, &tile1_col);
        printf("Player 1, choose your second tile (row col): ");
        scanf("%d %d", &tile2_row, &tile2_col);
        
        // Check if tiles match
        if (board[tile1_row][tile1_col] == board[tile2_row][tile2_col]) {
            match = 1;
            player1_score += 2;
        }
        
        // Print updated game board and scores
        printf("-------------\n");
        for (row = 0; row < 10; row++) {
            for (col = 0; col < 10; col++) {
                if (row == tile1_row && col == tile1_col) {
                    printf("|  ");
                } else if (row == tile2_row && col == tile2_col) {
                    printf("|  ");
                } else {
                    printf("|%2d", board[row][col]);
                }
            }
            printf("|\n-------------\n");
        }
        printf("Player 1 score: %d\nPlayer 2 score: %d\n", player1_score, player2_score);
        
        // Get player 2's move
        printf("Player 2, choose your first tile (row col): ");
        scanf("%d %d", &tile1_row, &tile1_col);
        printf("Player 2, choose your second tile (row col): ");
        scanf("%d %d", &tile2_row, &tile2_col);
        
        // Check if tiles match
        if (board[tile1_row][tile1_col] == board[tile2_row][tile2_col]) {
            match = 1;
            player2_score += 2;
        }
        
        // Print updated game board and scores
        printf("-------------\n");
        for (row = 0; row < 10; row++) {
            for (col = 0; col < 10; col++) {
                if (row == tile1_row && col == tile1_col) {
                    printf("|  ");
                } else if (row == tile2_row && col == tile2_col) {
                    printf("|  ");
                } else {
                    printf("|%2d", board[row][col]);
                }
            }
            printf("|\n-------------\n");
        }
        printf("Player 1 score: %d\nPlayer 2 score: %d\n", player1_score, player2_score);
        
        // If there is a match, player gets another turn
        if (match) {
            turn--;
        }
    }
    
    // Determine winner
    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}