//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[ROWS][COLS]) {
    int i, j;
    // Initialize maze to all walls
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
    // Create a path through the maze
    int x = 1, y = 1;
    maze[x][y] = 0;
    while(maze[ROWS - 2][COLS - 2]) {
        int dir = rand() % 4;
        if(dir == 0 && x > 1 && maze[x - 2][y]) { // Up
            maze[x - 1][y] = 0;
            maze[x - 2][y] = 0;
            x -= 2;
        } else if(dir == 1 && y < COLS - 2 && maze[x][y + 2]) { // Right
            maze[x][y + 1] = 0;
            maze[x][y + 2] = 0;
            y += 2; 
        } else if(dir == 2 && x < ROWS - 2 && maze[x + 2][y]) { // Down
            maze[x + 1][y] = 0;
            maze[x + 2][y] = 0;
            x += 2;
        } else if(dir == 3 && y > 1 && maze[x][y - 2]) { // Left
            maze[x][y - 1] = 0;
            maze[x][y - 2] = 0;
            y -= 2;
        }
    }
    // Add entrance and exit
    maze[1][0] = 0;
    maze[ROWS - 2][COLS - 1] = 0;
}

void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}