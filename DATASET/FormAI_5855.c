//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6

int main(void) {
    int board[ROWS][COLS];  // initialize board array
    int value = -1;
    
    srand(time(NULL));  // seed randomizer
    
    // initialize board values to -1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = value;  
        }
    }
    
    // fill in random value for each cell in board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            value = rand() % 99 + 1;  // random number between 1-99
            board[i][j] = value;
        }
    }
    
    // print out board contents
    printf("Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    int player1_score = 0;
    int player2_score = 0;
    int player_turn = 1;
    
    // play game until all cells have been uncovered
    while (value != ROWS*COLS) {
        int row;
        int col;
        
        // prompt player to enter row and column values
        printf("Player %d, enter your row and column values: ", player_turn);
        scanf("%d %d", &row, &col);
        
        // if cell has already been uncovered, prompt player to enter new values
        while (board[row][col] == -1) {
            printf("That cell has already been uncovered. Enter new values: ");
            scanf("%d %d", &row, &col);
        }
        
        // update player scores
        if (player_turn == 1) {
            player1_score += board[row][col];
        } else {
            player2_score += board[row][col];
        }
        
        // uncover cell and print updated board contents
        board[row][col] = -1;
        printf("Board:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        
        // switch player turn
        if (player_turn == 1) {
            player_turn = 2;
        } else {
            player_turn = 1;
        }
        
        // update number of uncovered cells
        value = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == -1) {
                    value++;
                }
            }
        }
    }
    
    // determine winner of the game and print out scores
    printf("Game over!\n");
    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);
    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}