//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROW 10
#define COL 10

// Function prototypes
void printGrid(char grid[ROW][COL], int reveal);
void placeMines(char grid[ROW][COL], int numOfMines);
int countMines(char grid[ROW][COL], int row, int col);
void revealTile(char grid[ROW][COL], char reveal[ROW][COL], int row, int col);
void playGame(char grid[ROW][COL]);

int main() {
    // Welcome message
    printf("Welcome to Minesweeper\n");
    printf("************************\n\n");
    
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize game grid
    char grid[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            grid[i][j] = '-';
        }
    }
    
    // Play game
    playGame(grid);
    
    return 0;
}

// Prints the current state of the game grid
void printGrid(char grid[ROW][COL], int reveal) {
    int i, j;
    
    // Print column numbers
    printf("\t");
    for (i = 0; i < COL; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    
    // Print row numbers and grid
    for (i = 0; i < ROW; i++) {
        printf("%d\t", i+1);
        for (j = 0; j < COL; j++) {
            if (grid[i][j] == 'X' && reveal == 1) {
                printf("%c ", grid[i][j]);
            } else if (grid[i][j] != 'X') {
                printf("%c ", grid[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

// Places mines randomly on the grid
void placeMines(char grid[ROW][COL], int numOfMines) {
    int i, j, k;
    
    // Place mines
    for (k = 0; k < numOfMines; k++) {
        i = rand() % ROW;
        j = rand() % COL;
        
        if (grid[i][j] == '-') {
            grid[i][j] = 'X';
        } else {
            k--;
        }
    }
}

// Counts the number of mines adjacent to a tile
int countMines(char grid[ROW][COL], int row, int col) {
    int i, j, count = 0;
    
    // Check surrounding tiles for mines
    for (i = row-1; i <= row+1; i++) {
        for (j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < ROW && j >= 0 && j < COL && grid[i][j] == 'X') {
                count++;
            }
        }
    }
    return count;
}

// Recursively reveals the tiles adjacent to the clicked tile
void revealTile(char grid[ROW][COL], char reveal[ROW][COL], int row, int col) {
    int i, j;
    
    if (row >= 0 && row < ROW && col >= 0 && col < COL && reveal[row][col] == '-') {
        reveal[row][col] = ' ';
        
        if (grid[row][col] == ' ') {
            for (i = row-1; i <= row+1; i++) {
                for (j = col-1; j <= col+1; j++) {
                    revealTile(grid, reveal, i, j);
                }
            }
        }
    }
}

// Plays the game
void playGame(char grid[ROW][COL]) {
    int i, j, numOfMines, numOfTiles, row, col, gameOver = 0;
    char choice;
    
    // Determine number of mines and tiles
    printf("Enter number of mines (0-98): ");
    scanf("%d", &numOfMines);
    printf("\n");
    numOfTiles = ROW * COL - numOfMines;
    
    // Place mines
    placeMines(grid, numOfMines);
    
    // Initialize reveal grid
    char reveal[ROW][COL];
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            reveal[i][j] = '-';
        }
    }
    
    // Play game until all non-mine tiles are revealed
    while (!gameOver) {
        // Print grid
        printGrid(reveal, 0);
        
        // Get user choice
        printf("Enter row and column (ex. 1 2): ");
        scanf("%d %d", &row, &col);
        printf("\n");
        
        // Check for mine or adjacent mines
        if (grid[row-1][col-1] == 'X') {
            reveal[row-1][col-1] = 'X';
            printGrid(reveal, 1);
            printf("Game over!\n");
            gameOver = 1;
        } else {
            int count = countMines(grid, row-1, col-1);
            
            if (count == 0) {
                revealTile(grid, reveal, row-1, col-1);
            } else {
                reveal[row-1][col-1] = count + '0';
            }
            
            // Check for win
            int tilesRevealed = 0;
            for (i = 0; i < ROW; i++) {
                for (j = 0; j < COL; j++) {
                    if (reveal[i][j] != '-') {
                        tilesRevealed++;
                    }
                }
            }
            if (tilesRevealed == numOfTiles) {
                printGrid(reveal, 1);
                printf("You win!\n");
                gameOver = 1;
            }
        }
    }
}