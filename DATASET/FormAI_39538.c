//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE];

void generateMaze(int x, int y) {
    if (maze[x][y] == 0) {
        maze[x][y] = 1;
        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[j];
            directions[j] = temp;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = x, nextY = y;
            switch (directions[i]) {
                case 0:
                    nextX++;
                    break;
                case 1:
                    nextY++;
                    break;
                case 2:
                    nextX--;
                    break;
                case 3:
                    nextY--;
                    break;
            }
            if (nextX >= 0 && nextX < MAZE_SIZE && nextY >= 0 && nextY < MAZE_SIZE) {
                if (maze[nextX][nextY] == 0) {
                    maze[x + (nextX - x) / 2][y + (nextY - y) / 2] = 1;
                    generateMaze(nextX, nextY);
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    generateMaze(0, 0);
    while (1) {
        for (int y = 0; y < MAZE_SIZE; y++) {
            for (int x = 0; x < MAZE_SIZE; x++) {
                printf("%c ", maze[x][y] ? ' ' : '#');
            }
            printf("\n");
        }
        printf("\n");
        getchar();
    }
    return 0;
}