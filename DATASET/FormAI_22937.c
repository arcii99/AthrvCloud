//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

void initialize_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

void print_maze() {
    printf("+");
    int i, j;
    for (i = 0; i < COLS; i++) {
        printf("-%c", '+');
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%c", '|');
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf(" %c", '|');
            } else {
                printf("  ");
            }
        }
        printf("%c\n", '|');
        printf("+");
        for (j = 0; j < COLS; j++) {
            printf("-%c", '+');
        }
        printf("\n");
    }
}

void generate_maze(int row, int col) {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int random_directions[4];

    int i, j, k, m;
    for (m = 0; m < 4; m++) {
        random_directions[m] = m;
    }

    for (k = 0; k < 4; k++) {
        int temp = random_directions[k];
        int random_index = rand() % 4;
        random_directions[k] = random_directions[random_index];
        random_directions[random_index] = temp;
    }

    for (i = 0; i < 4; i++) {
        int row_direction = directions[random_directions[i]][0];
        int col_direction = directions[random_directions[i]][1];

        int new_row = row + row_direction * 2;
        int new_col = col + col_direction * 2;

        if (new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
            continue;
        }

        if (maze[new_row][new_col] == 1) {
            maze[new_row - row_direction][new_col - col_direction] = 0;
            maze[new_row][new_col] = 0;
            generate_maze(new_row, new_col);
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_maze();
    generate_maze(1, 1);
    print_maze();
    return 0;
}