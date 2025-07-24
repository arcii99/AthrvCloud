//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

// Represent the cells in the maze
typedef struct _cell {
    int visited;
    int walls[4]; // 0 - North, 1 - East, 2 - South, 3 - West
} Cell;

// Initialize the maze
void init_maze(Cell maze[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j].visited = 0;
            maze[i][j].walls[0] = 1;
            maze[i][j].walls[1] = 1;
            maze[i][j].walls[2] = 1;
            maze[i][j].walls[3] = 1;
        }
    }
}

// Check if the current cell has any unvisited neighbors
int are_unvisited_neighbors(Cell maze[][COLS], int row, int col) {
    if (row > 0 && !maze[row-1][col].visited)
        return 1;
    if (row < ROWS-1 && !maze[row+1][col].visited)
        return 1;
    if (col > 0 && !maze[row][col-1].visited)
        return 1;
    if (col < COLS-1 && !maze[row][col+1].visited)
        return 1;

    return 0;
}

// Generate the maze
void generate_maze(Cell maze[][COLS]) {
    int row = 0, col = 0;
    int total_visited = 1;
    int direction;

    // Seed the random number generator
    srand(time(NULL));

    // Select the starting cell
    maze[row][col].visited = 1;

    // While there are unvisited cells
    while (total_visited < ROWS * COLS) {
        // Check if the current cell has any unvisited neighbors
        if (are_unvisited_neighbors(maze, row, col)) {
            // Select a random unvisited neighbor
            do {
                direction = rand() % 4;
            } while (direction == 0 && row == 0 ||
                     direction == 1 && col == COLS-1 ||
                     direction == 2 && row == ROWS-1 ||
                     direction == 3 && col == 0 ||
                     maze[(direction == 0) ? row-1 : (direction == 1) ? row : (direction == 2) ? row+1 : row][(direction == 3) ? col-1 : (direction == 0 || direction == 2) ? col : col+1].visited);

            // Remove the wall between the current cell and the selected neighbor
            maze[row][col].walls[direction] = 0;
            maze[(direction == 0) ? row-1 : (direction == 1) ? row : (direction == 2) ? row+1 : row][(direction == 3) ? col-1 : (direction == 0 || direction == 2) ? col : col+1].walls[(direction + 2) % 4] = 0;

            // Move to the selected neighbor
            row += (direction == 0) ? -1 : (direction == 2) ? 1 : 0;
            col += (direction == 3) ? -1 : (direction == 1) ? 1 : 0;
            maze[row][col].visited = 1;
            total_visited++;
        }
        else {
            // Backtrack to the previous cell
            do {
                row += (direction == 0) ? 1 : (direction == 2) ? -1 : 0;
                col += (direction == 3) ? 1 : (direction == 1) ? -1 : 0;
            } while (!are_unvisited_neighbors(maze, row, col));
        }
    }
}

// Print the maze
void print_maze(Cell maze[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j].walls[0] ? '_' : ' ');
        }
        printf("\n");
        for (j = 0; j < COLS; j++) {
            printf("%c%c", maze[i][j].walls[3] ? '|' : ' ', maze[i][j].walls[1] ? '_' : ' ');
        }
        printf("%c\n", maze[i][j-1].walls[2] ? '|' : ' ');
    }
}

// Main function
int main(void) {
    Cell maze[ROWS][COLS];

    // Initialize the maze
    init_maze(maze);

    // Generate the maze
    generate_maze(maze);

    // Print the maze
    print_maze(maze);

    return 0;
}