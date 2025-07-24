//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL_CHAR '*'
#define SPACE_CHAR ' '

void generateMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    // Fill with walls
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL_CHAR;
        }
    }

    // Random seed
    srand(time(NULL));

    // Starting position
    int x = rand() % MAZE_SIZE;
    int y = rand() % MAZE_SIZE;
    maze[y][x] = SPACE_CHAR;

    while (1) {
        // Check for available directions
        int count = 0;
        int directions[4];
        if (y > 1 && maze[y - 2][x] == WALL_CHAR) {
            directions[count] = 0;
            count++;
        }
        if (x < MAZE_SIZE - 2 && maze[y][x + 2] == WALL_CHAR) {
            directions[count] = 1;
            count++;
        }
        if (y < MAZE_SIZE - 2 && maze[y + 2][x] == WALL_CHAR) {
            directions[count] = 2;
            count++;
        }
        if (x > 1 && maze[y][x - 2] == WALL_CHAR) {
            directions[count] = 3;
            count++;
        }

        // End condition
        if (count == 0) {
            break;
        }

        // Choose a random direction
        int index = rand() % count;
        int direction = directions[index];

        // Clear the path
        switch (direction) {
            case 0:
                maze[y - 1][x] = SPACE_CHAR;
                maze[y - 2][x] = SPACE_CHAR;
                y -= 2;
                break;
            case 1:
                maze[y][x + 1] = SPACE_CHAR;
                maze[y][x + 2] = SPACE_CHAR;
                x += 2;
                break;
            case 2:
                maze[y + 1][x] = SPACE_CHAR;
                maze[y + 2][x] = SPACE_CHAR;
                y += 2;
                break;
            case 3:
                maze[y][x - 1] = SPACE_CHAR;
                maze[y][x - 2] = SPACE_CHAR;
                x -= 2;
                break;
            default:
                break;
        }
    }

    // Place finish line
    maze[MAZE_SIZE-1][MAZE_SIZE-1] = SPACE_CHAR;
}

void printMaze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}