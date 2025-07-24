//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int maze[SIZE][SIZE];

void init_maze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand() % 2;
            }
        }
    }
}

void print_maze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void solve_maze() {
    int x = 1, y = 1;
    maze[x][y] = 2;
    while (x != SIZE - 2 || y != SIZE - 2) {
        if (maze[x][y + 1] == 0) {
            y++;
            maze[x][y] = 2;
        } else if (maze[x + 1][y] == 0) {
            x++;
            maze[x][y] = 2;
        } else if (maze[x][y - 1] == 0) {
            y--;
            maze[x][y] = 2;
        } else if (maze[x - 1][y] == 0) {
            x--;
            maze[x][y] = 2;
        } else {
            maze[x][y] = 3;
            if (x == 1 && y == 1) {
                printf("No solution found.\n");
                return;
            }
            x--;
            if (maze[x][y] == 2) {
                maze[x][y] = 3;
            } else {
                y--;
                if (maze[x][y] == 2) {
                    maze[x][y] = 3;
                } else {
                    x++;
                    if (maze[x][y] == 2) {
                        maze[x][y] = 3;
                    } else {
                        y++;
                        if (maze[x][y] == 2) {
                            maze[x][y] = 3;
                        }
                    }
                }
            }
        }
    }
    printf("Solution:\n");
    print_maze();
}

int main() {
    srand(time(0));
    init_maze();
    printf("Maze:\n");
    print_maze();
    solve_maze();
    return 0;
}