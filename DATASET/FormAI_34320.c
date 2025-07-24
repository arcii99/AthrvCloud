//FormAI DATASET v1.0 Category: Game ; Style: grateful
// A Grateful C Game Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void displayGrid(int grid[3][3]);
void updateGrid(int grid[3][3], int row, int col, int player);
int checkWinner(int grid[3][3]);

// main function
int main() {
    int grid[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int player = 1;
    int row, col, winner;
    
    // seed random number generator
    srand(time(NULL));
    
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Player 1: X\nPlayer 2: O\n\n");
    
    // game loop
    do {
        displayGrid(grid);
        printf("Player %d, enter a row and column: ", player);
        scanf("%d %d", &row, &col);
        
        // check for valid input
        if (row<1 || row>3 || col<1 || col>3) {
            printf("Invalid input! Please try again.\n");
            continue;
        }
        // check if cell is empty
        if (grid[row-1][col-1] != 0) {
            printf("That cell is already occupied! Please try again.\n");
            continue;
        }
        
        updateGrid(grid, row-1, col-1, player); // update grid
        winner = checkWinner(grid); // check for winner
        
        if (winner != 0) {
            displayGrid(grid);
            printf("Congratulations, Player %d! You won!\n", winner);
            break; // exit game loop
        }
        
        // switch players
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    } while (winner == 0);
    
    printf("\nThank you for playing Tic Tac Toe!\n");
    
    return 0;
}

// display grid
void displayGrid(int grid[3][3]) {
    printf("\n");
    for (int i=0; i<3; i++) {
        printf("   ");
        for (int j=0; j<3; j++) {
            if (grid[i][j] == 0)
                printf(" ");
            else if (grid[i][j] == 1)
                printf("X");
            else
                printf("O");
            
            if (j < 2)
                printf(" | ");
        }
        if (i < 2) {
            printf("\n");
            printf("---|---|---\n");
        }
    }
    printf("\n\n");
}

// update grid
void updateGrid(int grid[3][3], int row, int col, int player) {
    grid[row][col] = player;
}

// check for winner
int checkWinner(int grid[3][3]) {
    for (int i=0; i<3; i++) {
        // check rows
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != 0) {
            return grid[i][0];
        }
        // check columns
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != 0) {
            return grid[0][i];
        }
    }
    // check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != 0) {
        return grid[0][0];
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != 0) {
        return grid[0][2];
    }
    // check for tie
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (grid[i][j] == 0)
                return 0;
        }
    }
    return -1; // tie
}