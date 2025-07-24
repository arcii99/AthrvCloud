//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 15

void generate_maze(int maze[MAZE_SIZE][MAZE_SIZE], int curr_row, int curr_col);
void print_maze(int maze[MAZE_SIZE][MAZE_SIZE]);

int main()
{
    int maze[MAZE_SIZE][MAZE_SIZE] = {0}; // Initialize maze with all 0s
    srand(time(NULL)); // Seed random number generator with the current time

    generate_maze(maze, 0, 0);
    print_maze(maze);

    return 0;
}

void generate_maze(int maze[MAZE_SIZE][MAZE_SIZE], int curr_row, int curr_col)
{
    static int visited[MAZE_SIZE][MAZE_SIZE] = {0}; // Keep track of visited cells
    visited[curr_row][curr_col] = 1; // Mark current cell as visited

    // Define the four possible directions to move in the maze
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Shuffle the directions array randomly
    for (int i = 0; i < 4; i++) {
        int random_index = rand() % 4;
        int temp_row = directions[i][0];
        int temp_col = directions[i][1];
        directions[i][0] = directions[random_index][0];
        directions[i][1] = directions[random_index][1];
        directions[random_index][0] = temp_row;
        directions[random_index][1] = temp_col;
    }

    // Move in each possible direction
    for (int i = 0; i < 4; i++) {
        int new_row = curr_row + directions[i][0];
        int new_col = curr_col + directions[i][1];

        // Check if new cell is within bounds and unvisited
        if (new_row >= 0 && new_row < MAZE_SIZE && new_col >= 0 && new_col < MAZE_SIZE) {
            if (visited[new_row][new_col] == 0) {
                // Mark the wall between the current cell and the new cell as removed
                if (directions[i][0] == -1) {
                    maze[curr_row][curr_col] -= 1; // Remove north wall of current cell
                    maze[new_row][new_col] -= 4; // Remove south wall of new cell
                } else if (directions[i][0] == 1) {
                    maze[curr_row][curr_col] -= 4; // Remove south wall of current cell
                    maze[new_row][new_col] -= 1; // Remove north wall of new cell
                } else if (directions[i][1] == -1) {
                    maze[curr_row][curr_col] -= 2; // Remove west wall of current cell
                    maze[new_row][new_col] -= 8; // Remove east wall of new cell
                } else {
                    maze[curr_row][curr_col] -= 8; // Remove east wall of current cell
                    maze[new_row][new_col] -= 2; // Remove west wall of new cell
                }

                // Move to the new cell and generate maze recursively
                generate_maze(maze, new_row, new_col);
            }
        }
    }
}

void print_maze(int maze[MAZE_SIZE][MAZE_SIZE])
{
    printf(" ");
    for (int i = 0; i < MAZE_SIZE * 2 - 1; i++) {
        printf("_");
    }
    printf("\n");

    for (int row = 0; row < MAZE_SIZE; row++) {
        printf("|");
        for (int col = 0; col < MAZE_SIZE; col++) {
            // Print space and vertical wall if cell is blocked on top
            if (maze[row][col] & 1) {
                printf(" ");
            } else {
                printf("_");
            }

            // Print space if cell is unvisited, otherwise print '_'
            if (row == MAZE_SIZE - 1 && col == MAZE_SIZE - 1) {
                printf(" ");
            } else if (maze[row][col] & 8) {
                printf("_");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}