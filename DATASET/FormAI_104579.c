//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 4
#define COLS 4
#define WALL 0 
#define PATH 1 
#define STARTROW 0
#define STARTCOL 0
#define ENDROW 3
#define ENDCOL 3

int heuristic(int row, int col) {
    return abs(ENDROW - row) + abs(ENDCOL - col);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int AStar(int maze[][COLS], int row, int col) {
    int closedList[ROWS][COLS];
    int gScore[ROWS][COLS];
    int fScore[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closedList[i][j] = 0;
            gScore[i][j] = INT_MAX;
            fScore[i][j] = INT_MAX;
        }
    }
    gScore[STARTROW][STARTCOL] = 0;
    fScore[STARTROW][STARTCOL] = heuristic(STARTROW, STARTCOL);

    while (1) {
        int minFScore = INT_MAX, minRow = -1, minCol = -1;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (closedList[i][j] == 0 && fScore[i][j] < minFScore) {
                    minFScore = fScore[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }

        if (minRow == -1 || minCol == -1) {
            return 0;
        }

        if (minRow == ENDROW && minCol == ENDCOL) {
            return 1;
        }

        closedList[minRow][minCol] = 1;

        if (minRow > 0 && maze[minRow - 1][minCol] != WALL) {
            int newGScore = gScore[minRow][minCol] + 1;
            if (newGScore < gScore[minRow - 1][minCol]) {
                gScore[minRow - 1][minCol] = newGScore;
                fScore[minRow - 1][minCol] = gScore[minRow - 1][minCol] + heuristic(minRow - 1, minCol);
            }
        }

        if (minCol > 0 && maze[minRow][minCol - 1] != WALL) {
            int newGScore = gScore[minRow][minCol] + 1;
            if (newGScore < gScore[minRow][minCol - 1]) {
                gScore[minRow][minCol - 1] = newGScore;
                fScore[minRow][minCol - 1] = gScore[minRow][minCol - 1] + heuristic(minRow, minCol - 1);
            }
        }

        if (minCol < COLS - 1 && maze[minRow][minCol + 1] != WALL) {
            int newGScore = gScore[minRow][minCol] + 1;
            if (newGScore < gScore[minRow][minCol + 1]) {
                gScore[minRow][minCol + 1] = newGScore;
                fScore[minRow][minCol + 1] = gScore[minRow][minCol + 1] + heuristic(minRow, minCol + 1);
            }
        }

        if (minRow < ROWS - 1 && maze[minRow + 1][minCol] != WALL) {
            int newGScore = gScore[minRow][minCol] + 1;
            if (newGScore < gScore[minRow + 1][minCol]) {
                gScore[minRow + 1][minCol] = newGScore;
                fScore[minRow + 1][minCol] = gScore[minRow + 1][minCol] + heuristic(minRow + 1, minCol);
            }
        }
    }
}

int main() {
    int maze[ROWS][COLS] = {{1, 0, 1, 1},
                            {1, 1, 1, 0},
                            {0, 1, 0, 1},
                            {1, 1, 1, 1}};

    if (AStar(maze, STARTROW, STARTCOL) == 1) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}