//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMaze(int *maze, int width, int height) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            printf(maze[j * width + i] ? "  " : "[]");
        }
        printf("\n");
    }
}

void generateMaze(int *maze, int width, int height) {
    srand(time(NULL));
    maze[0] = 1;
    while (maze[width * (height - 1) + (width - 1)] != 1) {
        int x = rand() % width;
        int y = rand() % height;

        if (x > 0 && maze[y * width + (x - 1)] == 1 && maze[y * width + x] == 0 && maze[y * width + x + 1] == 0) {
            maze[y * width + x] = 1;
        } else if (x < width - 1 && maze[y * width + (x + 1)] == 1 && maze[y * width + x] == 0 && maze[y * width + (x - 1)] == 0) {
            maze[y * width + x] = 1;
        } else if (y > 0 && maze[(y - 1) * width + x] == 1 && maze[y * width + x] == 0 && maze[(y + 1) * width + x] == 0) {
            maze[y * width + x] = 1;
        } else if (y < height - 1 && maze[(y + 1) * width + x] == 1 && maze[y * width + x] == 0 && maze[(y - 1) * width + x] == 0) {
            maze[y * width + x] = 1;
        }
    }
}

int main() {
    int width, height;

    printf("Hello! Let's generate a maze!\n");
    printf("Please enter the width of the maze: ");
    scanf("%d", &width);
    printf("Please enter the height of the maze: ");
    scanf("%d", &height);

    int *maze = malloc(width * height * sizeof(int));
    generateMaze(maze, width, height);
    printMaze(maze, width, height);
    free(maze);

    printf("Done!\n");

    return 0;
}