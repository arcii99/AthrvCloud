//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // Number of rows
#define COLS 10 // Number of columns
#define SPACESHIP_ROW 4 // Row of the spaceship
#define SHIP_SYMBOL "S" // Spaceship symbol
#define ALIEN_SYMBOL "A" // Alien symbol
#define DEAD_SYMBOL " " // Dead alien symbol
#define BULLET_SYMBOL "^" // Bullet symbol

void printGrid(char grid[ROWS][COLS]) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("| %c ", grid[row][col]);
        }
        printf("|\n");
    }
    printf("\n");
}

void createSpaceship(char grid[ROWS][COLS]) {
    grid[SPACESHIP_ROW][COLS / 2] = SHIP_SYMBOL;
}

void moveSpaceshipLeft(char grid[ROWS][COLS], int* spaceshipColPtr) {
    int newSpaceshipCol = *spaceshipColPtr - 1;
    
    if(newSpaceshipCol >= 0) {
        grid[SPACESHIP_ROW][*spaceshipColPtr] = DEAD_SYMBOL;
        *spaceshipColPtr = newSpaceshipCol;
        grid[SPACESHIP_ROW][*spaceshipColPtr] = SHIP_SYMBOL;
    }
}

void moveSpaceshipRight(char grid[ROWS][COLS], int* spaceshipColPtr) {
    int newSpaceshipCol = *spaceshipColPtr + 1;
    
    if(newSpaceshipCol < COLS) {
        grid[SPACESHIP_ROW][*spaceshipColPtr] = DEAD_SYMBOL;
        *spaceshipColPtr = newSpaceshipCol;
        grid[SPACESHIP_ROW][*spaceshipColPtr] = SHIP_SYMBOL;
    }
}

int moveAliens(char grid[ROWS][COLS], int steps) {
    int numDeadAliens = 0;
    
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(grid[row][col] == ALIEN_SYMBOL) {
                if(steps % 2 == 0) { // Move left
                    if(col > 0) {
                        if(grid[row][col - 1] != BULLET_SYMBOL) {
                            grid[row][col] = DEAD_SYMBOL;
                            grid[row][col - 1] = ALIEN_SYMBOL;
                        }
                    } else {
                        return -1; // Aliens reach the spaceship
                    }
                } else { // Move right
                    if(col < COLS - 1) {
                        if(grid[row][col + 1] != BULLET_SYMBOL) {
                            grid[row][col] = DEAD_SYMBOL;
                            grid[row][col + 1] = ALIEN_SYMBOL;
                        }
                    } else {
                        return -1; // Aliens reach the spaceship
                    }
                }
            }
        }
    }
    
    return numDeadAliens;
}

void moveBullet(char grid[ROWS][COLS], int* bulletRowPtr, int* bulletColPtr, int direction) {
    if(direction == 1) { // Move up
        if(*bulletRowPtr > 0) {
            grid[*bulletRowPtr][*bulletColPtr] = DEAD_SYMBOL;
            (*bulletRowPtr)--;
            grid[*bulletRowPtr][*bulletColPtr] = BULLET_SYMBOL;
        }
    } else if(direction == -1) { // Move down
        if(*bulletRowPtr < ROWS - 1) {
            grid[*bulletRowPtr][*bulletColPtr] = DEAD_SYMBOL;
            (*bulletRowPtr)++;
            grid[*bulletRowPtr][*bulletColPtr] = BULLET_SYMBOL;
        }
    }
}

int main() {
    srand((unsigned int) time(NULL)); // Seed the random number generator
    char grid[ROWS][COLS];
    int spaceshipCol = COLS / 2;
    int bulletRow = SPACESHIP_ROW - 1;
    int bulletCol = spaceshipCol;
    int steps = 0;
    int score = 0;
    createSpaceship(grid);

    // Initial aliens
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < COLS; col++) {
            grid[row][col] = ALIEN_SYMBOL;
        }
    }
    printGrid(grid);

    while(1) {
        steps++;
        int numDeadAliens = moveAliens(grid, steps);
        
        if(numDeadAliens < 0) { // Aliens reach the spaceship
            printf("Game over! You scored %d points.\n", score);
            break;
        }
        
        if(numDeadAliens > 0) {
            score += numDeadAliens * 10;
        }
        
        printf("Score: %d\n", score);
        printf("Enter command (a/d/s/space): ");
        char command;
        scanf(" %c", &command);
        
        switch(command) {
            case 'a':
                moveSpaceshipLeft(grid, &spaceshipCol);
                break;
            case 'd':
                moveSpaceshipRight(grid, &spaceshipCol);
                break;
            case 's':
                // Do nothing
                break;
            case ' ':
                moveBullet(grid, &bulletRow, &bulletCol, -1);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
        
        moveBullet(grid, &bulletRow, &bulletCol, 1);
        printGrid(grid);
    }
    
    return 0;
}