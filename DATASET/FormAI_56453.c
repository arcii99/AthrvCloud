//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

void create_maze(int maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    srand(time(NULL));
    int i, j;
    
    // Fill the maze with walls
    for (i = 0; i < MAZE_WIDTH; i++) {
        for (j = 0; j < MAZE_HEIGHT; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Set the entrance and exit
    maze[0][0] = 0;
    maze[MAZE_WIDTH - 1][MAZE_HEIGHT - 1] = 0;
    
    // Generate the maze
    int x = 1;
    int y = 1;
    maze[x][y] = 0;
    
    while (x < MAZE_WIDTH - 1 && y < MAZE_HEIGHT - 1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // North
                if (maze[x][y - 2] != 0) {
                    maze[x][y - 1] = 0;
                    maze[x][y - 2] = 0;
                    y -= 2;
                }
                break;
            case 1: // East
                if (maze[x + 2][y] != 0) {
                    maze[x + 1][y] = 0;
                    maze[x + 2][y] = 0;
                    x += 2;
                }
                break;
            case 2: // South
                if (maze[x][y + 2] != 0) {
                    maze[x][y + 1] = 0;
                    maze[x][y + 2] = 0;
                    y += 2;
                }
                break;
            case 3: // West
                if (maze[x - 2][y] != 0) {
                    maze[x - 1][y] = 0;
                    maze[x - 2][y] = 0;
                    x -= 2;
                }
                break;
        }
    }
}

void print_maze(int maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    int i, j;
    for (i = 0; i < MAZE_WIDTH; i++) {
        for (j = 0; j < MAZE_HEIGHT; j++) {
            if (maze[i][j] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[MAZE_WIDTH][MAZE_HEIGHT];
    create_maze(maze);
    print_maze(maze);
    return 0;
}