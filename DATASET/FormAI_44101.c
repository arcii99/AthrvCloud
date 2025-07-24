//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int maze[SIZE][SIZE];

void print_maze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    // Initialize the maze with walls on all sides
    for (int i = 0; i < SIZE; i++) {
        maze[i][0] = 1;
        maze[i][SIZE-1] = 1;
        maze[0][i] = 1;
        maze[SIZE-1][i] = 1;
    }
    // Generate the maze with a random depth-first search algorithm
    int stack[SIZE*SIZE][2];
    int top = 0;
    int x = 2, y = 2;
    stack[top][0] = x;
    stack[top][1] = y;
    while (top >= 0) {
        // Pop the top cell off the stack
        x = stack[top][0];
        y = stack[top][1];
        top--;
        // Make sure the cell hasn't already been visited
        if (maze[x][y] == 0) {
            // Mark the cell as visited
            maze[x][y] = 1;
            // Add the neighboring cells to the stack
            if (maze[x-2][y] == 0) {
                top++;
                stack[top][0] = x-2;
                stack[top][1] = y;
            }
            if (maze[x+2][y] == 0) {
                top++;
                stack[top][0] = x+2;
                stack[top][1] = y;
            }
            if (maze[x][y-2] == 0) {
                top++;
                stack[top][0] = x;
                stack[top][1] = y-2;
            }
            if (maze[x][y+2] == 0) {
                top++;
                stack[top][0] = x;
                stack[top][1] = y+2;
            }
        }
    }
    // Add a start and goal to the maze
    maze[1][1] = 0;
    maze[SIZE-2][SIZE-2] = 0;
    // Print the maze
    print_maze();
    return 0;
}