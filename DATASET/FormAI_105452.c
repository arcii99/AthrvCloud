//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Define the structure of a cell
typedef struct cell {
    int row, col;
    bool visited;
    int fScore, gScore, hScore;
    struct cell* parent;
} cell_t;

// Create 2D grid of cells
cell_t grid[ROW][COL];

/**
 * Perform A* pathfinding algorithm on the given start and end cells
 * 
 * @param startCell The starting cell
 * @param endCell The target cell
 **/
void aStarPathfinding(cell_t* startCell, cell_t* endCell) {

    printf("Let's find a path! ");

    // Initialize start cell's gScore and fScore to 0, and hScore to distance between start and end cells
    startCell->gScore = 0;
    startCell->fScore = startCell->gScore + abs(endCell->row - startCell->row) + abs(endCell->col - startCell->col);
    startCell->hScore = abs(endCell->row - startCell->row) + abs(endCell->col - startCell->col);

    // Create open and close sets for algorithm
    cell_t* openSet[ROW * COL];
    int openCount = 1;
    openSet[0] = startCell;
    cell_t* closeSet[ROW * COL];
    int closeCount = 0;

    while (openCount > 0) {

        // Find cell with lowest fScore in open set
        cell_t* currCell = openSet[0];
        int currIndex = 0;
        for (int i = 0; i < openCount; i++) {
            if (openSet[i]->fScore < currCell->fScore) {
                currCell = openSet[i];
                currIndex = i;
            }
        }

        // Check if current cell is the end cell
        if (currCell == endCell) {
            printf(" found the target cell!\n");
            return;
        }

        // Move current cell from open to close set
        openSet[currIndex] = openSet[openCount - 1];
        openCount--;
        closeSet[closeCount] = currCell;
        closeCount++;

        // For each neighbor, calculate its tentative gScore and fScore
        int neighborsCount = 0;
        cell_t* neighbors[4];
        int row = currCell->row, col = currCell->col;
        if (row > 0 && !grid[row - 1][col].visited) {
            neighbors[neighborsCount] = &grid[row - 1][col];
            neighborsCount++;
        }
        if (col > 0 && !grid[row][col - 1].visited) {
            neighbors[neighborsCount] = &grid[row][col - 1];
            neighborsCount++;
        }
        if (row < ROW - 1 && !grid[row + 1][col].visited) {
            neighbors[neighborsCount] = &grid[row + 1][col];
            neighborsCount++;
        }
        if (col < COL - 1 && !grid[row][col + 1].visited) {
            neighbors[neighborsCount] = &grid[row][col + 1];
            neighborsCount++;
        }

        for (int i = 0; i < neighborsCount; i++) {
            cell_t* neighbor = neighbors[i];

            neighbor->visited = true;

            int tentativeGScore = currCell->gScore + 1; // Distance between current and neighbor is 1
            bool betterGScore = false;
            if (neighbor->gScore == 0) {
                neighbor->hScore = abs(endCell->row - neighbor->row) + abs(endCell->col - neighbor->col);
                betterGScore = true;
            } else if (tentativeGScore < neighbor->gScore) {
                betterGScore = true;
            }

            if (betterGScore) {
                neighbor->parent = currCell;
                neighbor->gScore = tentativeGScore;
                neighbor->fScore = neighbor->gScore + neighbor->hScore;

                // Add neighbor to open set if not already in set
                bool inOpenSet = false;
                for (int j = 0; j < openCount; j++) {
                    if (openSet[j] == neighbor) {
                        inOpenSet = true;
                        break;
                    }
                }
                if (!inOpenSet) {
                    openSet[openCount] = neighbor;
                    openCount++;
                }
            }
        }
    }

    // If algorithm did not find a path
    printf(" sorry I couldn't find a path!\n");
}

/**
 * Create a 2D grid of cells and call the A* pathfinding algorithm
 **/ 
int main() {

    // Create 2D grid of cells
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            grid[row][col].row = row;
            grid[row][col].col = col;
            grid[row][col].visited = false;
            grid[row][col].parent = NULL;
            grid[row][col].fScore = grid[row][col].gScore = grid[row][col].hScore = 0;
        }
    }

    // Select random start and end cells
    int startRow = rand() % ROW;
    int startCol = rand() % COL;
    int endRow = rand() % ROW;
    int endCol = rand() % COL;

    // Make sure start and end cells are not the same
    while (startRow == endRow && startCol == endCol) {
        endRow = rand() % ROW;
        endCol = rand() % COL;
    }

    // Call the A* pathfinding algorithm with randomly selected start and end cells
    aStarPathfinding(&grid[startRow][startCol], &grid[endRow][endCol]);

    return 0;
}