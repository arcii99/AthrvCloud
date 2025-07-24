//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 7  // Number of rows in the maze
#define COLS 7  // Number of columns in the maze

char maze[ROWS][COLS];  // Maze array

void init_maze(void);
void generate_maze(int row, int col);
bool is_valid(int r, int c);

int main()
{
    srand(time(NULL));  // Initialize random seed

    init_maze();  // Initialize the maze

    int start_row = rand() % ROWS;  // Starting row for maze generation
    int start_col = rand() % COLS;  // Starting column for maze generation

    generate_maze(start_row, start_col);  // Generate the maze

    // Print the maze
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c ", maze[r][c]);  // Print the cell of the maze
        }
        printf("\n");  // End the row
    }

    return 0;
}

/**
 * Initialize the maze to all walls
 */
void init_maze(void)
{
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            maze[r][c] = '#';  // Set the cell to a wall
        }
    }
}

/**
 * Generate the maze recursively
 */
void generate_maze(int row, int col)
{
    int dir[4] = {0, 1, 2, 3};  // Array of directions

    // Shuffle the array of directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tmp = dir[i];
        dir[i] = dir[j];
        dir[j] = tmp;
    }

    // For each direction, try to create a path
    for (int i = 0; i < 4; i++) {
        int r = row, c = col;

        // Move in the direction
        if (dir[i] == 0) r--;
        else if (dir[i] == 1) c++;
        else if (dir[i] == 2) r++;
        else c--;

        // If destination is valid, open up the cell and generate from there
        if (is_valid(r, c)) {
            maze[r][c] = ' ';  // Open up the cell
            generate_maze(r, c);  // Generate from that cell
        }
    }
}

/**
 * Determine if a cell location is valid
 */
bool is_valid(int r, int c)
{
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return false;  // Outside the maze
    if (maze[r][c] != '#') return false;  // Already visited
    return true;
}