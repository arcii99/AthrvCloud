//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Enum for different wall directions
enum wallDirection { UP, DOWN, LEFT, RIGHT };

// Struct for each cell in the maze
typedef struct {
    int x, y;
    int visited;
    int walls[4];
} Cell;

// Function to generate a random number
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to get the index of the direction across from the current direction
int getOppositeDirectionIndex(int direction) {
    if (direction == UP)    return DOWN;
    if (direction == DOWN)  return UP;
    if (direction == LEFT)  return RIGHT;
    if (direction == RIGHT) return LEFT;
}

// Function to remove the wall between two cells
void removeWall(Cell* current, Cell* neighbor) {
    int dx = current->x - neighbor->x;
    int dy = current->y - neighbor->y;
    if (dx == 1) {
        current->walls[LEFT] = 0;
        neighbor->walls[RIGHT] = 0;
    }
    else if (dx == -1) {
        current->walls[RIGHT] = 0;
        neighbor->walls[LEFT] = 0;
    }
    else if (dy == 1) {
        current->walls[UP] = 0;
        neighbor->walls[DOWN] = 0;
    }
    else if (dy == -1) {
        current->walls[DOWN] = 0;
        neighbor->walls[UP] = 0;
    }
}

// Function to get the next unvisited neighbor of a cell
Cell* getNextNeighbor(Cell grid[ROWS][COLS], Cell* cell) {
    int row = cell->x;
    int col = cell->y;
    Cell* neighbors[4];
    int neighborCount = 0;
    if (row > 0 && !grid[row - 1][col].visited) {
        neighbors[neighborCount++] = &grid[row - 1][col];
    }
    if (row < ROWS - 1 && !grid[row + 1][col].visited) {
        neighbors[neighborCount++] = &grid[row + 1][col];
    }
    if (col > 0 && !grid[row][col - 1].visited) {
        neighbors[neighborCount++] = &grid[row][col - 1];
    }
    if (col < COLS - 1 && !grid[row][col + 1].visited) {
        neighbors[neighborCount++] = &grid[row][col + 1];
    }
    if (neighborCount == 0) {
        return NULL;
    }
    int randomIndex = getRandom(0, neighborCount - 1);
    return neighbors[randomIndex];
}

// Function to generate the maze using a depth-first search traversal
void generateMaze(Cell grid[ROWS][COLS]) {
    Cell* current = &grid[0][0];
    current->visited = 1;
    int visitedCount = 1;
    while (visitedCount < ROWS * COLS) {
        Cell* next = getNextNeighbor(grid, current);
        if (next != NULL) {
            next->visited = 1;
            visitedCount++;
            removeWall(current, next);
            current = next;
        }
        else {
            current = &grid[0][0];
        }
    }
}

// Function to print the maze
void printMaze(Cell grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Cell* cell = &grid[i][j];
            if (cell->walls[UP]) {
                printf("+---");
            }
            else {
                printf("+   ");
            }
        }
        printf("+\n");
        for (int j = 0; j < COLS; j++) {
            Cell* cell = &grid[i][j];
            if (cell->walls[LEFT]) {
                printf("|   ");
            }
            else {
                printf("    ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    srand(time(NULL));
    Cell grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].visited = 0;
            for (int k = 0; k < 4; k++) {
                grid[i][j].walls[k] = 1;
            }
        }
    }
    generateMaze(grid);
    printMaze(grid);
    return 0;
}