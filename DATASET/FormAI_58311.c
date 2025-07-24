//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

#define WALL 1
#define EMPTY 0
#define START 2
#define GOAL 3

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    int x, y;
} Coord;

int inBounds(Coord coord) {
    return 0 <= coord.x && coord.x < ROWS &&
           0 <= coord.y && coord.y < COLS;
}

int isTraversable(Coord coord) {
    return inBounds(coord) && maze[coord.x][coord.y] != WALL;
}

int isGoal(Coord coord) {
    return inBounds(coord) && maze[coord.x][coord.y] == GOAL;
}

void printMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("# ");
            } else if (maze[i][j] == START) {
                printf("S ");
            } else if (maze[i][j] == GOAL) {
                printf("G ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

Coord neighbors[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

Coord path[ROWS * COLS]; /* Enough to store the full path */
int pathLength = 0;

int findPath(Coord curr) {
    if (isGoal(curr)) {
        return 1;
    } else {
        int i;
        for (i = 0; i < 4; i++) {
            Coord next = {curr.x + neighbors[i].x, curr.y + neighbors[i].y};
            if (isTraversable(next)) {
                maze[next.x][next.y] = 2;
                if (findPath(next)) {
                    /* Found a path */
                    path[pathLength] = next;
                    pathLength++;
                    return 1;
                }
            }
        }
        return 0;
    }
}

int main() {
    Coord start = {1, 1};
    path[0] = start;
    pathLength++;
    maze[start.x][start.y] = START;

    findPath(start);

    if (pathLength > 0) {
        printf("Path found: ");
        int i;
        for (i = 0; i < pathLength; i++) {
            printf("(%d, %d) ", path[i].x, path[i].y);
        }
        printf("\n");
    } else {
        printf("No path found.\n");
    }

    printMaze();
    return 0;
}