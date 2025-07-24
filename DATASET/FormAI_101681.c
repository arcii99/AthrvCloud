//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// function declarations
void initMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);
void generateMaze(int maze[ROWS][COLS], int r, int c);
void dfs(int maze[ROWS][COLS], int r, int c, int visited[ROWS][COLS]);

// main function
int main() {
    int maze[ROWS][COLS];
    
    // initialize maze with walls
    initMaze(maze);
    
    // set seed for random number generator
    srand(time(0));
    
    // generate maze starting from top-left corner
    generateMaze(maze, 0, 0);
    
    // print generated maze
    printMaze(maze);
    
    return 0;
}

// function to initialize maze with walls
void initMaze(int maze[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

// function to print maze
void printMaze(int maze[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// function to generate maze using depth first search
void generateMaze(int maze[ROWS][COLS], int r, int c) {
    int visited[ROWS][COLS]; // array to keep track of visited cells
    
    // initialize visited array to all zeros
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }
    
    dfs(maze, r, c, visited);
}

void dfs(int maze[ROWS][COLS], int r, int c, int visited[ROWS][COLS]) {
    visited[r][c] = 1; // mark cell as visited
    
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, down, left
    
    // shuffle directions randomly
    for(int i = 0; i < 3; i++) {
        int j = rand() % 4;
        int temp1 = directions[i][0];
        int temp2 = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = temp1;
        directions[j][1] = temp2;
    }
    
    // visit neighbour cells in random order
    for(int i = 0; i < 4; i++) {
        int nr = r + directions[i][0];
        int nc = c + directions[i][1];
        
        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && !visited[nr][nc]) {
            // remove wall between current cell and neighbour cell
            if(directions[i][0] == -1) { // up
                maze[r][c] &= ~(1 << 0);
                maze[nr][nc] &= ~(1 << 2);
            } else if(directions[i][1] == 1) { // right
                maze[r][c] &= ~(1 << 1);
                maze[nr][nc] &= ~(1 << 3);
            } else if(directions[i][0] == 1) { // down
                maze[r][c] &= ~(1 << 2);
                maze[nr][nc] &= ~(1 << 0);
            } else if(directions[i][1] == -1) { // left
                maze[r][c] &= ~(1 << 3);
                maze[nr][nc] &= ~(1 << 1);
            }
            dfs(maze, nr, nc, visited);
        }
    }
}