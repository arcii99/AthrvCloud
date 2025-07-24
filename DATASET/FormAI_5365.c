//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int maze[HEIGHT][WIDTH];

void generateMaze(int x, int y)
{
    maze[y][x] = 1;
    
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    srand(time(NULL));
    
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int dx = dirs[r][0];
        int dy = dirs[r][1];
        
        int nx = x + dx;
        int ny = y + dy;
        
        if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT && maze[ny][nx] == 0) {
            maze[y + dy / 2][x + dx / 2] = 1;
            generateMaze(nx, ny);
        }
    }
}

int main()
{
    srand(time(NULL));
    
    // Initialize maze
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 0;
        }
    }
    
    // Generate maze
    generateMaze(0, 0);
    
    // Print maze
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    
    return 0;
}