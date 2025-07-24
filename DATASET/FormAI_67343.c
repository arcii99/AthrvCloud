//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_maze(int maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(maze[i][j] == 0) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int maze[ROWS][COLS]) {
    int x = 0, y = 0;

    // Set starting point to 1
    maze[x][y] = 1;

    // Move through the maze until we reach the end
    while(x < ROWS-1 || y < COLS-1) {
        int direction = rand() % 4;

        // Move up
        if(direction == 0 && x > 0 && maze[x-1][y] == 0) {
            maze[--x][y] = 1;
        }
        // Move down
        else if(direction == 1 && x < ROWS-1 && maze[x+1][y] == 0) {
            maze[++x][y] = 1;
        }
        // Move left
        else if(direction == 2 && y > 0 && maze[x][y-1] == 0) {
            maze[x][--y] = 1;
        }
        // Move right
        else if(direction == 3 && y < COLS-1 && maze[x][y+1] == 0) {
            maze[x][++y] = 1;
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {0};
    srand(time(NULL));
    generate_maze(maze);
    printf("Maze:\n");
    print_maze(maze);
    return 0;
}