//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void generateMaze(int maze[WIDTH][HEIGHT]) {
    srand(time(NULL)); // seed the random number generator
    
    // initialize maze with walls
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            maze[x][y] = 1;
        }
    }
    
    int starting_x = rand() % WIDTH;
    int starting_y = rand() % HEIGHT;
    maze[starting_x][starting_y] = 0; // mark starting point
    
    // recursive depth-first search algorithm to carve out the maze
    int stack[WIDTH * HEIGHT][2]; // stack for backtracking
    int stack_top = 0;
    stack[stack_top][0] = starting_x;
    stack[stack_top][1] = starting_y;
    while (stack_top >= 0) {
        int x = stack[stack_top][0];
        int y = stack[stack_top][1];
        stack_top--;
        
        // find neighbors
        int neighbors[4][2] = {{x-2, y}, {x+2, y}, {x, y-2}, {x, y+2}};
        for (int i = 0; i < 4; i++) {
            int nx = neighbors[i][0];
            int ny = neighbors[i][1];
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                if (maze[nx][ny] == 1) { // unvisited
                    int mx = nx + (x - nx) / 2; // find the neighbor in the direction of (x, y)
                    int my = ny + (y - ny) / 2;
                    maze[mx][my] = 0;
                    maze[nx][ny] = 0;
                    stack_top++;
                    stack[stack_top][0] = nx;
                    stack[stack_top][1] = ny;
                }
            }
        }
    }
}

void printMaze(int maze[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[x][y] == 1) {
                printf("[ ]");
            } else {
                printf("[X]");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[WIDTH][HEIGHT];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}