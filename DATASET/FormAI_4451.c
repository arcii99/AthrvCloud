//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

// Structure to hold meta information about each cell in the maze
typedef struct {
    int visited;
    int north;
    int east;
    int south;
    int west;
} Cell;

// Function prototype for maze generation
void generate_maze(Cell cells[][COL], int row, int col);

// Function prototype for pathfinding algorithm
void find_path(Cell cells[][COL], int row, int col);

int main() {
    Cell maze[ROW][COL];
    
    // Initialize all cells in the maze to unvisited and no walls
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j].visited = 0;
            maze[i][j].north = 0;
            maze[i][j].east = 0;
            maze[i][j].south = 0;
            maze[i][j].west = 0;
        }
    }

    // Generate the maze
    generate_maze(maze, ROW, COL);

    // Find a path through the maze
    find_path(maze, ROW, COL);

    return 0;
}

void generate_maze(Cell cells[][COL], int row, int col) {
    srand(time(NULL));
    int curr_row = rand() % row;
    int curr_col = rand() % col;
    int visited_count = 1;

    // Mark the starting cell as visited
    cells[curr_row][curr_col].visited = 1;

    // Loop until all cells have been visited
    while (visited_count < row * col) {
        // Determine the possible neighbors of the current cell
        int north_row = curr_row - 1;
        int south_row = curr_row + 1;
        int west_col = curr_col - 1;
        int east_col = curr_col + 1;
        
        // Keep track of how many neighbors the current cell has
        int num_neighbors = 0;

        // Check if the north neighbor is valid and unvisited
        if (north_row >= 0 && !cells[north_row][curr_col].visited) {
            num_neighbors++;
        }

        // Check if the south neighbor is valid and unvisited
        if (south_row < row && !cells[south_row][curr_col].visited) {
            num_neighbors++;
        }

        // Check if the west neighbor is valid and unvisited
        if (west_col >= 0 && !cells[curr_row][west_col].visited) {
            num_neighbors++;
        }

        // Check if the east neighbor is valid and unvisited
        if (east_col < col && !cells[curr_row][east_col].visited) {
            num_neighbors++;
        }

        // If the current cell has at least one unvisited neighbor, choose one and remove the wall between them
        if (num_neighbors > 0) {
            int direction = rand() % num_neighbors;
            if (north_row >= 0 && !cells[north_row][curr_col].visited && direction == 0) {
                // Remove the north wall
                cells[curr_row][curr_col].north = 0;
                cells[north_row][curr_col].south = 0;
                curr_row = north_row;
            } else if (south_row < row && !cells[south_row][curr_col].visited && direction == 1) {
                // Remove the south wall
                cells[curr_row][curr_col].south = 0;
                cells[south_row][curr_col].north = 0;
                curr_row = south_row;
            } else if (west_col >= 0 && !cells[curr_row][west_col].visited && direction == 2) {
                // Remove the west wall
                cells[curr_row][curr_col].west = 0;
                cells[curr_row][west_col].east = 0;
                curr_col = west_col;
            } else {
                // Remove the east wall
                cells[curr_row][curr_col].east = 0;
                cells[curr_row][east_col].west = 0;
                curr_col = east_col;
            }
            
            // Mark the new current cell as visited
            cells[curr_row][curr_col].visited = 1;
            visited_count++;
        }
    }
}

void find_path(Cell cells[][COL], int row, int col) {
    int start_row = 0;
    int start_col = 0;
    int end_row = row - 1;
    int end_col = col - 1;
    
    // Initialize the path as empty
    int path[row * col][2];
    int path_len = 0;

    // Mark the starting cell as part of the path
    path[path_len][0] = start_row;
    path[path_len][1] = start_col;
    path_len++;

    // Loop until the end cell has been reached
    int curr_row = start_row;
    int curr_col = start_col;
    while (curr_row != end_row || curr_col != end_col) {
        // Determine the possible neighbors of the current cell
        int north_row = curr_row - 1;
        int south_row = curr_row + 1;
        int west_col = curr_col - 1;
        int east_col = curr_col + 1;
        
        // Determine the direction of the end cell relative to the current cell
        int direction;
        if (end_col > curr_col) {
            direction = 0;
        } else if (end_row < curr_row) {
            direction = 1;
        } else if (end_col < curr_col) {
            direction = 2;
        } else {
            direction = 3;
        }

        // Check if there is a path in the desired direction
        if (direction == 0 && !cells[curr_row][curr_col].east) {
            curr_col++;
        } else if (direction == 1 && !cells[curr_row][curr_col].north) {
            curr_row--;
        } else if (direction == 2 && !cells[curr_row][curr_col].west) {
            curr_col--;
        } else if (direction == 3 && !cells[curr_row][curr_col].south) {
            curr_row++;
        } else {
            // Check if there is a path to the right
            if (!cells[curr_row][curr_col].east && curr_col + 1 < col && !cells[curr_row][curr_col + 1].visited) {
                curr_col++;
            } else {
                // Check if there is a path to the north
                if (!cells[curr_row][curr_col].north && curr_row - 1 >= 0 && !cells[curr_row - 1][curr_col].visited) {
                    curr_row--;
                } else {
                    // Check if there is a path to the left
                    if (!cells[curr_row][curr_col].west && curr_col - 1 >= 0 && !cells[curr_row][curr_col - 1].visited) {
                        curr_col--;
                    } else {
                        // Check if there is a path to the south
                        if (!cells[curr_row][curr_col].south && curr_row + 1 < row && !cells[curr_row + 1][curr_col].visited) {
                            curr_row++;
                        } else {
                            // If there is no viable path, backtrack until a new path is found
                            while (path_len > 1) {
                                int prev_row = path[path_len - 2][0];
                                int prev_col = path[path_len - 2][1];
                                int prev_direction;
                                if (prev_col < curr_col) {
                                    prev_direction = 0;
                                } else if (prev_row > curr_row) {
                                    prev_direction = 1;
                                } else if (prev_col > curr_col) {
                                    prev_direction = 2;
                                } else {
                                    prev_direction = 3;
                                }
                                if (prev_direction == 0 && !cells[curr_row][curr_col].west) {
                                    path_len--;
                                    curr_col--;
                                    break;
                                } else if (prev_direction == 1 && !cells[curr_row][curr_col].south) {
                                    path_len--;
                                    curr_row++;
                                    break;
                                } else if (prev_direction == 2 && !cells[curr_row][curr_col].east) {
                                    path_len--;
                                    curr_col++;
                                    break;
                                } else if (prev_direction == 3 && !cells[curr_row][curr_col].north) {
                                    path_len--;
                                    curr_row--;
                                    break;
                                } else {
                                    path_len--;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        // Mark the current cell as part of the path
        path[path_len][0] = curr_row;
        path[path_len][1] = curr_col;
        path_len++;
    }
    
    // Print the path through the maze
    for (int i = 0; i < path_len; i++) {
        printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
}