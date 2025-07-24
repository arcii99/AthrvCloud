//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>

// Define the size of the grid (assuming it's a square grid)
#define GRID_SIZE 10

// Define the data structure for storing each grid cell
typedef struct GridCell {
    int x;
    int y;
    int distance;
    int visited;
    int obstacle;
    struct GridCell* parent;
} GridCell;

// Define the data structure for the grid
typedef struct Grid {
    GridCell cells[GRID_SIZE][GRID_SIZE];
} Grid;

// Define the function for initializing the grid
void initGrid(Grid* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].x = i;
            grid->cells[i][j].y = j;
            grid->cells[i][j].distance = -1;
            grid->cells[i][j].visited = 0;
            grid->cells[i][j].obstacle = 0;
            grid->cells[i][j].parent = NULL;
        }
    }
}

// Define the function for setting obstacles in the grid
void setObstacles(Grid* grid, int numObstacles) {
    for (int i = 0; i < numObstacles; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        grid->cells[x][y].obstacle = 1;
    }
}

// Define the function for printing the grid
void printGrid(Grid* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].obstacle) {
                printf("X ");
            } else {
                printf("%d ", grid->cells[i][j].distance);
            }
        }
        printf("\n");
    }
}

// Define the function for finding the shortest path using BFS
void findShortestPath(Grid* grid, GridCell* start, GridCell* end) {
    // Define a queue for BFS
    GridCell* queue[GRID_SIZE * GRID_SIZE];
    int front = 0;
    int rear = 0;

    // Enqueue the start cell
    queue[rear++] = start;
    start->distance = 0;
    start->visited = 1;

    while (front != rear) {
        // Dequeue a cell from the queue
        GridCell* curr = queue[front++];
        int currX = curr->x;
        int currY = curr->y;

        // Check if we've reached the end cell
        if (curr == end) {
            break;
        }

        // Add the neighbors of the current cell to the queue
        if (currX > 0 && !grid->cells[currX-1][currY].visited && !grid->cells[currX-1][currY].obstacle) {
            queue[rear++] = &grid->cells[currX-1][currY];
            grid->cells[currX-1][currY].distance = curr->distance + 1;
            grid->cells[currX-1][currY].visited = 1;
            grid->cells[currX-1][currY].parent = curr;
        }
        if (currX < GRID_SIZE-1 && !grid->cells[currX+1][currY].visited && !grid->cells[currX+1][currY].obstacle) {
            queue[rear++] = &grid->cells[currX+1][currY];
            grid->cells[currX+1][currY].distance = curr->distance + 1;
            grid->cells[currX+1][currY].visited = 1;
            grid->cells[currX+1][currY].parent = curr;
        }
        if (currY > 0 && !grid->cells[currX][currY-1].visited && !grid->cells[currX][currY-1].obstacle) {
            queue[rear++] = &grid->cells[currX][currY-1];
            grid->cells[currX][currY-1].distance = curr->distance + 1;
            grid->cells[currX][currY-1].visited = 1;
            grid->cells[currX][currY-1].parent = curr;
        }
        if (currY < GRID_SIZE-1 && !grid->cells[currX][currY+1].visited && !grid->cells[currX][currY+1].obstacle) {
            queue[rear++] = &grid->cells[currX][currY+1];
            grid->cells[currX][currY+1].distance = curr->distance + 1;
            grid->cells[currX][currY+1].visited = 1;
            grid->cells[currX][currY+1].parent = curr;
        }
    }

    // Print the shortest path
    GridCell* curr = end;
    while (curr != start) {
        printf("(%d,%d) -> ", curr->x, curr->y);
        curr = curr->parent;
    }
    printf("(%d,%d)", start->x, start->y);
    printf("\n");
}

int main() {
    // Initialize the grid
    Grid grid;
    initGrid(&grid);

    // Set the obstacles
    setObstacles(&grid, 20);

    // Print the grid
    printf("Initial grid:\n");
    printGrid(&grid);

    // Define the start and end points
    GridCell* start = &grid.cells[0][0];
    GridCell* end = &grid.cells[GRID_SIZE-1][GRID_SIZE-1];

    // Find the shortest path
    printf("Shortest path:\n");
    findShortestPath(&grid, start, end);

    return 0;
}