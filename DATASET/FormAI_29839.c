//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

enum directions { NORTH, EAST, SOUTH, WEST };

void generate_maze(int maze[][COLS]);
void print_maze(int maze[][COLS]);

int main(void) {
    int maze[ROWS][COLS];

    srand(time(NULL)); // seed the random number generator

    generate_maze(maze); // generate the maze
    print_maze(maze); // print the maze

    return 0;
}

void generate_maze(int maze[][COLS]) {
    int visited[ROWS][COLS] = { {0} }; // initialize all cells as unvisited
    int direction = 0; // start by going north
    int row = 0, col = 0; // start in the top left corner
    int new_row = 0, new_col = 0; // the row and column of the cell to move to next

    maze[row][col] = 0; // mark the start cell as part of the maze

    while (1) {
        visited[row][col] = 1; // mark the current cell as visited

        // check if there are any unvisited neighbors
        if ((row > 0 && !visited[row-1][col]) ||
            (col < COLS-1 && !visited[row][col+1]) ||
            (row < ROWS-1 && !visited[row+1][col]) ||
            (col > 0 && !visited[row][col-1])) {

            // choose a random unvisited neighbor
            do {
                direction = rand() % 4;
                switch (direction) {
                    case NORTH:
                        if (row > 0 && !visited[row-1][col]) {
                            new_row = row-1;
                            new_col = col;
                        }
                        break;
                    case EAST:
                        if (col < COLS-1 && !visited[row][col+1]) {
                            new_row = row;
                            new_col = col+1;
                        }
                        break;
                    case SOUTH:
                        if (row < ROWS-1 && !visited[row+1][col]) {
                            new_row = row+1;
                            new_col = col;
                        }
                        break;
                    case WEST:
                        if (col > 0 && !visited[row][col-1]) {
                            new_row = row;
                            new_col = col-1;
                        }
                        break;
                }
            } while ((!visited[new_row][new_col] && 
                    ((new_row > 0 && maze[new_row-1][new_col]) ||
                     (new_col < COLS-1 && maze[new_row][new_col+1]) ||
                     (new_row < ROWS-1 && maze[new_row+1][new_col]) ||
                     (new_col > 0 && maze[new_row][new_col-1]))));

            // mark the new cell as part of the maze and remove the wall between the cells
            maze[row][col] |= 1 << direction;
            maze[new_row][new_col] |= 1 << ((direction + 2) % 4);

            row = new_row;
            col = new_col;
        } else { // backtrack to a cell with unvisited neighbors
            if (row == 0 && col == 0) { // we are back at the start cell, maze is complete
                break;
            }
            direction = (maze[row][col] & 0b1100) >> 2; // get the direction we came from
            maze[row][col] &= ~(1 << direction); // remove the wall between the cells
            row += (direction == SOUTH) - (direction == NORTH);
            col += (direction == EAST) - (direction == WEST);
        }
    }
}

void print_maze(int maze[][COLS]) {
    // print top border of maze
    for (int col = 0; col < COLS; col++) {
        printf("+--");
    }
    printf("+\n");

    // print the maze
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("|");
            if ((maze[row][col] & 0b0001) == 0) { // check north wall
                printf("  ");
            } else {
                printf("--");
            }
        }
        printf("|\n");
        for (int col = 0; col < COLS; col++) {
            if ((maze[row][col] & 0b0010) == 0) { // check east wall
                printf(" ");
            } else {
                printf("|");
            }
            printf("  ");
        }
        if ((maze[row][COLS-1] & 0b0010) == 0) { // check east wall of last cell in row
            printf(" ");
        } else {
            printf("|");
        }
        printf("\n");
    }

    // print bottom border of maze
    for (int col = 0; col < COLS; col++) {
        printf("+--");
    }
    printf("+\n");
}