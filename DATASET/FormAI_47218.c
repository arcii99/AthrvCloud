//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

void print_maze(char maze[][COL], int row, int col) {
    int i, j;

    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[][COL], int row, int col) {
    int i, j;

    // Fill the maze with walls
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }

    // Generate a random starting position for the maze
    srand(time(NULL));
    int start_row = rand() % (row - 2) + 1;
    int start_col = rand() % (col - 2) + 1;
    maze[start_row][start_col] = 'S';

    // Generate a random ending position for the maze
    int end_row = rand() % (row - 2) + 1;
    int end_col = rand() % (col - 2) + 1;
    maze[end_row][end_col] = 'E';

    // Generate the maze path
    int direction;
    int current_row = start_row;
    int current_col = start_col;
    do {
        // Pick a random direction (0 is up, 1 is right, 2 is down, 3 is left)
        do {
            direction = rand() % 4;
        } while (
            (direction == 0 && current_row == 1) ||
            (direction == 1 && current_col == col - 2) ||
            (direction == 2 && current_row == row - 2) ||
            (direction == 3 && current_col == 1)
        );

        // Move in the chosen direction and carve a path
        switch (direction) {
            case 0: // up
                maze[current_row - 1][current_col] = ' ';
                current_row--;
                break;
            case 1: // right
                maze[current_row][current_col + 1] = ' ';
                current_col++;
                break;
            case 2: // down
                maze[current_row + 1][current_col] = ' ';
                current_row++;
                break;
            case 3: // left
                maze[current_row][current_col - 1] = ' ';
                current_col--;
                break;
        }
    } while (current_row != end_row || current_col != end_col);
}

int main() {
    char maze[ROW][COL];

    generate_maze(maze, ROW, COL);

    printf("Generated maze:\n");
    print_maze(maze, ROW, COL);

    return 0;
}