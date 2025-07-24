//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_maze(int maze[][COLS]) {
    // seed the random number generator
    srand(time(NULL));

    // initialize maze with walls everywhere
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // starting point
    int r = 1;
    int c = 1;
    maze[r][c] = 0;

    // create a list of directions
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // main loop to generate the maze
    while (1) {
        // shuffle the directions array
        for (int i = 0; i < 4; i++) {
            int temp_r = directions[i][0];
            int temp_c = directions[i][1];
            int random_index = rand() % 4;
            directions[i][0] = directions[random_index][0];
            directions[i][1] = directions[random_index][1];
            directions[random_index][0] = temp_r;
            directions[random_index][1] = temp_c;
        }

        // check if all neighbors are walls
        int num_neighbors = 0;
        for (int i = 0; i < 4; i++) {
            int neighbor_r = r + directions[i][0];
            int neighbor_c = c + directions[i][1];
            if (neighbor_r > 0 && neighbor_r < ROWS && neighbor_c > 0 && neighbor_c < COLS && maze[neighbor_r][neighbor_c] == 1) {
                num_neighbors++;
            }
        }

        // if all neighbors are walls, backtrack
        if (num_neighbors == 0) {
            maze[r][c] = 2;
            if (r == 1 && c == 1) {
                break; // finished maze generation
            }
            int last_r = r;
            int last_c = c;
            for (int i = 0; i < 4; i++) {
                r = last_r + directions[i][0];
                c = last_c + directions[i][1];
                if (r > 0 && r < ROWS && c > 0 && c < COLS && maze[r][c] == 0) {
                    break;
                }
            }
        }
        // else, carve through a random neighbor
        else {
            int random_index = rand() % num_neighbors;
            for (int i = 0; i < 4; i++) {
                int neighbor_r = r + directions[i][0];
                int neighbor_c = c + directions[i][1];
                if (neighbor_r > 0 && neighbor_r < ROWS && neighbor_c > 0 && neighbor_c < COLS && maze[neighbor_r][neighbor_c] == 1) {
                    if (random_index == 0) {
                        maze[neighbor_r][neighbor_c] = 0;
                        maze[r + directions[i][0] / 2][c + directions[i][1] / 2] = 0;
                        r = neighbor_r;
                        c = neighbor_c;
                        break;
                    }
                    random_index--;
                }
            }
        }
    }
}

void print_maze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            }
            else if (maze[i][j] == 2) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}