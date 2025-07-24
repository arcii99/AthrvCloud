//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

int maze[ROWS][COLS];

int opposite_dir(int dir) {
    switch (dir) {
        case NORTH:
            return SOUTH;
        case EAST:
            return WEST;
        case SOUTH:
            return NORTH;
        case WEST:
            return EAST;
    }
}

void generate_maze(int row, int col) {
    Direction directions[4] = {NORTH, EAST, SOUTH, WEST};
    int temp;

    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int dir = directions[i];
        int new_row = row, new_col = col;

        switch (dir) {
            case NORTH:
                new_row--;
                break;
            case EAST:
                new_col++;
                break;
            case SOUTH:
                new_row++;
                break;
            case WEST:
                new_col--;
                break;
        }

        if (new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
            continue;
        }

        if (maze[new_row][new_col] == 0) {
            maze[row][col] |= 1 << dir;
            maze[new_row][new_col] |= 1 << opposite_dir(dir);
            generate_maze(new_row, new_col);
        }
    }
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 && j == 0) {
                printf("START ");
            } else if (i == ROWS - 1 && j == COLS - 1) {
                printf("END ");
            } else {
                printf("%s ", (maze[i][j] & (1 << NORTH)) ? " " : "_");
                printf("%s ", (maze[i][j] & (1 << EAST)) ? " " : "|");
                printf("%s ", (maze[i][j] & (1 << SOUTH)) ? " " : "_");
                printf("%s ", (maze[i][j] & (1 << WEST)) ? " " : "|");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }

    generate_maze(0, 0);
    print_maze();

    return 0;
}