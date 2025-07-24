//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 20

char maze[ROWS][COLUMNS] = {
    "# # # # # # # # # # # # # # # # # # #",
    "#   #             #               # #",
    "# # # # # # # # # # # # # # # #   # #",
    "#   #             #       #     #   #",
    "# # # # # # # # # # # # # # #   # # #",
    "#   #             #           #     #",
    "# # # # # # # # # # # # # # # # # # #",
    "#   #             #           #     #",
    "# # # # # # # # # # # # # # #   # # #",
    "#                   #               #",
};

bool visited[ROWS][COLUMNS] = {false};

int startX;
int startY;

int endX;
int endY;

void findStartAndEndPositions() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 'S') {
                startX = j;
                startY = i;
            }
            if (maze[i][j] == 'E') {
                endX = j;
                endY = i;
            }
        }
    }
}

bool isWall(char cell) {
    return cell == '#' || cell == '\0' || cell == '\n';
}

bool isValidPosition(int x, int y) {
    return x >= 0 && y >= 0 && x < COLUMNS && y < ROWS && !visited[y][x] && !isWall(maze[y][x]);
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void printVisited() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d", visited[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

bool findRoute(int x, int y) {
    if (!isValidPosition(x, y)) {
        return false;
    }

    visited[y][x] = true;

    if (x == endX && y == endY) {
        return true;
    }

    if (findRoute(x - 1, y)) {
        return true;
    }

    if (findRoute(x + 1, y)) {
        return true;
    }

    if (findRoute(x, y - 1)) {
        return true;
    }

    if (findRoute(x, y + 1)) {
        return true;
    }

    visited[y][x] = false;

    return false;
}

void markRoute(int x, int y) {
    if (x == startX && y == startY) {
        maze[y][x] = 'S';
        return;
    }

    if (x == endX && y == endY) {
        maze[y][x] = 'E';
        return;
    }

    maze[y][x] = '+';

    if (isValidPosition(x - 1, y) && visited[y][x - 1]) {
        markRoute(x - 1, y);
        return;
    }

    if (isValidPosition(x + 1, y) && visited[y][x + 1]) {
        markRoute(x + 1, y);
        return;
    }

    if (isValidPosition(x, y - 1) && visited[y - 1][x]) {
        markRoute(x, y - 1);
        return;
    }

    if (isValidPosition(x, y + 1) && visited[y + 1][x]) {
        markRoute(x, y + 1);
        return;
    }

    printf("Something went wrong: could not mark route\n");
}

int main() {
    printf("Finding route in maze:\n");
    printMaze();

    findStartAndEndPositions();

    if (findRoute(startX, startY)) {
        printf("\nRoute found:\n");
        markRoute(endX, endY);
        printMaze();
    } else {
        printf("Route not found");
    }

    return 0;
}