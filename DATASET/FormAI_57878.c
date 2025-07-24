//FormAI DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define ROWS 4
#define COLS 4

// Function to print the grid
void printGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
}

// Function to create a grid with random characters
void createGrid(char grid[ROWS][COLS]) {
    srand(time(NULL));
    char characters[] = {'!', '@', '#', '$', '%', '&', '?', '+', '/', '=', '~', '`', '^', '*', '(', ')', '<', '>', '|', '_', '[', ']', '{', '}'};
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (index >= ROWS * COLS) {
                grid[i][j] = ' '; // Fill the rest of the grid with spaces
            } else {
                grid[i][j] = characters[rand() % 24]; // Choose a random character
                index++;
            }
        }
    }
}

// Function to check if the two chosen cells match
int checkMatch(char grid[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if (grid[row1][col1] == ' ' || grid[row2][col2] == ' ') {
        // If any of the cells are empty, return 0
        return 0;
    } else if (grid[row1][col1] == grid[row2][col2]) {
        // If the cells match, return 1
        return 1;
    } else {
        // If the cells don't match, return -1
        return -1;
    }
}

// Function to clear the grid
void clearGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

int main() {
    char grid[ROWS][COLS];
    int numMatches = 0;
    int numAttempts = 0;
    int row1, col1, row2, col2;
    char input[10];

    printf("Welcome to the Surrealist Memory Game!\n");
    printf("Match the surreal symbols to reveal the hidden message.\n");
    printf("*********************************************\n\n");

    while (1) {

        createGrid(grid); // Create a new grid
        printGrid(grid); // Print the grid

        while (1) {
            printf("Enter the row and column of the first cell (e.g. 1 2): ");
            fgets(input, 10, stdin); // Retrieve input from the user
            sscanf(input, "%d %d", &row1, &col1); // Parse the input
            if (row1 > ROWS || row1 < 1 || col1 > COLS || col1 < 1) {
                printf("Invalid input. Please enter a valid row and column.\n");
            } else {
                break;
            }
        }

        while (1) {
            printf("Enter the row and column of the second cell (e.g. 1 2): ");
            fgets(input, 10, stdin); // Retrieve input from the user
            sscanf(input, "%d %d", &row2, &col2); // Parse the input
            if (row2 > ROWS || row2 < 1 || col2 > COLS || col2 < 1) {
                printf("Invalid input. Please enter a valid row and column.\n");
            } else {
                break;
            }
        }

        int match = checkMatch(grid, row1 - 1, col1 - 1, row2 - 1, col2 - 1); // Check if the cells match

        if (match == 1) {
            printf("Congratulations! You found a match!\n");
            numMatches++;
        } else if (match == -1) {
            printf("Sorry, no match. Try again.\n");
        } else {
            printf("Invalid selection. Please try again.\n");
        }

        numAttempts++;

        if (numMatches == 12) {
            printf("\n\nYou won! The hidden message is:\n\n");
            printf("Would I rather be\n");
            printf("Feared or Loved?\n");
            printf("Easy, both.\n");
            printf("I want people to be afraid of how much they love me.\n\n");
            break;
        }
    }
    return 0;
}