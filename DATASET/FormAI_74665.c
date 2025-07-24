//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10
#define BLOCK '#'
#define PATH '.'

char maze[ROWS][COLS] = {
    {'#', '.', '.', '#', '#', '#', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '.', '#', '.', '#'},
    {'.', '#', '.', '.', '#', '.', '#', '.', '.', '#'},
    {'.', '.', '#', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '#', '.', '#', '.', '.', '#', '.', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '.', '#', '#', '.', '.', '#', '.', '.'},
    {'#', '.', '.', '.', '#', '.', '.', '#', '#', '#'},
};

struct Point {
    int x;
    int y;
};

void printMaze()
{
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int isBlocked(struct Point point)
{
    return maze[point.x][point.y] == BLOCK;
}

int isPath(struct Point point)
{
    if (point.x < 0 || point.x >= ROWS || point.y < 0 || point.y >= COLS) {
        return 0;
    } else {
        return maze[point.x][point.y] == PATH;
    }
}

int isVisited(struct Point point, struct Point visited[], int nVisited)
{
    for (int i = 0; i < nVisited; i++) {
        if (visited[i].x == point.x && visited[i].y == point.y) {
            return 1;
        }
    }
    return 0;
}

int findRoute(struct Point from, struct Point to, struct Point visited[], int nVisited)
{
    if (from.x == to.x && from.y == to.y) {
        return 1;
    }

    static struct Point moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < 4; i++) {
        struct Point next = {from.x + moves[i].x, from.y + moves[i].y};
        if (isPath(next) && !isVisited(next, visited, nVisited)) {
            struct Point nextVisited[nVisited + 1];
            memcpy(nextVisited, visited, nVisited * sizeof(nextVisited[0]));
            nextVisited[nVisited] = next;

            if (findRoute(next, to, nextVisited, nVisited + 1)) {
                maze[next.x][next.y] = '#';
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    struct Point start = {0, 0};
    struct Point end = {ROWS - 1, COLS - 1};

    struct Point visited[0];

    findRoute(start, end, visited, 0);

    printMaze();

    return 0;
}