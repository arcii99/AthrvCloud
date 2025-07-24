//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLUMNS 15

typedef enum directions {
    UP,
    DOWN,
    LEFT,
    RIGHT,
} Direction;

void print_maze(int maze[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }
}

void generate_maze(int maze[ROWS][COLUMNS], int row, int column) {
    Direction directions[4] = {UP, DOWN, LEFT, RIGHT};
    int shuffled_directions[4] = {0};
    int temp;

    // Shuffle the directions
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        int random_index = rand() % 4;
        temp = directions[random_index];
        directions[random_index] = directions[i];
        directions[i] = temp;
        shuffled_directions[i] = temp;
    }

    // Dig paths recursively
    for (int i = 0; i < 4; i++) {
        switch (shuffled_directions[i]) {
            case UP:
                if (row - 2 <= 0) {
                    continue;
                }
                if (maze[row - 2][column] == 0) {
                    maze[row - 2][column] = 1;
                    maze[row - 1][column] = 1;
                    generate_maze(maze, row - 2, column);
                }
                break;
            case DOWN:
                if (row + 2 >= ROWS - 1) {
                    continue;
                }
                if (maze[row + 2][column] == 0) {
                    maze[row + 2][column] = 1;
                    maze[row + 1][column] = 1;
                    generate_maze(maze, row + 2, column);
                }
                break;
            case LEFT:
                if (column - 2 <= 0) {
                    continue;
                }
                if (maze[row][column - 2] == 0) {
                    maze[row][column - 2] = 1;
                    maze[row][column - 1] = 1;
                    generate_maze(maze, row, column - 2);
                }
                break;
            case RIGHT:
                if (column + 2 >= COLUMNS - 1) {
                    continue;
                }
                if (maze[row][column + 2] == 0) {
                    maze[row][column + 2] = 1;
                    maze[row][column + 1] = 1;
                    generate_maze(maze, row, column + 2);
                }
                break;
        }
    }
}

int main() {
    int maze[ROWS][COLUMNS] = {{0}};

    // Set starting point
    maze[0][1] = 1;

    // Generate maze
    generate_maze(maze, 0, 1);

    // Print maze
    print_maze(maze);

    return 0;
}