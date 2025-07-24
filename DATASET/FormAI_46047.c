//FormAI DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function declarations
void initializeBoard(char board[][COLS], int rows);
void displayBoard(char board[][COLS], int rows);
int countAliveNeighbors(char board[][COLS], int x, int y);
void updateBoard(char board[][COLS], int rows);
int isCellAlive(char board[][COLS], int x, int y);

int main()
{
    char board[ROWS][COLS]; // The game board
    
    // Initialize the board and display it
    initializeBoard(board, ROWS);
    displayBoard(board, ROWS);
    
    // Play the game
    while(1) {
        updateBoard(board, ROWS);
        displayBoard(board, ROWS);
        getchar(); // Wait for user to press enter
    }

    return 0;
}

// Initialize the board with random alive or dead cells
void initializeBoard(char board[][COLS], int rows) {
    int i, j;
    srand(time(NULL)); // Use current time as seed for random generator
    for(i = 0; i < rows; i++) {
        for(j = 0; j < COLS; j++) {
            if(rand() % 2 == 0)
                board[i][j] = 'X'; // Cell is alive
            else
                board[i][j] = '.'; // Cell is dead
        }
    }
}

// Display the board to the console
void displayBoard(char board[][COLS], int rows) {
    int i, j;
    printf("  ");
    for(i = 0; i < COLS; i++)
        printf("%d ", i);
    printf("\n");
    for(i = 0; i < rows; i++) {
        printf("%d ", i);
        for(j = 0; j < COLS; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

// Count the number of alive neighbors around a cell
int countAliveNeighbors(char board[][COLS], int x, int y) {
    int count = 0, i, j;
    for(i = x - 1; i <= x + 1; i++) {
        for(j = y - 1; j <= y + 1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == x && j == y)) {
                if(board[i][j] == 'X')
                    count++;
            }
        }
    }
    return count;
}

// Update the board according to the rules of Game of Life
void updateBoard(char board[][COLS], int rows) {
    int i, j;
    char newBoard[ROWS][COLS]; // Create a new board to store the updated cells
    for(i = 0; i < rows; i++) {
        for(j = 0; j < COLS; j++) {
            int neighbors = countAliveNeighbors(board, i, j);
            if(isCellAlive(board, i, j)) {
                if(neighbors == 2 || neighbors == 3)
                    newBoard[i][j] = 'X'; // Cell stays alive
                else
                    newBoard[i][j] = '.'; // Cell dies
            }
            else {
                if(neighbors == 3)
                    newBoard[i][j] = 'X'; // Cell becomes alive
                else
                    newBoard[i][j] = '.'; // Cell stays dead
            }
        }
    }
    // Update the original board with the new board
    for(i = 0; i < rows; i++)
        for(j = 0; j < COLS; j++)
            board[i][j] = newBoard[i][j];
}

// Check if a cell is alive
int isCellAlive(char board[][COLS], int x, int y) {
    return (board[x][y] == 'X');
}