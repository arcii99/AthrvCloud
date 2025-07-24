//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 8

void print_maze(int maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(int maze[HEIGHT][WIDTH], int x, int y) {
    maze[y][x] = 0;
    
    int directions[4][2] = {
        {-1, 0}, // West
        {0, -1}, // North
        {1, 0},  // East
        {0, 1}   // South
    };
    
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        
        if (x + dx < 0 || x + dx >= WIDTH || y + dy < 0 || y + dy >= HEIGHT) {
            continue;
        }
        if (maze[y + dy][x + dx] != 1) {
            continue;
        }
        
        maze[y + dy][x + dx] = 0;
        generate_maze(maze, x + dx, y + dy);
    }
}

int main() {
    int maze[HEIGHT][WIDTH];
    
    // Initialize the maze with all walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Set the random seed and start generating the maze from the top-left corner
    srand(time(NULL));
    generate_maze(maze, 0, 0);
    
    print_maze(maze);
    
    return 0;
}