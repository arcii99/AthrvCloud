//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to initialize the game board
void initializeBoard(char board[][30], int rows, int columns) {
    // Set the borders of the board
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(i == 0 || j == 0 || i == rows-1 || j == columns-1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(char board[][30], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        printf("\n");
        for(int j = 0; j < columns; j++) {
            printf("%c", board[i][j]);
        }
    }
    printf("\n\n");
}

// Function to place the Pac-Man in the board
void placePacMan(char board[][30], int rows, int columns, int *pacManX, int *pacManY) {
    // Place Pac-Man in the center of the board
    *pacManX = rows/2;
    *pacManY = columns/2;
    board[*pacManX][*pacManY] = 'P';
}

int main() {
    // Set the dimensions of the board
    int rows = 20, columns = 30;
    char board[rows][30];

    // Initialize the game board
    initializeBoard(board, rows, columns);

    // Place Pac-Man in the board
    int pacManX, pacManY;
    placePacMan(board, rows, columns, &pacManX, &pacManY);

    // Display the game board
    displayBoard(board, rows, columns);

    return 0;
}