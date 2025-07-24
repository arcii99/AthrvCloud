//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>

#define COLS 10		// Number of columns
#define ROWS 10		// Number of rows

int initialState[ROWS][COLS] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int main() {
    int i, j;
    int iteration = 0;
    int currentGeneration[ROWS][COLS];
    int nextGeneration[ROWS][COLS];
    int aliveNeighbours;
    
    // Initialize current generation with initial state
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            currentGeneration[i][j] = initialState[i][j];
        }
    }
    
    printf("\nInitial Generation:\n\n");
    
    // Print initial generation
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (currentGeneration[i][j]) {
                printf("O ");	// Alive cell
            } else {
                printf(". ");	// Dead cell
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Run iterations
    do {
        // Initialize next generation
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                nextGeneration[i][j] = 0;
            }
        }
        
        // Calculate next generation
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                // Check surrounding cells
                aliveNeighbours = 0;
                
                // Top row
                if (i > 0) {
                    // Top left
                    if (j > 0 && currentGeneration[i-1][j-1]) {
                        aliveNeighbours++;
                    }
                    
                    // Top centre
                    if (currentGeneration[i-1][j]) {
                        aliveNeighbours++;
                    }
                    
                    // Top right
                    if (j < (COLS - 1) && currentGeneration[i-1][j+1]) {
                        aliveNeighbours++;
                    }
                }
                
                // Middle row
                // Middle left
                if (j > 0 && currentGeneration[i][j-1]) {
                    aliveNeighbours++;
                }
                
                // Middle right
                if (j < (COLS - 1) && currentGeneration[i][j+1]) {
                    aliveNeighbours++;
                }
                
                // Bottom row
                if (i < (ROWS - 1)) {
                    // Bottom left
                    if (j > 0 && currentGeneration[i+1][j-1]) {
                        aliveNeighbours++;
                    }
                    
                    // Bottom centre
                    if (currentGeneration[i+1][j]) {
                        aliveNeighbours++;
                    }
                    
                    // Bottom right
                    if (j < (COLS - 1) && currentGeneration[i+1][j+1]) {
                        aliveNeighbours++;
                    }
                }
                
                // Apply rules to current cell
                if (currentGeneration[i][j]) {	// Alive cell
                    if (aliveNeighbours == 2 || aliveNeighbours == 3) {
                        nextGeneration[i][j] = 1;	// Cell stays alive
                    }
                } else {	// Dead cell
                    if (aliveNeighbours == 3) {
                        nextGeneration[i][j] = 1;	// Cell becomes alive
                    }
                }
            }
        }
        
        printf("Iteration %d:\n\n", iteration+1);
        
        // Print next generation
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                currentGeneration[i][j] = nextGeneration[i][j];
                if (currentGeneration[i][j]) {
                    printf("O ");	// Alive cell
                } else {
                    printf(". ");	// Dead cell
                }
            }
            printf("\n");
        }
        
        printf("\n");
        
        iteration++;
    } while (iteration < 5);	// Limit number of iterations (optional)
    
    return 0;
}