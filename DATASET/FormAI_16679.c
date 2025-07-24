//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// function to check if a cell is within bounds
int is_valid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// function to generate the maze
void generate_maze(int maze[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};    // to keep track of visited cells
    int stack[ROWS * COLS][2];         // stack to keep track of path
    int top = -1;                      // top pointer of stack
    int x = 0, y = 0;                  // current cell coordinates

    // mark starting cell as visited
    visited[x][y] = 1;

    // push starting cell to stack
    stack[++top][0] = x;
    stack[top][1] = y;

    // while stack is not empty
    while (top >= 0) {
        // pop current cell from stack
        x = stack[top][0];
        y = stack[top][1];
        top--;

        // create an array of possible neighbors
        int neighbors[4][2] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

        // shuffle the neighbors array randomly
        for (int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp_x = neighbors[i][0];
            int temp_y = neighbors[i][1];
            neighbors[i][0] = neighbors[j][0];
            neighbors[i][1] = neighbors[j][1];
            neighbors[j][0] = temp_x;
            neighbors[j][1] = temp_y;
        }

        // loop through each neighbor
        for (int i = 0; i < 4; i++) {
            int neighbor_x = neighbors[i][0];
            int neighbor_y = neighbors[i][1];

            // if neighbor cell is valid and not visited
            if (is_valid(neighbor_x, neighbor_y) && !visited[neighbor_x][neighbor_y]) {
                // mark neighbor cell as visited
                visited[neighbor_x][neighbor_y] = 1;

                // push current cell to stack
                stack[++top][0] = x;
                stack[top][1] = y;

                // create a passage between current cell and neighbor cell
                if (neighbor_x < x) {
                    maze[x][y] |= 1;    // remove top wall of current cell
                    maze[neighbor_x][neighbor_y] |= 4;    // remove bottom wall of neighbor cell
                }
                if (neighbor_x > x) {
                    maze[x][y] |= 4;    // remove bottom wall of current cell
                    maze[neighbor_x][neighbor_y] |= 1;    // remove top wall of neighbor cell
                }
                if (neighbor_y < y) {
                    maze[x][y] |= 8;    // remove left wall of current cell
                    maze[neighbor_x][neighbor_y] |= 2;    // remove right wall of neighbor cell
                }
                if (neighbor_y > y) {
                    maze[x][y] |= 2;    // remove right wall of current cell
                    maze[neighbor_x][neighbor_y] |= 8;    // remove left wall of neighbor cell
                }

                // update current cell coordinates to neighbor cell coordinates
                x = neighbor_x;
                y = neighbor_y;

                // push neighbor cell to stack
                stack[++top][0] = x;
                stack[top][1] = y;

                // break the loop
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));    // seed the random number generator

    int maze[ROWS][COLS] = {0};    // initialize maze

    generate_maze(maze);    // generate the maze

    // print the maze
    printf(" ");
    for (int j = 0; j < COLS; j++) {
        printf("_");
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 4) {
                printf(" ");
            } else {
                printf("_");
            }
            if (maze[i][j] & 2) {
                printf(" ");
            } else {
                printf("|");
            }           
        }
        printf("\n");
    }

    return 0;
}