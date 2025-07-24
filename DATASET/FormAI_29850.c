//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

void generateMaze(char maze[][MAZE_SIZE]);
void printMaze(char maze[][MAZE_SIZE]);

int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];

    srand(time(NULL));

    generateMaze(maze);

    printf("Here is your awesome procedurally generated maze!\n");
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][MAZE_SIZE]) {
    int i, j;

    // Initialize maze with walls
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = '#';
        }
    }

    // Create random starting and ending points
    int start_i = rand() % MAZE_SIZE;
    int start_j = rand() % MAZE_SIZE;
    int end_i = rand() % MAZE_SIZE;
    int end_j = rand() % MAZE_SIZE;

    // Set starting and ending points in maze
    maze[start_i][start_j] = 'S';
    maze[end_i][end_j] = 'E';

    // Generate random paths in maze
    int num_paths = (MAZE_SIZE * MAZE_SIZE) / 4;
    int paths_created = 0;

    while (paths_created < num_paths) {
        int i = rand() % MAZE_SIZE;
        int j = rand() % MAZE_SIZE;

        if (maze[i][j] == '#') {
            maze[i][j] = ' ';
            paths_created++;
        }
    }
}

void printMaze(char maze[][MAZE_SIZE]) {
    int i, j;

    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}