//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS];

typedef struct {
    int x;
    int y;
} Coord;

Coord getRandCoord() {
    int x, y;
    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (map[x][y] != 0);
    return (Coord){x, y};
}

bool isVisited(Coord c) {
    return map[c.x][c.y] == 1;
}

bool isValidCoord(Coord c) {
    return c.x >= 0 && c.x < ROWS && c.y >= 0 && c.y < COLS && map[c.x][c.y] == 0;
}

void printMap() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%s", map[i][j] == 1 ? "X" : ".");
        }
        printf("\n");
    }
}

void generateMap() {
    srand(time(NULL));
    int obstacles = ROWS * COLS / 4;
    for (int i = 0; i < obstacles; i++) {
        Coord c = getRandCoord();
        map[c.x][c.y] = -1;
    }
}

void cleanMap() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] != -1) {
                map[i][j] = 0;
            }
        }
    }
}

bool pathfinding(Coord start, Coord end) {
    Coord current = start;
    map[current.x][current.y] = 1; // mark as visited
    printMap();
    if (current.x == end.x && current.y == end.y) {
        return true; // reached the end
    }
    Coord nextCoords[4] = {{current.x+1, current.y}, {current.x-1, current.y}, {current.x, current.y+1}, {current.x, current.y-1}};
    for (int i = 0; i < 4; i++) {
        Coord nextCoord = nextCoords[i];
        if (isValidCoord(nextCoord)) {
            if (pathfinding(nextCoord, end)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    generateMap();
    printMap();
    Coord start = getRandCoord();
    Coord end = getRandCoord();
    while (start.x == end.x && start.y == end.y) {
        end = getRandCoord();
    }
    printf("Start: (%d,%d)\n", start.x, start.y);
    printf("End: (%d,%d)\n", end.x, end.y);
    if (pathfinding(start, end)) {
        printf("Path found!");
    } else {
        printf("Path not found");
    }
    cleanMap();
    return 0;
}