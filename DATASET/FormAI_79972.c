//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 15
#define MAZE_HEIGHT 15

char maze[MAZE_HEIGHT][MAZE_WIDTH];

void generate_maze() {
    // Set all cells to blocked
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = '#';
        }
    }

    // Randomly choose a starting point
    int x = rand() % MAZE_WIDTH;
    int y = rand() % MAZE_HEIGHT;
    maze[y][x] = 'S';

    // Generate the maze
    while (maze[y][x] != 'E') {
        // Choose a random direction
        int dir = rand() % 4;

        // Move in the chosen direction if possible
        if (dir == 0 && x > 0 && maze[y][x-1] == '#') {
            x--;
            maze[y][x] = ' ';
        } else if (dir == 1 && y > 0 && maze[y-1][x] == '#') {
            y--;
            maze[y][x] = ' ';
        } else if (dir == 2 && x < MAZE_WIDTH - 1 && maze[y][x+1] == '#') {
            x++;
            maze[y][x] = ' ';
        } else if (dir == 3 && y < MAZE_HEIGHT - 1 && maze[y+1][x] == '#') {
            y++;
            maze[y][x] = ' ';
        }

        // Place the end point
        if (y == MAZE_HEIGHT - 1 && x == MAZE_WIDTH / 2) {
            maze[y][x] = 'E';
        }
    }
}

void print_maze() {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_maze();
    print_maze();
    return 0;
}