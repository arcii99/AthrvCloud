//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

void generate_maze(int rows, int cols, char maze[rows][cols]);

int main() {
    char maze[ROWS][COLS];

    srand(time(NULL));
    generate_maze(ROWS, COLS, maze);

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void generate_maze(int rows, int cols, char maze[rows][cols]) {
    // Initialize maze with walls
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = '.';
            }
        }
    }

    // Place the starting and ending points
    int start_row = rand() % (rows - 2) + 1;
    int start_col = rand() % (cols - 2) + 1;
    maze[start_row][start_col] = 'S';

    int end_row, end_col;
    do {
        end_row = rand() % (rows - 2) + 1;
        end_col = rand() % (cols - 2) + 1;
    } while (maze[end_row][end_col] == 'S');
    maze[end_row][end_col] = 'E';

    // Generate the maze
    int row = start_row;
    int col = start_col;
    int num_cells_visited = 1;
    int total_cells = (rows - 2) * (cols - 2);
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (num_cells_visited < total_cells) {
        // Shuffle the directions
        for (int i = 0; i < 4; i++) {
            int temp;
            int random_index = rand() % 4;
            temp = directions[i][0];
            directions[i][0] = directions[random_index][0];
            directions[random_index][0] = temp;
            temp = directions[i][1];
            directions[i][1] = directions[random_index][1];
            directions[random_index][1] = temp;
        }

        // Visit the adjacent cell in each direction
        int cells_visited_in_direction = 0;
        for (int i = 0; i < 4; i++) {
            int next_row = row + directions[i][0];
            int next_col = col + directions[i][1];

            if (maze[next_row][next_col] == '.') {
                maze[next_row][next_col] = '#';
                maze[row + directions[i][0] / 2][col + directions[i][1] / 2] = '#';
                row = next_row;
                col = next_col;
                num_cells_visited++;
                cells_visited_in_direction++;
                break;
            }
        }

        // If no adjacent cell was visited, backtrack
        if (cells_visited_in_direction == 0) {
            for (int i = 0; i < 4; i++) {
                int next_row = row + directions[i][0];
                int next_col = col + directions[i][1];

                if (maze[next_row][next_col] == '#') {
                    row = next_row;
                    col = next_col;
                    break;
                }
            }
        }
    }
}