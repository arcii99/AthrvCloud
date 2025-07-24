//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 25
#define COL 25

int maze[ROW][COL];

void generateMaze(int x, int y) {
    maze[x][y] = 1;

    int directions[] = {1, 2, 3, 4};
    int temp;

    for (int i = 0; i < 4; i++) {
        int index = rand() % 4;
        temp = directions[index];
        directions[index] = directions[i];
        directions[i] = temp;
    }

    for (int i = 0; i < 4; i++) {
        switch (directions[i]) {
            case 1:
                if (x - 2 <= 0)
                    continue;
                if (maze[x-2][y] == 0) {
                    maze[x-1][y] = 1;
                    generateMaze(x-2, y);
                }
                break;
            case 2:
                if (x + 2 >= ROW - 1)
                    continue;
                if (maze[x+2][y] == 0) {
                    maze[x+1][y] = 1;
                    generateMaze(x+2, y);
                }
                break;
            case 3:
                if (y - 2 <= 0)
                    continue;
                if (maze[x][y-2] == 0) {
                    maze[x][y-1] = 1;
                    generateMaze(x, y-2);
                }
                break;
            case 4:
                if (y + 2 >= COL - 1)
                    continue;
                if (maze[x][y+2] == 0) {
                    maze[x][y+1] = 1;
                    generateMaze(x, y+2);
                }
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize maze
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = 0;
        }
    }

    int startX = rand() % (ROW/2) * 2 + 1;
    int startY = rand() % (COL/2) * 2 + 1;

    generateMaze(startX, startY);

    // Print maze
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == startX && j == startY) {
                printf("S ");
            } else if (maze[i][j] == 1) {
                printf("  ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}