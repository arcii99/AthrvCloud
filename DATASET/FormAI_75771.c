//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

char maze[WIDTH][HEIGHT];

void generateMaze(int x, int y)
{
    if (maze[x][y] != '.') {
        maze[x][y] = '.';
        if (x > 1) {
            if (maze[x-2][y] == ' ')
            {
                maze[x-1][y] = '.';
                generateMaze(x-2, y);
            }
        }
        if (x < WIDTH-2) {
            if (maze[x+2][y] == ' ')
            {
                maze[x+1][y] = '.';
                generateMaze(x+2, y);
            }
        }
        if (y > 1) {
            if (maze[x][y-2] == ' ')
            {
                maze[x][y-1] = '.';
                generateMaze(x, y-2);
            }
        }
        if (y < HEIGHT-2) {
            if (maze[x][y+2] == ' ')
            {
                maze[x][y+1] = '.';
                generateMaze(x, y+2);
            }
        }
    }
}

int main(void) 
{
    srand((unsigned)time(NULL));
    int startX = rand() % (WIDTH/2) * 2;
    int startY = rand() % (HEIGHT/2) * 2;
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            maze[x][y] = ' ';
        }
    }
    generateMaze(startX, startY);
    maze[1][0] = '.';
    maze[WIDTH-2][HEIGHT-1] = '.';
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[x][y] == ' ') {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}