//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

typedef struct {
    int x, y;
} Point;

void print_maze(int maze[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[MAZE_SIZE][MAZE_SIZE];
    srand(time(NULL));
    
    // initialize maze
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = 0;
        }
    }
    
    // generate maze
    Point current = {rand() % MAZE_SIZE, rand() % MAZE_SIZE};
    maze[current.x][current.y] = 1;
    
    while (1) {
        Point nexts[4] = {{current.x - 1, current.y}, {current.x + 1, current.y}, {current.x, current.y - 1}, {current.x, current.y + 1}};
        int count = 0;
        for (int i = 0; i < 4; i++) {
            Point next = nexts[i];
            if (next.x >= 0 && next.x < MAZE_SIZE && next.y >= 0 && next.y < MAZE_SIZE) {
                if (maze[next.x][next.y] == 0) {
                    count++;
                }
            }
        }
        if (count == 0) {
            break;
        }
        int index = rand() % count;
        for (int i = 0; i < 4; i++) {
            Point next = nexts[i];
            if (next.x >= 0 && next.x < MAZE_SIZE && next.y >= 0 && next.y < MAZE_SIZE) {
                if (maze[next.x][next.y] == 0) {
                    if (index == 0) {
                        maze[next.x][next.y] = 1;
                        if (next.x < current.x) {
                            maze[current.x - 1][current.y] = 1;
                        } else if (next.x > current.x) {
                            maze[current.x + 1][current.y] = 1;
                        } else if (next.y < current.y) {
                            maze[current.x][current.y - 1] = 1;
                        } else if (next.y > current.y) {
                            maze[current.x][current.y + 1] = 1;
                        }
                        current = next;
                        break;
                    }
                    index--;
                }
            }
        }
    }
    
    // print maze
    print_maze(maze);
    
    return 0;
}