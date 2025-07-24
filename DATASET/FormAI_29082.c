//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define WIN_SCORE 2048

// Enumeration for movement direction
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Create a random number between min and max
int randomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Print the game grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n");
    
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if the game is over
int isGameOver(int grid[GRID_SIZE][GRID_SIZE]) {
    // Check if any empty cell is available
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(grid[i][j] == 0) {
                return 0;
            }
        }
    }
    
    // Check if any adjacent cells have same value
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(i > 0 && grid[i][j] == grid[i-1][j]) {
                return 0;
            }
            if(i < GRID_SIZE-1 && grid[i][j] == grid[i+1][j]) {
                return 0;
            }
            if(j > 0 && grid[i][j] == grid[i][j-1]) {
                return 0;
            }
            if(j < GRID_SIZE-1 && grid[i][j] == grid[i][j+1]) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Move the tiles in the given direction
void moveTiles(int grid[GRID_SIZE][GRID_SIZE], enum Direction dir) {
    int tmp[GRID_SIZE][GRID_SIZE];
    int mergeFlag = 0;
    
    // Initialize tmp grid
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            tmp[i][j] = 0;
        }
    }
    
    // Move tiles in the given direction
    if(dir == UP) {
        for(int j=0; j<GRID_SIZE; j++) {
            int index = 0;
            
            for(int i=0; i<GRID_SIZE; i++) {
                if(grid[i][j] != 0) {
                    if(tmp[index][j] == grid[i][j] && mergeFlag == 0) {
                        tmp[index][j] *= 2;
                        mergeFlag = 1;
                    }
                    else {
                        tmp[index][j] = grid[i][j];
                        mergeFlag = 0;
                    }
                    index++;
                }
            }
        }
    }
    else if(dir == DOWN) {
        for(int j=0; j<GRID_SIZE; j++) {
            int index = GRID_SIZE-1;
            
            for(int i=GRID_SIZE-1; i>=0; i--) {
                if(grid[i][j] != 0) {
                    if(tmp[index][j] == grid[i][j] && mergeFlag == 0) {
                        tmp[index][j] *= 2;
                        mergeFlag = 1;
                    }
                    else {
                        tmp[index][j] = grid[i][j];
                        mergeFlag = 0;
                    }
                    index--;
                }
            }
        }
    }
    else if(dir == LEFT) {
        for(int i=0; i<GRID_SIZE; i++) {
            int index = 0;
            
            for(int j=0; j<GRID_SIZE; j++) {
                if(grid[i][j] != 0) {
                    if(tmp[i][index] == grid[i][j] && mergeFlag == 0) {
                        tmp[i][index] *= 2;
                        mergeFlag = 1;
                    }
                    else {
                        tmp[i][index] = grid[i][j];
                        mergeFlag = 0;
                    }
                    index++;
                }
            }
        }
    }
    else if(dir == RIGHT) {
        for(int i=0; i<GRID_SIZE; i++) {
            int index = GRID_SIZE-1;
            
            for(int j=GRID_SIZE-1; j>=0; j--) {
                if(grid[i][j] != 0) {
                    if(tmp[i][index] == grid[i][j] && mergeFlag == 0) {
                        tmp[i][index] *= 2;
                        mergeFlag = 1;
                    }
                    else {
                        tmp[i][index] = grid[i][j];
                        mergeFlag = 0;
                    }
                    index--;
                }
            }
        }
    }
    
    // Copy tmp grid to main grid
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

// Add a random tile to the grid
void addRandomTile(int grid[GRID_SIZE][GRID_SIZE]) {
    while(1) {
        int x = randomInRange(0, GRID_SIZE-1);
        int y = randomInRange(0, GRID_SIZE-1);
        
        if(grid[x][y] == 0) {
            grid[x][y] = randomInRange(1, 2) * 2;
            break;
        }
    }
}

// Main function
int main() {
    srand(time(0));
    
    // Initialize grid
    int grid[GRID_SIZE][GRID_SIZE];
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    
    // Add first two tiles
    addRandomTile(grid);
    addRandomTile(grid);
    
    // Print the initial state of the game
    printGrid(grid);
    
    // Game loop
    while(1) {
        // Get user input
        printf("Enter movement direction: ");
        char input = getchar();
        while(getchar() != '\n');
        
        // Handle input
        switch(input) {
            case 'w':
            case 'W':
                moveTiles(grid, UP);
                break;
            case 's':
            case 'S':
                moveTiles(grid, DOWN);
                break;
            case 'a':
            case 'A':
                moveTiles(grid, LEFT);
                break;
            case 'd':
            case 'D':
                moveTiles(grid, RIGHT);
                break;
            default:
                printf("Invalid input!\n");
                continue;
        }
        
        // Add new tile
        addRandomTile(grid);
        
        // Check if game is over
        if(isGameOver(grid)) {
            printf("Game over!\n");
            break;
        }
        
        // Check if win score is achieved
        for(int i=0; i<GRID_SIZE; i++) {
            for(int j=0; j<GRID_SIZE; j++) {
                if(grid[i][j] == WIN_SCORE) {
                    printf("You win!\n");
                    return 0;
                }
            }
        }
        
        // Print updated state of game
        printGrid(grid);
    }
    
    return 0;
}