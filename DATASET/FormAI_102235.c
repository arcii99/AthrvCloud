//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void generateMaze(int maze[ROW][COL], int row, int col);

int main() {
    int maze[ROW][COL];
    int i, j;

    // Fill the maze with walls
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate the maze
    generateMaze(maze, ROW, COL);

    // Print the maze
    printf("Maze:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(int maze[ROW][COL], int row, int col) {
    srand(time(NULL));
    int x = rand() % row;
    int y = rand() % col;
    int visited[row][col];
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            visited[i][j] = 0;
        }
    }
    visited[x][y] = 1;
    while (1) {
        int move = rand() % 4;
        if (move == 0) {
            if (x - 2 < 0) {
                continue;
            }
            if (visited[x - 2][y] == 0) {
                maze[x - 2][y] = 0;
                maze[x - 1][y] = 0;
                visited[x - 2][y] = 1;
                x -= 2;
            }
        } else if (move == 1) {
            if (y + 2 >= col) {
                continue;
            }
            if (visited[x][y + 2] == 0) {
                maze[x][y + 2] = 0;
                maze[x][y + 1] = 0;
                visited[x][y + 2] = 1;
                y += 2;
            }
        } else if (move == 2) {
            if (x + 2 >= row) {
                continue;
            }
            if (visited[x + 2][y] == 0) {
                maze[x + 2][y] = 0;
                maze[x + 1][y] = 0;
                visited[x + 2][y] = 1;
                x += 2;
            }
        } else {
            if (y - 2 < 0) {
                continue;
            }
            if (visited[x][y - 2] == 0) {
                maze[x][y - 2] = 0;
                maze[x][y - 1] = 0;
                visited[x][y - 2] = 1;
                y -= 2;
            }
        }
        int done = 1;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (visited[i][j] == 0) {
                    done = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
}