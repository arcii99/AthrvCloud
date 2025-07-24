//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 31
#define COLS 51
#define WALL 1
#define PATH 0
#define START_ROW 1
#define START_COL 1
#define END_ROW ROWS - 2
#define END_COL COLS - 2

int maze[ROWS][COLS];

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateMaze() {
    // Initialize maze with all walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // Generate random starting point
    srand(time(NULL));
    int row = START_ROW;
    int col = START_COL;
    maze[row][col] = PATH;
    
    // Generate maze using depth-first search
    while(1) {
        int unvisitedNeighbors = 0;
        if(col > 2 && maze[row][col - 2] == WALL) {
            unvisitedNeighbors++;
        }
        if(row > 2 && maze[row - 2][col] == WALL) {
            unvisitedNeighbors++;
        }
        if(col < COLS - 3 && maze[row][col + 2] == WALL) {
            unvisitedNeighbors++;
        }
        if(row < ROWS - 3 && maze[row + 2][col] == WALL) {
            unvisitedNeighbors++;
        }
        
        if(unvisitedNeighbors == 0) {
            // Backtracking
            int backtrack = 0;
            do {
                backtrack--;
                row -= (row - maze[row][col - 1] != 0) ? row - maze[row][col - 1] : 0;
                col -= (col - maze[row][col - 1] != 0) ? col - maze[row][col - 1] : 0;
            } while(maze[row][col] == PATH);
        } else {
            // Choose a random unvisited neighbor to visit
            int neighbor = rand() % unvisitedNeighbors;
            if(col > 2 && maze[row][col - 2] == WALL && neighbor-- == 0) {
                maze[row][col - 1] = PATH;
                maze[row][col - 2] = PATH;
                col -= 2;
            }
            if(row > 2 && maze[row - 2][col] == WALL && neighbor-- == 0) {
                maze[row - 1][col] = PATH;
                maze[row - 2][col] = PATH;
                row -= 2;
            }
            if(col < COLS - 3 && maze[row][col + 2] == WALL && neighbor-- == 0) {
                maze[row][col + 1] = PATH;
                maze[row][col + 2] = PATH;
                col += 2;
            }
            if(row < ROWS - 3 && maze[row + 2][col] == WALL && neighbor-- == 0) {
                maze[row + 1][col] = PATH;
                maze[row + 2][col] = PATH;
                row += 2;
            }
            
            if(row == END_ROW && col == END_COL) {
                break;
            }
        }
    }
}

int main() {
    generateMaze();
    printMaze();
    return 0;
}