//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x, y;
} point;

point getPairFromIndex(int index) {
    return (point) {
        .x = index % COLS,
        .y = index / COLS
    };
}

int getIndexFromPair(point pair) {
    return pair.y * ROWS + pair.x;
}

int getAdjacentIndex(point current, point destination) {
    int currentIndex = getIndexFromPair(current);
    int destIndex = getIndexFromPair(destination);

    int rowDiff = current.y - destination.y;
    int colDiff = current.x - destination.x;

    if (rowDiff == 0 && colDiff == -1) { // Right
        return currentIndex + 1;
    } else if (rowDiff == 0 && colDiff == 1) { // Left
        return currentIndex - 1;
    } else if (rowDiff == 1 && colDiff == 0) { // Down
        return currentIndex - COLS;
    } else if (rowDiff == -1 && colDiff == 0) { // Up
        return currentIndex + ROWS;
    } else {
        return -1;
    }
}

int findRoute(int maze[ROWS][COLS], int start, int end, int *route) {
    point startPair = getPairFromIndex(start);
    point endPair = getPairFromIndex(end);

    int routeLength = 0;

    int visited[ROWS*COLS] = {0};
    int queue[ROWS*COLS] = {start};

    visited[start] = 1;

    int current;

    while (routeLength < ROWS*COLS && queue[0] != -1) {
        current = queue[0];

        if (current == end) {
            break;
        }

        point currentPair = getPairFromIndex(current);

        for (int i = 0; i < 4; i++) {
            point adjacentPair = {(currentPair.x + (i == 0) - (i == 1)), (currentPair.y + (i == 2) - (i == 3))};

            if (adjacentPair.y >= 0 && adjacentPair.y < ROWS) {
                if (adjacentPair.x >= 0 && adjacentPair.x < COLS) {
                    int adjacentIndex = getAdjacentIndex(currentPair, adjacentPair);

                    if (adjacentIndex >= 0 && !visited[adjacentIndex] && maze[adjacentPair.y][adjacentPair.x] != 1) {
                        queue[++queue[0]] = adjacentIndex;
                        visited[adjacentIndex] = 1;
                        route[adjacentIndex] = current;
                    }
                }
            }
        }

        queue[0]--;
    }

    if (current != end) {
        routeLength = -1;
    } else {
        while (current != start) {
            route[routeLength++] = current;
            current = route[current];
        }

        route[routeLength] = start;
    }

    return routeLength;
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printRoute(int maze[ROWS][COLS], int *route, int length) {
    int displayMaze[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            displayMaze[i][j] = maze[i][j];
        }
    }

    for (int i = 1; i < length; i++) {
        point pair = getPairFromIndex(route[i]);
        displayMaze[pair.y][pair.x] = 2;
    }

    printf("\n\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", displayMaze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS] = {{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
                            { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
                            { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
                            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                            { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
                            { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
                            { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

    printMaze(maze);

    int route[ROWS*COLS] = {-1};
    int length = findRoute(maze, 3, 97, route);

    if (length > 0) {
        printRoute(maze, route, length);
    } else {
        printf("No route found.\n");
    }

    return 0;
}