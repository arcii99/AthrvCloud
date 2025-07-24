//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 25

void generateMaze(int maze[ROW][COL]) {
    srand(time(NULL));

    // Assigning wall to all cells
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = (rand() % 3 == 0) ? 1 : 0;
            }
        }
    }

    // Starting from a random cell and generating a maze
    int x = rand() % (ROW - 2) + 1;
    int y = rand() % (COL - 2) + 1;
    maze[x][y] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (1) {
        int count = 0;
        int nx, ny;
        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (maze[nx][ny] == 1) {
                count++;
            }
        }

        if (count == 3) {
            maze[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (maze[nx][ny] == 1) {
                    maze[nx][ny] = 0;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        } else if (count == 4) {
            if (maze[x + dx[0]][y + dy[0]] == 0) {
                x += dx[0];
                y += dy[0];
            } else if (maze[x + dx[1]][y + dy[1]] == 0) {
                x += dx[1];
                y += dy[1];
            } else if (maze[x + dx[2]][y + dy[2]] == 0) {
                x += dx[2];
                y += dy[2];
            } else if (maze[x + dx[3]][y + dy[3]] == 0) {
                x += dx[3];
                y += dy[3];
            }
        } else {
            break;
        }
    }
}

void printMaze(int maze[ROW][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            printf("%c", (maze[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int maze[ROW][COL];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}