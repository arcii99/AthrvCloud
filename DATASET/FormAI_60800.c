//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Function Declarations
void initBoard(int board[][WIDTH]);
void displayBoard(int board[][WIDTH]);

int main() {
    // Initialize the Random Seed
    srand(time(NULL));
    
    // Initialize the Game Board
    int board[HEIGHT][WIDTH];
    initBoard(board);
    
    // Game Loop
    while (1) {
        // Clear the Console Screen
        system("clear");
        
        // Display the Game Board
        displayBoard(board);
        
        // Array to Store the Next Generation of the Game Board
        int nextBoard[HEIGHT][WIDTH];
        
        // Calculate the Next Generation of the Game Board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                // Count the Number of Live Neighbors
                int liveNeighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        int row = (x + HEIGHT) % HEIGHT;
                        int col = (y + WIDTH) % WIDTH;
                        if (board[row][col]) {
                            liveNeighbors++;
                        }
                    }
                }
                if (board[i][j]) {
                    liveNeighbors--;
                }
                
                // Calculate the Next State of the Cell
                if (board[i][j] && liveNeighbors < 2) {
                    nextBoard[i][j] = 0; // Underpopulation
                } else if (board[i][j] && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    nextBoard[i][j] = 1; // Survives
                } else if (board[i][j] && liveNeighbors > 3) {
                    nextBoard[i][j] = 0; // Overpopulation
                } else if (!board[i][j] && liveNeighbors == 3) {
                    nextBoard[i][j] = 1; // Reproduction
                } else {
                    nextBoard[i][j] = board[i][j]; // No Change
                }
            }
        }
        
        // Update the Game Board with the Next Generation
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                board[i][j] = nextBoard[i][j];
            }
        }
        
        // Sleep for 100 Milliseconds
        usleep(100000);
    }
    
    return 0;
}

void initBoard(int board[][WIDTH]) {
    // Generate a Random Game Board with 40% of Live Cells
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = (rand() % 100 < 40);
        }
    }
}

void displayBoard(int board[][WIDTH]) {
    // Top Border
    printf("+");
    for (int j = 0; j < WIDTH; j++) {
        printf("-");
    }
    printf("+\n");
    
    // Game Board
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j] ? '#' : '.');
        }
        printf("|\n");
    }
    
    // Bottom Border
    printf("+");
    for (int j = 0; j < WIDTH; j++) {
        printf("-");
    }
    printf("+\n");
}