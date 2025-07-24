//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void printMaze(int maze[][COL], int x, int y) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (i == x && j == y) {
                printf("X ");
            } else if (maze[i][j] == -1) {
                printf("# ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int outOfBounds(int i, int j) {
    if (i < 0 || j < 0 || i >= ROW || j >= COL) {
        return 1;
    }
    return 0;
}

int dfs(int maze[][COL], int visited[][COL], int i, int j, int count) {
    if (outOfBounds(i, j) || visited[i][j]) {
        return count;
    }
    visited[i][j] = 1;
    maze[i][j] = count;
    printMaze(maze, i, j);
    count++;
    int randomNum = rand() % 4;
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int k;
    for (k = 0; k < 4; k++) {
        int x = i + dir[(k+randomNum)%4][0];
        int y = j + dir[(k+randomNum)%4][1];
        count = dfs(maze, visited, x, y, count);
    }
    return count;
}

int main() {
    srand(time(NULL));

    int maze[ROW][COL];
    int visited[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = -1;
            visited[i][j] = 0;
        }
    }

    int start_i = rand() % ROW;
    int start_j = rand() % COL;
    int count = 1;
    dfs(maze, visited, start_i, start_j, count);

    return 0;
}