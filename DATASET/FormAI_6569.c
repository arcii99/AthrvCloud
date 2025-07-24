//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAZE_SIZE 20 // size of the maze (MAZE_SIZE x MAZE_SIZE)

char maze[MAZE_SIZE][MAZE_SIZE]; // the maze itself

// recursively generates the maze
void generateMaze(int x, int y) {
    // mark cell as visited
    maze[x][y] = ' ';
    
    // create array of adjacent cells
    int adjacents[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 
    
    // shuffle the array
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tempX = adjacents[i][0];
        int tempY = adjacents[i][1];
        adjacents[i][0] = adjacents[j][0];
        adjacents[i][1] = adjacents[j][1];
        adjacents[j][0] = tempX;
        adjacents[j][1] = tempY;
    }
    
    // loop through the shuffled array
    for (int i = 0; i < 4; i++) {
        int newX = x + adjacents[i][0];
        int newY = y + adjacents[i][1];
        
        // if the adjacent cell is out of bounds, skip it
        if (newX < 1 || newX >= MAZE_SIZE - 1 || newY < 1 || newY >= MAZE_SIZE - 1) {
            continue;
        }
        
        // if the adjacent cell hasn't been visited yet, create a path
        if (maze[newX][newY] == '#') {
            int midX = (x + newX) / 2;
            int midY = (y + newY) / 2;
            maze[midX][midY] = ' ';
            generateMaze(newX, newY);
        }
    }
}

int main() {
    // seed the random generator
    srand(time(NULL));
    
    // initialize maze with all walls
    memset(maze, '#', sizeof(maze));
    
    // generate maze starting from cell (1,1)
    generateMaze(1, 1);
    
    // print the maze
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}