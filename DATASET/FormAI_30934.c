//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_maze(int maze[][COLS]) {
    for(int i = 0; i < ROWS * 2 + 1; i++) {
        for(int j = 0; j < COLS * 2 + 1; j++) {
            if(maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int maze[ROWS * 2 + 1][COLS * 2 + 1];

    // initialize maze borders as walls
    for(int i = 0; i < ROWS * 2 + 1; i++) {
        maze[i][0] = 1;
        maze[i][COLS * 2] = 1;
    }
    for(int j = 0; j < COLS * 2 + 1; j++) {
        maze[0][j] = 1;
        maze[ROWS * 2][j] = 1;
    }

    // generate maze
    int x = 1;
    int y = 1;
    maze[x][y] = 1;
    while(x > 0 && x < ROWS * 2 && y > 0 && y < COLS * 2) {
        maze[x][y] = 1;
        int direction = rand() % 4;
        if(direction == 0 && x >= 2 && maze[x - 2][y] == 0) { // up
            maze[x - 1][y] = 1;
            x -= 2;
        } else if(direction == 1 && y <= COLS * 2 - 2 && maze[x][y + 2] == 0) { // right
            maze[x][y + 1] = 1;
            y += 2;
        } else if(direction == 2 && x <= ROWS * 2 - 2 && maze[x + 2][y] == 0) { // down
            maze[x + 1][y] = 1;
            x += 2;
        } else if(direction == 3 && y >= 2 && maze[x][y - 2] == 0) { // left
            maze[x][y - 1] = 1;
            y -= 2;
        }
    }

    print_maze(maze);

    return 0;
}