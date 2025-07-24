//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 30

enum directions { UP, RIGHT, DOWN, LEFT };

void create_maze(int maze[][COLS])
{
    srand(time(NULL));

    // Create outer walls
    for (int i = 0; i < ROWS; i++) {
        maze[i][0] = 1;
        maze[i][COLS-1] = 1;
    }
    for (int j = 0; j < COLS; j++) {
        maze[0][j] = 1;
        maze[ROWS-1][j] = 1;
    }

    // Create random paths
    int curr_row = 1, curr_col = 1;
    maze[curr_row][curr_col] = 0;

    while (curr_row != ROWS-2 || curr_col != COLS-2) {
        // Check if there are any directions to go in
        int valid_dirs[4] = {-1, -1, -1, -1};
        int num_dirs = 0;

        if (curr_row > 1 && maze[curr_row-2][curr_col] != 0) {
            valid_dirs[num_dirs] = UP;
            num_dirs++;
        }
        if (curr_col < COLS-2 && maze[curr_row][curr_col+2] != 0) {
            valid_dirs[num_dirs] = RIGHT;
            num_dirs++;
        }
        if (curr_row < ROWS-2 && maze[curr_row+2][curr_col] != 0) {
            valid_dirs[num_dirs] = DOWN;
            num_dirs++;
        }
        if (curr_col > 1 && maze[curr_row][curr_col-2] != 0) {
            valid_dirs[num_dirs] = LEFT;
            num_dirs++;
        }

        // If no directions to go in
        if (num_dirs == 0) {
            int row_back = curr_row, col_back = curr_col;
            do {
                curr_row = row_back;
                curr_col = col_back;

                if (curr_col > 1) {
                    curr_col -= 2;
                }
                else {
                    curr_col = COLS - 2;
                    curr_row--;
                }
            } while (maze[curr_row][curr_col] != 0);
        }
        else {
            int rand_dir = valid_dirs[rand() % num_dirs];

            switch (rand_dir) {
                case UP:
                    maze[curr_row-1][curr_col] = 0;
                    curr_row -= 2;
                    break;
                case RIGHT:
                    maze[curr_row][curr_col+1] = 0;
                    curr_col += 2;
                    break;
                case DOWN:
                    maze[curr_row+1][curr_col] = 0;
                    curr_row += 2;
                    break;
                case LEFT:
                    maze[curr_row][curr_col-1] = 0;
                    curr_col -= 2;
                    break;
            }
        }
    }
}

void print_maze(int maze[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS] = {0};

    create_maze(maze);
    print_maze(maze);

    return 0;
}