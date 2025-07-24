//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// Maze cells are either walls or passages.
typedef enum { WALL = 0, PASSAGE, VISITED } CellType;

// Keeps track of the cell's position.
typedef struct {
    int row; // y-coordinate
    int col; // x-coordinate
} Coordinate;

// Initializes the maze with WALL cells (except for the start and end).
void initialize(CellType maze[ROWS][COLS], Coordinate start, Coordinate end) {
    srand(time(NULL)); // Seeds the random number generator.

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == start.row && col == start.col) {
                maze[row][col] = PASSAGE; // Start cell.
            } else if (row == end.row && col == end.col) {
                maze[row][col] = PASSAGE; // End cell.
            } else {
                maze[row][col] = WALL; // Wall cells.
            }
        }
    }
}

// Checks if the position is within the maze.
int is_within_boundaries(Coordinate pos) {
    return pos.row >= 0 && pos.row < ROWS && pos.col >= 0 && pos.col < COLS;
}

// Returns a randomly selected cell from the list of neighbors.
Coordinate select_random_neighbor(Coordinate neighbors[], int num_neighbors) {
    int index = rand() % num_neighbors; // Selects a random index from the array.
    return neighbors[index];
}

// Counts the number of PASSAGE cells around the current cell.
int count_passages(CellType maze[ROWS][COLS], Coordinate current) {
    Coordinate neighbors[4] = { { current.row - 1, current.col }, // North
                                { current.row, current.col + 1 }, // East
                                { current.row + 1, current.col }, // South
                                { current.row, current.col - 1 } };// West

    int num_passages = 0;

    for (int i = 0; i < 4; i++) { // Checks each neighbor cell.
        if (is_within_boundaries(neighbors[i]) && maze[neighbors[i].row][neighbors[i].col] == PASSAGE) {
            num_passages++;
        }
    }

    return num_passages;
}

// Generates a maze using a recursive backtracking algorithm.
void generate_maze(CellType maze[ROWS][COLS], Coordinate current) {
    Coordinate neighbors[4] = { { current.row - 1, current.col }, // North
                                { current.row, current.col + 1 }, // East
                                { current.row + 1, current.col }, // South
                                { current.row, current.col - 1 } };// West

    int num_neighbors = 4;

    // Randomly shuffles the list of neighbors using the Fisher-Yates algorithm.
    for (int i = num_neighbors - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Coordinate temp = neighbors[i];
        neighbors[i] = neighbors[j];
        neighbors[j] = temp;
    }

    for (int i = 0; i < 4; i++) {
        // Selects a random neighbor and removes it from the list.
        Coordinate neighbor = select_random_neighbor(neighbors, num_neighbors);
        neighbors[num_neighbors - 1] = neighbor;
        num_neighbors--;

        // Checks if the neighbor is within boundaries and hasn't been visited yet.
        if (is_within_boundaries(neighbor) && maze[neighbor.row][neighbor.col] == WALL) {
            int num_passages = count_passages(maze, neighbor);

            if (num_passages == 1) { // Connects the current cell and the neighbor.
                maze[neighbor.row][neighbor.col] = PASSAGE;
                generate_maze(maze, neighbor);
            }
        }
    }
}

// Prints the maze to the console.
void print_maze(CellType maze[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            switch (maze[row][col]) {
                case WALL: printf("\u2588\u2588"); break; // Unicode block character.
                case PASSAGE: printf("  "); break;
                case VISITED: printf(". "); break;
            }
        }
        printf("\n");
    }
}

int main() {
    CellType maze[ROWS][COLS];
    Coordinate start = { 0, 0 };
    Coordinate end = { ROWS - 1, COLS - 1 };

    initialize(maze, start, end);
    generate_maze(maze, start);
    maze[end.row][end.col] = PASSAGE;

    print_maze(maze);

    return 0;
}