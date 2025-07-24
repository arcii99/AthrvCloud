//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLUMNS 20
#define MAX_VISITS 100

struct Coord {
    int x, y;
};

bool isVisited[MAX_ROWS][MAX_COLUMNS] = { false };
struct Coord visited[MAX_VISITS];
int visitedIndex = 0;

int random_num(int min, int max) {
    int range = max - min + 1;
    return (rand() % range) + min;
}

bool hasVisited(int x, int y) {
    for (int i = 0; i < visitedIndex; i++) {
        if (visited[i].x == x && visited[i].y == y) {
            return true;
        }
    }
    return false;
}

bool isOutOfBounds(int x, int y) {
    return x < 0 || x >= MAX_COLUMNS || y < 0 || y >= MAX_ROWS;
}

bool canGoUp(int x, int y) {
    return !isOutOfBounds(x, y - 1) && !hasVisited(x, y - 1) && !isVisited[x][y - 1];
}

bool canGoDown(int x, int y) {
    return !isOutOfBounds(x, y + 1) && !hasVisited(x, y + 1) && !isVisited[x][y + 1];
}

bool canGoLeft(int x, int y) {
    return !isOutOfBounds(x - 1, y) && !hasVisited(x - 1, y) && !isVisited[x - 1][y];
}

bool canGoRight(int x, int y) {
    return !isOutOfBounds(x + 1, y) && !hasVisited(x + 1, y) && !isVisited[x + 1][y];
}

void moveUp(int *x, int *y) {
    *y -= 1;
}

void moveDown(int *x, int *y) {
    *y += 1;
}

void moveLeft(int *x, int *y) {
    *x -= 1;
}

void moveRight(int *x, int *y) {
    *x += 1;
}

void printMaze(int playerX, int playerY) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (playerX == j && playerY == i) {
                printf("P");
            } else if (isVisited[j][i]) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void findRoute(int playerX, int playerY) {
    int count = 0;
    int max_moves = MAX_ROWS * MAX_COLUMNS;

    while (count < max_moves) {
        printMaze(playerX, playerY);

        visited[visitedIndex].x = playerX;
        visited[visitedIndex].y = playerY;
        visitedIndex++;
        isVisited[playerX][playerY] = true;

        bool canMove = false;
        if (canGoUp(playerX, playerY)) {
            canMove = true;
        }
        if (canGoDown(playerX, playerY)) {
            canMove = true;
        }
        if (canGoLeft(playerX, playerY)) {
            canMove = true;
        }
        if (canGoRight(playerX, playerY)) {
            canMove = true;
        }

        if (!canMove) {
            visitedIndex--;
            isVisited[playerX][playerY] = false;
            if (visitedIndex == 0) {
                printf("No route found.\n");
                break;
            }
            playerX = visited[visitedIndex - 1].x;
            playerY = visited[visitedIndex - 1].y;
            continue;
        }

        while (true) {
            int direction = random_num(1, 4);
            switch (direction) {
                case 1:
                    if (canGoUp(playerX, playerY)) {
                        moveUp(&playerX, &playerY);
                        count++;
                        break;
                    }
                case 2:
                    if (canGoDown(playerX, playerY)) {
                        moveDown(&playerX, &playerY);
                        count++;
                        break;
                    }
                case 3:
                    if (canGoLeft(playerX, playerY)) {
                        moveLeft(&playerX, &playerY);
                        count++;
                        break;
                    }
                case 4:
                    if (canGoRight(playerX, playerY)) {
                        moveRight(&playerX, &playerY);
                        count++;
                        break;
                    }
            }
            if (count >= max_moves) {
                printf("No route found.\n");
                break;
            }
            if (!canGoUp(playerX, playerY) && !canGoDown(playerX, playerY) &&
                !canGoLeft(playerX, playerY) && !canGoRight(playerX, playerY)) {
                break;
            }
        }

        if (playerX == MAX_COLUMNS - 1 && playerY == MAX_ROWS - 1) {
            printf("Route found!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    findRoute(0, 0);
    return 0;
}