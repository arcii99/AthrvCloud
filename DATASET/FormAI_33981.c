//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int grid[ROWS][COLUMNS];

int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void generateMaze() {
    srand(time(NULL));
    int i, j;
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLUMNS; j++) {
            grid[i][j] = 1;
        }
    }
    
    int startX = generateRandomNumber(0, ROWS-1);
    int startY = generateRandomNumber(0, COLUMNS-1);
    
    grid[startX][startY] = 0;
    
    int currentX = startX;
    int currentY = startY;
    
    while((currentX != 0 && grid[currentX-1][currentY]) || (currentX != ROWS-1 && grid[currentX+1][currentY]) || (currentY != 0 && grid[currentX][currentY-1]) || (currentY != COLUMNS-1 && grid[currentX][currentY+1])) {
        
        while(1) {
            int direction = generateRandomNumber(1, 4);
            
            if(direction == 1 && currentX != 0 && grid[currentX-1][currentY]) {
                grid[currentX-1][currentY] = 0;
                currentX--;
                break;
            }
            
            else if(direction == 2 && currentX != ROWS-1 && grid[currentX+1][currentY]) {
                grid[currentX+1][currentY] = 0;
                currentX++;
                break;
            }
            
            else if(direction == 3 && currentY != 0 && grid[currentX][currentY-1]) {
                grid[currentX][currentY-1] = 0;
                currentY--;
                break;
            }
            
            else if(direction == 4 && currentY != COLUMNS-1 && grid[currentX][currentY+1]) {
                grid[currentX][currentY+1] = 0;
                currentY++;
                break;
            }
        }
    }
    
    grid[startX][startY] = 0;
}

void printMaze() {
    printf(" ");
    int i,j;
    for(i=0; i<COLUMNS*2-1; i++) {
        printf("_");
    }
    printf("\n");
    
    for(i=0; i<ROWS; i++) {
        printf("|");
        for(j=0; j<COLUMNS; j++) {
            if(grid[i][j] == 0) printf(" ");
            else printf("_");
            
            if(j != COLUMNS-1) {
                if(grid[i][j+1] == 0) printf(" ");
                else printf("|");
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();
    
    return 0;
}