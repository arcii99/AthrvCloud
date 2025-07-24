//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

// Function to print the grid
void printGrid(char grid[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if player has found all the items
bool checkWin(char grid[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            if (grid[row][col] == 'I') {
                return false;
            }
        }
    }
    return true;
}

// Main function
int main() {
    // Initialize grid with all empty spaces
    char grid[ROWS][COLUMNS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            grid[row][col] = '_';
        }
    }
    
    // Add items to the grid
    grid[1][3] = 'I'; // Key
    grid[4][6] = 'I'; // Map
    grid[8][2] = 'I'; // Flashlight
    
    // Add obstacles to the grid
    grid[0][5] = '|';
    grid[1][5] = '|';
    grid[2][5] = '|';
    grid[3][5] = '|';
    grid[4][5] = '|';
    grid[5][5] = '|';
    grid[6][5] = '|';
    grid[7][5] = '|';
    grid[8][5] = '|';
    grid[9][5] = '|';
    
    // Add player to the grid
    int playerRow = 0;
    int playerCol = 0;
    grid[playerRow][playerCol] = 'X'; // Player
    
    // Print instructions
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You must find all the items in the house to escape.\n");
    printf("Move using the arrow keys. Press Q to quit.\n\n");
    
    // Game loop
    while (true) {
        // Print the grid
        printGrid(grid);
        
        // Check for player win
        if (checkWin(grid)) {
            printf("Congratulations! You found all the items and escaped the haunted house.\n");
            break;
        }
        
        // Get user input
        char input = getchar();
        
        // Move the player
        if (input == 'q' || input == 'Q') {
            printf("Goodbye!\n");
            break;
        } else if (input == 'w' || input == 'W') {
            if (playerRow > 0 && grid[playerRow-1][playerCol] != '|') {
                grid[playerRow][playerCol] = '_';
                playerRow--;
                grid[playerRow][playerCol] = 'X';
            }
        } else if (input == 'a' || input == 'A') {
            if (playerCol > 0 && grid[playerRow][playerCol-1] != '|') {
                grid[playerRow][playerCol] = '_';
                playerCol--;
                grid[playerRow][playerCol] = 'X';
            }
        } else if (input == 's' || input == 'S') {
            if (playerRow < ROWS-1 && grid[playerRow+1][playerCol] != '|') {
                grid[playerRow][playerCol] = '_';
                playerRow++;
                grid[playerRow][playerCol] = 'X';
            }
        } else if (input == 'd' || input == 'D') {
            if (playerCol < COLUMNS-1 && grid[playerRow][playerCol+1] != '|') {
                grid[playerRow][playerCol] = '_';
                playerCol++;
                grid[playerRow][playerCol] = 'X';
            }
        }
    }
    
    return 0;
}