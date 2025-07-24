//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x;
    int y;
} Position;

void initMaze(char maze[][WIDTH]);
void printMaze(char maze[][WIDTH]);
void generateMaze(char maze[][WIDTH], Position start, Position end, int numObstacles);
int validMove(char maze[][WIDTH], Position position, int dx, int dy);

int main() {
    char maze[HEIGHT][WIDTH];
    Position start = {0, 0};
    Position end = {WIDTH - 1, HEIGHT - 1};
    int numObstacles = 20;

    srand(time(NULL));
    initMaze(maze);
    generateMaze(maze, start, end, numObstacles);
    printMaze(maze);

    return 0;
}

void initMaze(char maze[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            maze[y][x] = '#';
        }
    }
}

void printMaze(char maze[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(maze[y][x]);
        }
        putchar('\n');
    }
}

void generateMaze(char maze[][WIDTH], Position start, Position end, int numObstacles) {
    int x, y;
    int dx, dy;
    int i;
    Position currentPosition = start;

    for (i = 0; i < numObstacles; i++) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        if (maze[y][x] == '#') {
            maze[y][x] = 'O';
        }
    }

    maze[start.y][start.x] = 'S';
    maze[end.y][end.x] = 'E';

    while (currentPosition.x != end.x || currentPosition.y != end.y) {
        dx = rand() % 3 - 1;
        dy = rand() % 3 - 1;
        if (dx != 0 && dy != 0) {
            continue;
        }

        if (validMove(maze, currentPosition, dx, dy)) {
            maze[currentPosition.y][currentPosition.x] = '.';
            currentPosition.x += dx;
            currentPosition.y += dy;
            maze[currentPosition.y][currentPosition.x] = '@';
        }
    }
}

int validMove(char maze[][WIDTH], Position position, int dx, int dy) {
    int x = position.x + dx;
    int y = position.y + dy;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return 0;
    }

    if (maze[y][x] == '#' || maze[y][x] == 'O' || maze[y][x] == '@') {
        return 0;
    }

    return 1;
}