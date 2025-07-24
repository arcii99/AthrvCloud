//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(char maze[][COLS], int row, int col);
void printMaze(char maze[][COLS]);

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize maze with all walls
    char maze[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }
    
    // Generate maze
    generateMaze(maze, 0, 0);
    
    // Print maze
    printMaze(maze);
    
    return 0;
}

void generateMaze(char maze[][COLS], int row, int col) {
    // Mark current cell as walkable
    maze[row][col] = ' ';
    
    // Get direction of random unvisited neighbor cell
    int dirs[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = dirs[r];
        dirs[r] = dirs[i];
        dirs[i] = temp;
    }
    
    for(int i = 0; i < 4; i++) {
        int dir = dirs[i];
        int nRow, nCol;
        switch(dir) {
            case 0:
                nRow = row - 1;
                nCol = col;
                break;
            case 1:
                nRow = row;
                nCol = col + 1;
                break;
            case 2:
                nRow = row + 1;
                nCol = col;
                break;
            case 3:
                nRow = row;
                nCol = col - 1;
                break;
        }
        
        if(nRow < 0 || nRow >= ROWS || nCol < 0 || nCol >= COLS || maze[nRow][nCol] != '#')
            continue;
        
        // Remove the wall between current cell and neighbor
        if(nRow < row) {
            maze[row-1][col] = ' ';
        } else if(nRow > row) {
            maze[row+1][col] = ' ';
        } else if(nCol < col) {
            maze[row][col-1] = ' ';
        } else if(nCol > col) {
            maze[row][col+1] = ' ';
        }
        
        // Recurse on neighbor cell
        generateMaze(maze, nRow, nCol);
    }
}

void printMaze(char maze[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}