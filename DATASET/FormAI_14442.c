//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 25
#define MAZE_HEIGHT 25

// Maze cell structure
typedef struct {
    int up;
    int right;
    int down;
    int left;
    int visited;
} Cell;

Cell maze[MAZE_WIDTH][MAZE_HEIGHT];

// Function to generate a random integer between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to initialize the maze
void init_maze() {
    int i, j;

    // Set all cell walls to be intact
    for(i = 0; i < MAZE_WIDTH; i++) {
        for(j = 0; j < MAZE_HEIGHT; j++) {
            maze[i][j].up = 1;
            maze[i][j].right = 1;
            maze[i][j].down = 1;
            maze[i][j].left = 1;
            maze[i][j].visited = 0;
        }
    }
}

// Function to generate the maze using depth-first search
void generate_maze(int x, int y) {
    int direction, new_x, new_y;

    // Mark the current cell as visited
    maze[x][y].visited = 1;

    // Randomly choose a direction
    direction = rand_int(0, 3);

    // Check if the cell in the chosen direction is unvisited
    if(direction == 0 && y > 0 && maze[x][y-1].visited == 0) { // Up
        maze[x][y].up = 0;
        maze[x][y-1].down = 0;
        new_x = x;
        new_y = y-1;
    } else if(direction == 1 && x < MAZE_WIDTH-1 && maze[x+1][y].visited == 0) { // Right
        maze[x][y].right = 0;
        maze[x+1][y].left = 0;
        new_x = x+1;
        new_y = y;
    } else if(direction == 2 && y < MAZE_HEIGHT-1 && maze[x][y+1].visited == 0) { // Down
        maze[x][y].down = 0;
        maze[x][y+1].up = 0;
        new_x = x;
        new_y = y+1;
    } else if(direction == 3 && x > 0 && maze[x-1][y].visited == 0) { // Left
        maze[x][y].left = 0;
        maze[x-1][y].right = 0;
        new_x = x-1;
        new_y = y;
    } else {
        // If no unvisited neighbor is found, backtrack
        return;
    }

    // Recursively call generate_maze on the new cell
    generate_maze(new_x, new_y);
}

// Function to print the maze
void print_maze() {
    int i, j;

    // Print the top border
    for(i = 0; i < MAZE_WIDTH; i++) {
        printf("+--");
    }
    printf("+\n");

    // Print each row of cells
    for(j = 0; j < MAZE_HEIGHT; j++) {
        // Print the left border of each row
        printf("|");

        for(i = 0; i < MAZE_WIDTH; i++) {
            // Print the cell contents
            if(maze[i][j].up == 1) {
                printf("  |");
            } else {
                printf("   ");
            }

            if(maze[i][j].right == 1) {
                printf(" ");
            } else {
                printf("|");
            }
        }

        // Print the right border of each row
        printf("\n+");
        for(i = 0; i < MAZE_WIDTH; i++) {
            if(maze[i][j].down == 1) {
                printf("--+");
            } else {
                printf("  +");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed based on the system time
    srand(time(NULL));

    // Initialize the maze
    init_maze();

    // Generate the maze from the starting cell (0, 0)
    generate_maze(0, 0);

    // Print the maze
    print_maze();

    return 0;
}