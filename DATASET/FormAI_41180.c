//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the maze size
#define WIDTH 15
#define HEIGHT 10

// Define constants for the different types of cells in the maze
#define CELL_EMPTY 0
#define CELL_WALL 1

// Define a struct to represent a point in the maze
typedef struct {
    int x;
    int y;
} Point;

// Define a struct to represent a cell in the maze
typedef struct {
    int type;
    int visited;
} Cell;

// Function prototypes
void generateMaze(Cell maze[HEIGHT][WIDTH]);
void printMaze(Cell maze[HEIGHT][WIDTH]);

// Main function
int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create the maze
    Cell maze[HEIGHT][WIDTH];

    // Generate the maze
    generateMaze(maze);

    // Print the maze
    printMaze(maze);

    return 0;
}

// Generate the maze using a depth-first search algorithm
void generateMaze(Cell maze[HEIGHT][WIDTH])
{
    // Initialize all cells to be walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x].type = CELL_WALL;
            maze[y][x].visited = 0;
        }
    }

    // Choose a random starting point
    Point current = {rand() % WIDTH, rand() % HEIGHT};

    // Mark the starting point as visited
    maze[current.y][current.x].visited = 1;

    // Create a list of unvisited neighbors
    Point neighbors[4];
    int numNeighbors = 0;

    // Repeat until all cells have been visited
    while (1) {
        // Find the unvisited neighbors of the current cell
        numNeighbors = 0;
        if (current.x > 0 && !maze[current.y][current.x - 1].visited) {
            neighbors[numNeighbors++] = (Point){current.x - 1, current.y};
        }
        if (current.x < WIDTH - 1 && !maze[current.y][current.x + 1].visited) {
            neighbors[numNeighbors++] = (Point){current.x + 1, current.y};
        }
        if (current.y > 0 && !maze[current.y - 1][current.x].visited) {
            neighbors[numNeighbors++] = (Point){current.x, current.y - 1};
        }
        if (current.y < HEIGHT - 1 && !maze[current.y + 1][current.x].visited) {
            neighbors[numNeighbors++] = (Point){current.x, current.y + 1};
        }

        // If there are unvisited neighbors, choose one at random and break down the wall between it and the current cell
        if (numNeighbors > 0) {
            // Choose a random neighbor
            Point chosen = neighbors[rand() % numNeighbors];

            // Break down the wall between the current cell and the chosen neighbor
            if (chosen.x < current.x) {
                maze[current.y][current.x].type &= ~0x01;
                maze[chosen.y][chosen.x].type &= ~0x02;
            } else if (chosen.x > current.x) {
                maze[current.y][current.x].type &= ~0x02;
                maze[chosen.y][chosen.x].type &= ~0x01;
            } else if (chosen.y < current.y) {
                maze[current.y][current.x].type &= ~0x04;
                maze[chosen.y][chosen.x].type &= ~0x08;
            } else {
                maze[current.y][current.x].type &= ~0x08;
                maze[chosen.y][chosen.x].type &= ~0x04;
            }

            // Move to the chosen neighbor and mark it as visited
            current = chosen;
            maze[current.y][current.x].visited = 1;
        } else {
            // If there are no unvisited neighbors, back up to the last cell with unvisited neighbors
            int found = 0;
            for (int y = 0; y < HEIGHT; y++) {
                for (int x = 0; x < WIDTH; x++) {
                    if (!maze[y][x].visited && (
                            (x > 0 && maze[y][x - 1].visited) ||
                            (x < WIDTH - 1 && maze[y][x + 1].visited) ||
                            (y > 0 && maze[y - 1][x].visited) ||
                            (y < HEIGHT - 1 && maze[y + 1][x].visited)
                    )) {
                        current = (Point){x, y};
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }

            // If no such cell exists, the maze is complete
            if (!found) break;
        }
    }
}

// Print the maze
void printMaze(Cell maze[HEIGHT][WIDTH])
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(maze[y][x].type == CELL_EMPTY ? "  " : "██");
        }
        printf("\n");
    }
}