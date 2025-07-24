//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 20

// Function to initialize the maze
void init_maze(int maze[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

// Function to print the maze
void print_maze(int maze[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(maze[i][j] == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate the maze
void generate_maze(int maze[ROW][COL], int startX, int startY) {
    maze[startX][startY] = 1;
    int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int carv_count = 1;
    while(carv_count < (ROW * COL)) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if(maze[x][y] == 1) {
            int carv = 0;
            for(int i = 0; i < 4; i++) {
                int x1 = x + moves[i][0];
                int y1 = y + moves[i][1];
                if(x1 >= ROW || x1 < 0 || y1 >= COL || y1 < 0) {
                    continue;
                }
                if(maze[x1][y1] == 1) {
                    carv++;
                }
            }
            if(carv == 1) {
                maze[x][y] = 0;
                carv_count--;
            }
        } else {
            int carv = 0;
            for(int i = 0; i < 4; i++) {
                int x1 = x + moves[i][0];
                int y1 = y + moves[i][1];
                if(x1 >= ROW || x1 < 0 || y1 >= COL || y1 < 0) {
                    continue;
                }
                if(maze[x1][y1] == 1) {
                    carv++;
                }
            }
            if(carv == 1) {
                maze[x][y] = 1;
                carv_count++;
            }
        }
    }
}

int main() {
    int maze[ROW][COL];
    int startX = rand() % ROW;
    int startY = rand() % COL;

    srand(time(0));

    init_maze(maze);
    generate_maze(maze, startX, startY);
    print_maze(maze);

    return 0;
}