//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the maze
#define WIDTH 21    
#define HEIGHT 21   
#define WALL 1      
#define PATH 0      

// Function prototypes
void generate_maze(int maze[HEIGHT][WIDTH], int row, int col);
void print_maze(int maze[HEIGHT][WIDTH]);

int main(void) {
    // Seed random number generator
    srand((unsigned)time(NULL));

    // Initialize maze to all walls
    int maze[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }

    // Generate maze starting at position (1, 1)
    generate_maze(maze, 1, 1);

    // Print maze
    print_maze(maze);

    return 0;
}

void generate_maze(int maze[HEIGHT][WIDTH], int row, int col) {
    // Possible directions to move
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Randomize direction array
    for (int i = 0; i < 4; i++) {
        int rand_index = rand() % 4;
        int tmp_row = directions[i][0];
        int tmp_col = directions[i][1];
        directions[i][0] = directions[rand_index][0];
        directions[i][1] = directions[rand_index][1];
        directions[rand_index][0] = tmp_row;
        directions[rand_index][1] = tmp_col;
    }

    // Mark current position as path
    maze[row][col] = PATH;

    // Loop through possible directions
    for (int i = 0; i < 4; i++) {
        int next_row = row + directions[i][0] * 2;
        int next_col = col + directions[i][1] * 2;

        // Check if next position is valid
        if (next_row > 0 && next_row < HEIGHT - 1 && next_col > 0 && next_col < WIDTH - 1 && maze[next_row][next_col] == WALL) {
            // Remove the wall between current and next position
            maze[row + directions[i][0]][col + directions[i][1]] = PATH;

            // Recursively call generate maze with next position
            generate_maze(maze, next_row, next_col);
        }
    }
}

void print_maze(int maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == WALL) {
                printf("\u2588\u2588");  // Unicode character for solid block
            } else {
                printf("  ");  // Two spaces for path
            }
        }
        printf("\n");
    }
}