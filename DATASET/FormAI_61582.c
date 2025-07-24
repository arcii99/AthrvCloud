//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initializing constants
#define ROWS 20
#define COLS 20
#define WALL 0
#define PATH 1
#define START_ROW 1
#define START_COL 1
#define END_ROW ROWS-2
#define END_COL COLS-2

// Function to print the maze
void print_maze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%s", maze[i][j] == WALL ? "██" : "  ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Setting the seed

    // Initializing variables
    int maze[ROWS][COLS] = {0};
    int visited[ROWS][COLS] = {0};
    int row = START_ROW;
    int col = START_COL;

    // Setting start and end points
    maze[row][col] = PATH;
    maze[END_ROW][END_COL] = PATH;

    // Setting the walls for the maze
    for (int i = 0; i < ROWS; i++) {
        maze[i][0] = WALL;
        maze[i][COLS-1] = WALL;
    }
    for (int i = 0; i < COLS; i++) {
        maze[0][i] = WALL;
        maze[ROWS-1][i] = WALL;
    }

    // Generating the maze
    while (row != END_ROW || col != END_COL) {
        visited[row][col] = 1;

        // Randomly choosing the next move
        int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;
            int tmp[2];
            tmp[0] = moves[r][0];
            tmp[1] = moves[r][1];
            moves[r][0] = moves[i][0];
            moves[r][1] = moves[i][1];
            moves[i][0] = tmp[0];
            moves[i][1] = tmp[1];
        }

        int moved = 0;
        for (int i = 0; i < 4; i++) {
            int next_row = row + moves[i][0];
            int next_col = col + moves[i][1];
            if (next_row >= 0 && next_row < ROWS && next_col >= 0 && next_col < COLS && visited[next_row][next_col] == 0) {
                // Making the path
                if (next_row != row) {
                    maze[(next_row + row) / 2][col] = PATH;
                }
                if (next_col != col) {
                    maze[row][(next_col + col) / 2] = PATH;
                }
                row = next_row;
                col = next_col;
                maze[row][col] = PATH;
                moved = 1;
                break;
            }
        }
        // Backtracking if there is no possible move
        if (!moved) {
            while (visited[row][col] == 1) {
                col--;
                if (col < 0) {
                    col = COLS-1;
                    row--;
                }
                if (row < 0) {
                    row = ROWS-1;
                }
            }
        }
    }

    // Printing the maze
    print_maze(maze);

    return 0;
}