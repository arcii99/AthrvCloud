//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int WIDTH = 10;
const int HEIGHT = 10;

int main() {

    srand(time(NULL));

    int maze[HEIGHT][WIDTH];
    int visited[HEIGHT][WIDTH];
    int i, j, x, y, p, q, a, b, random;
    char barrier = '\u2588'; // Unicode character for full block

    // Initialize maze to all walls
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
            visited[i][j] = 0;
        }
    }

    // Starting cell
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    visited[y][x] = 1;

    // Generate maze
    while (1) {

        // Find unvisited neighbor
        do {
            p = rand() % 3 - 1;
            q = rand() % 3 - 1;
            a = x + p;
            b = y + q;
        } while (a < 0 || a >= WIDTH || b < 0 || b >= HEIGHT || visited[b][a]);

        // Knock down wall
        if (p == -1) maze[y][x] &= 1;
        if (p == 1) maze[b][a] &= 4;
        if (q == -1) maze[y][x] &= 2;
        if (q == 1) maze[b][a] &= 8;

        // Visit neighbor
        x = a;
        y = b;
        visited[y][x] = 1;

        // Check if maze is complete
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                if (!visited[i][j]) {
                    break;
                }
            }
            if (j < WIDTH) {
                break;
            }
        }
        if (i == HEIGHT) {
            break;
        }
    }

    // Print maze
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] & 1) printf("%c%c%c", barrier, barrier, barrier);
            else printf("%c %c", barrier, barrier);
        }
        printf("%c\n", barrier);
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] & 2) printf("%c %c", barrier, barrier);
            else printf("  %c", barrier);
        }
        printf("%c\n", barrier);
    }
    for (j = 0; j < WIDTH; j++) {
        printf("%c%c%c", barrier, barrier, barrier);
    }

    return 0;
}