//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int maze[ROWS][COLS], int start[2], int end[2]) {
    // randomly generate maze
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = 0; // set wall as 0
            } else {
                maze[i][j] = (rand() % 2) + 1; // set path as 1 or 2
            }
        }
    }
    // set start and end points
    start[0] = 1;
    start[1] = 1;
    end[0] = ROWS - 2;
    end[1] = COLS - 2;
    maze[start[0]][start[1]] = 3;
    maze[end[0]][end[1]] = 4;
}

void findRoute(int maze[ROWS][COLS], int start[2], int end[2]) {
    int current[2] = {start[0], start[1]};
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int queue[ROWS * COLS][2];
    int qStart = 0, qEnd = 1;
    queue[qStart][0] = current[0];
    queue[qStart][1] = current[1];
    while (qStart < qEnd) {
        current[0] = queue[qStart][0];
        current[1] = queue[qStart][1];
        for (int i = 0; i < 4; i++) {
            int next[2] = {current[0] + direction[i][0], current[1] + direction[i][1]};
            if (maze[next[0]][next[1]] == 0 || maze[next[0]][next[1]] == 2 || maze[next[0]][next[1]] == 4) {
                continue;
            }
            if (next[0] == end[0] && next[1] == end[1]) {
                maze[next[0]][next[1]] = 4;
                return;
            }
            maze[next[0]][next[1]] = 2;
            queue[qEnd][0] = next[0];
            queue[qEnd][1] = next[1];
            qEnd++;
        }
        qStart++;
    }
}

int main() {
    int maze[ROWS][COLS];
    int start[2], end[2];
    generateMaze(maze, start, end);
    printf("Original Maze:\n");
    printMaze(maze);
    findRoute(maze, start, end);
    printf("\nMaze with Route:\n");
    printMaze(maze);
    return 0;
}