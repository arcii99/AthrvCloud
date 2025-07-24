//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int main() {
    srand(time(NULL)); // Seed the random number generator
    int width = 20, height = 10;
    char maze[height][width];
    // Initialize the maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = '#';
        }
    }
    // Randomly generate start and end points
    Point start = {rand() % width, rand() % height};
    Point end = {rand() % width, rand() % height};
    if (start.x == end.x && start.y == end.y) {
        // Make sure the start and end are not the same
        end.x = (end.x + 1) % width;
        end.y = (end.y + 1) % height;
    }
    maze[start.y][start.x] = 'S';
    maze[end.y][end.x] = 'E';
    // Generate the maze using a random walk algorithm
    Point current = start;
    while (current.x != end.x || current.y != end.y) {
        Point next;
        int direction = rand() % 4;
        if (direction == 0 && current.x > 0) {
            next.x = current.x - 1;
            next.y = current.y;
        } else if (direction == 1 && current.x < width - 1) {
            next.x = current.x + 1;
            next.y = current.y;
        } else if (direction == 2 && current.y > 0) {
            next.x = current.x;
            next.y = current.y - 1;
        } else if (direction == 3 && current.y < height - 1) {
            next.x = current.x;
            next.y = current.y + 1;
        } else {
            // If we can't move in the chosen direction, try another direction
            continue;
        }
        if (maze[next.y][next.x] == '#') {
            // If the next point is a wall, carve a path to it
            maze[(current.y + next.y) / 2][(current.x + next.x) / 2] = ' ';
            maze[next.y][next.x] = ' ';
            current = next;
        }
    }
    // Print the maze
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
    return 0;
}