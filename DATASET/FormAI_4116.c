//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

void generate_maze(int maze[][MAZE_SIZE], int x, int y);
void print_maze(int maze[][MAZE_SIZE]);

int main()
{
    int maze[MAZE_SIZE][MAZE_SIZE] = {0};

    // Seed the random number generator.
    srand(time(NULL));

    // Generate the maze starting from the middle.
    generate_maze(maze, MAZE_SIZE/2, MAZE_SIZE/2);

    // Print the maze to the console.
    print_maze(maze);

    return 0;
}

void generate_maze(int maze[][MAZE_SIZE], int x, int y)
{
    // Choose a random direction to move in.
    int dx, dy;
    do {
        dx = rand() % 3 - 1;
        dy = rand() % 3 - 1;
    } while (dx == 0 && dy == 0);

    // Move in the chosen direction until hitting an obstacle.
    while (maze[x+dx][y+dy] == 0) {
        x += dx;
        y += dy;
        maze[x][y] = 1;
    }

    // Recursively generate the maze from the new position.
    for (int i = 0; i < 4; i++) {
        int nx = x + (rand() % 3 - 1);
        int ny = y + (rand() % 3 - 1);

        if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE && maze[nx][ny] == 0) {
            maze[nx][ny] = 1;
            generate_maze(maze, nx, ny);
        }
    }
}

void print_maze(int maze[][MAZE_SIZE])
{
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == 0)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}