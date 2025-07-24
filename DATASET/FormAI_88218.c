//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    char grid[ROWS][COLS];
    // Set all grid cells to empty
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = '-';
        }
    }
    // Spawn the player at a random location
    srand(time(NULL));
    int playerRow = rand() % ROWS;
    int playerCol = rand() % COLS;
    grid[playerRow][playerCol] = 'X';
    // Spawn the ghost at a random location
    int ghostRow, ghostCol;
    do {
        ghostRow = rand() % ROWS;
        ghostCol = rand() % COLS;
    } while (ghostRow == playerRow && ghostCol == playerCol);
    grid[ghostRow][ghostCol] = 'G';
    // Print the initial grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    // Game loop
    bool gameOver = false;
    while (!gameOver) {
        // Get player input
        char move;
        printf("Move (up, down, left, right): ");
        scanf(" %c", &move);
        // Move the player
        grid[playerRow][playerCol] = '-';
        switch (move) {
            case 'u':
                if (playerRow > 0) {
                    playerRow--;
                }
                break;
            case 'd':
                if (playerRow < ROWS - 1) {
                    playerRow++;
                }
                break;
            case 'l':
                if (playerCol > 0) {
                    playerCol--;
                }
                break;
            case 'r':
                if (playerCol < COLS - 1) {
                    playerCol++;
                }
                break;
            default:
                printf("Invalid move.\n");
                break;
        }
        grid[playerRow][playerCol] = 'X';
        // Move the ghost
        grid[ghostRow][ghostCol] = '-';
        int ghostMove = rand() % 4;
        switch (ghostMove) {
            case 0:
                if (ghostRow > 0) {
                    ghostRow--;
                }
                break;
            case 1:
                if (ghostRow < ROWS - 1) {
                    ghostRow++;
                }
                break;
            case 2:
                if (ghostCol > 0) {
                    ghostCol--;
                }
                break;
            case 3:
                if (ghostCol < COLS - 1) {
                    ghostCol++;
                }
                break;
        }
        grid[ghostRow][ghostCol] = 'G';
        // Check for game over condition
        if (playerRow == ghostRow && playerCol == ghostCol) {
            printf("Game Over! You were caught by the ghost.\n");
            gameOver = true;
        } else if (playerRow == ROWS - 1 && playerCol == COLS - 1) {
            printf("Congratulations! You have escaped the haunted house.\n");
            gameOver = true;
        } else {
            // Print the updated grid
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%c ", grid[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}