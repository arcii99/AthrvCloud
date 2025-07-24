//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the grid
#define ROWS 10
#define COLS 10

// Struct for storing the cell information
typedef struct {
    int row, col;
    double f, g, h;
    bool isWall;
    bool isVisited;
    struct Cell* parent;
} Cell;

// Function to initialise the grid
void initialiseGrid(Cell grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].f = 0.0;
            grid[i][j].g = 0.0;
            grid[i][j].h = 0.0;
            grid[i][j].isWall = false;
            grid[i][j].isVisited = false;
            grid[i][j].parent = NULL;
        }
    }
}

// Function to print the grid
void printGrid(Cell grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].isWall) {
                printf("#\t");
            } else {
                printf(".\t");
            }
        }
        printf("\n");
    }
}

// Function to calculate the Manhattan distance between two cells
double manhattanDistance(Cell* current, Cell* end) {
    int rowDiff = abs(current->row - end->row);
    int colDiff = abs(current->col - end->col);
    return rowDiff + colDiff;
}

// Function to get the neighbours of a cell
void getNeighbours(Cell* current, Cell grid[ROWS][COLS], Cell* neighbours[]) {
    int row = current->row;
    int col = current->col;
    int count = 0;

    // East
    if (col + 1 < COLS && !grid[row][col + 1].isVisited && !grid[row][col + 1].isWall) {
        neighbours[count] = &grid[row][col + 1];
        count++;
    }

    // South
    if (row + 1 < ROWS && !grid[row + 1][col].isVisited && !grid[row + 1][col].isWall) {
        neighbours[count] = &grid[row + 1][col];
        count++;
    }

    // West
    if (col - 1 >= 0 && !grid[row][col - 1].isVisited && !grid[row][col - 1].isWall) {
        neighbours[count] = &grid[row][col - 1];
        count++;
    }

    // North
    if (row - 1 >= 0 && !grid[row - 1][col].isVisited && !grid[row - 1][col].isWall) {
        neighbours[count] = &grid[row - 1][col];
        count++;
    }

    // South East
    if (row + 1 < ROWS && col + 1 < COLS && !grid[row + 1][col + 1].isVisited && !grid[row + 1][col + 1].isWall) {
        neighbours[count] = &grid[row + 1][col + 1];
        count++;
    }

    // South West
    if (row + 1 < ROWS && col - 1 >= 0 && !grid[row + 1][col - 1].isVisited && !grid[row + 1][col - 1].isWall) {
        neighbours[count] = &grid[row + 1][col - 1];
        count++;
    }

    // North East
    if (row - 1 >= 0 && col + 1 < COLS && !grid[row - 1][col + 1].isVisited && !grid[row - 1][col + 1].isWall) {
        neighbours[count] = &grid[row - 1][col + 1];
        count++;
    }

    // North West
    if (row - 1 >= 0 && col - 1 >= 0 && !grid[row - 1][col - 1].isVisited && !grid[row - 1][col - 1].isWall) {
        neighbours[count] = &grid[row - 1][col - 1];
        count++;
    }

    neighbours[count] = NULL;
}

// Function to sort an array of cells based on their f value
void sort(Cell* arr[], int size) {
    int i, j;
    Cell* temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[j]->f < arr[i]->f) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to find the shortest path between two cells using A* algorithm
bool aStar(Cell grid[ROWS][COLS], Cell* start, Cell* end) {
    // Create the open and closed lists
    Cell* openList[ROWS * COLS];
    Cell* closedList[ROWS * COLS];
    int openSize = 0;
    int closedSize = 0;

    // Add the start cell to the open list
    start->g = 0.0;
    start->h = manhattanDistance(start, end);
    start->f = start->g + start->h;
    openList[openSize] = start;
    openSize++;

    // Loop until the open list is empty or the end cell is found
    while (openSize > 0) {
        // Get the cell with the lowest f value
        sort(openList, openSize);
        Cell* current = openList[0];

        // Check if the current cell is the end cell
        if (current == end) {
            return true;
        }

        // Remove the current cell from the open list and add it to the closed list
        for (int i = 0; i < openSize; i++) {
            if (openList[i] == current) {
                openList[i] = NULL;
                openSize--;
                break;
            }
        }
        closedList[closedSize] = current;
        closedSize++;

        // Get the neighbours of the current cell
        Cell* neighbours[8];
        getNeighbours(current, grid, neighbours);

        // Loop through the neighbours
        for (int i = 0; i < 8 && neighbours[i] != NULL; i++) {
            Cell* neighbour = neighbours[i];
            double tempG = current->g + manhattanDistance(current, neighbour);

            // If the neighbour is already in the closed list or the new g value is greater than the current g value, skip this neighbour
            bool neighbourFound = false;
            for (int j = 0; j < closedSize && !neighbourFound; j++) {
                if (closedList[j] == neighbour) {
                    neighbourFound = true;
                }
            }
            if (neighbourFound || tempG >= neighbour->g) {
                continue;
            }

            // Calculate the new f, g and h values for the neighbour and add it to the open list
            neighbour->parent = current;
            neighbour->g = tempG;
            neighbour->h = manhattanDistance(neighbour, end);
            neighbour->f = neighbour->g + neighbour->h;
            openList[openSize] = neighbour;
            openSize++;
        }
    }

    // If the end cell is not found, return false
    return false;
}

int main() {
    // Initialise the grid
    Cell grid[ROWS][COLS];
    initialiseGrid(grid);

    // Set some cells as walls
    grid[4][2].isWall = true;
    grid[4][3].isWall = true;
    grid[4][4].isWall = true;
    grid[4][5].isWall = true;
    grid[4][6].isWall = true;

    // Print the grid
    printf("Initial grid:\n");
    printGrid(grid);

    // Find the shortest path between two cells
    Cell* start = &grid[0][0];
    Cell* end = &grid[9][9];
    bool foundPath = aStar(grid, start, end);

    // Print the final grid with the path marked
    if (foundPath) {
        printf("Final grid:\n");
        Cell* current = end;
        while (current != start) {
            current->isVisited = true;
            current = current->parent;
        }
        printGrid(grid);
    } else {
        printf("No path found.\n");
    }

    return 0;
}