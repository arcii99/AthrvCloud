//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Structure for a cell in the grid
typedef struct Cell {
    int row, col;
} Cell;

// Structure for the queue that stores the nodes to be explored
typedef struct Queue {
    Cell data[ROWS * COLS];
    int front, rear;
} Queue;

// Add a cell to the queue
void enqueue(Queue *queue, Cell cell) {
    queue->data[queue->rear] = cell;
    queue->rear++;
}

// Remove a cell from the queue
Cell dequeue(Queue *queue) {
    Cell cell;
    cell = queue->data[queue->front];
    queue->front++;
    return cell;
}

// Initialize the queue
void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

// Check if a given cell is a valid cell to explore
bool is_valid(int row, int col, int grid[][COLS], bool visited[][COLS]) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    if (grid[row][col] == 1 || visited[row][col]) {
        return false;
    }
    return true;
}

// Perform breadth-first search to find the shortest path between the start and end cells
void bfs(Cell start, Cell end, int grid[][COLS]) {
    // Create a boolean array to keep track of visited cells
    bool visited[ROWS][COLS] = {false};

    // Create a queue to store nodes to be explored
    Queue queue;
    init_queue(&queue);

    // Add the start cell to the queue and mark it as visited
    enqueue(&queue, start);
    visited[start.row][start.col] = true;

    // Keep exploring nodes until the end cell is found or the queue is empty
    while (queue.front != queue.rear) {
        // Dequeue the front node and explore its neighbors
        Cell current = dequeue(&queue);
        if (current.row == end.row && current.col == end.col) {
            printf("Shortest path found\n");
            return;
        }

        // Explore the neighbors of the current cell
        int row = current.row;
        int col = current.col;
        if (is_valid(row, col-1, grid, visited)) { // Check left neighbor
            enqueue(&queue, (Cell){row, col-1});
            visited[row][col-1] = true;
        }
        if (is_valid(row-1, col, grid, visited)) { // Check top neighbor
            enqueue(&queue, (Cell){row-1, col});
            visited[row-1][col] = true;
        }
        if (is_valid(row, col+1, grid, visited)) { // Check right neighbor
            enqueue(&queue, (Cell){row, col+1});
            visited[row][col+1] = true;
        }
        if (is_valid(row+1, col, grid, visited)) { // Check bottom neighbor
            enqueue(&queue, (Cell){row+1, col});
            visited[row+1][col] = true;
        }
    }

    // If no path was found, print error message
    printf("Error: no path found\n");
}

int main() {
    // Create a grid to represent the maze
    int grid[ROWS][COLS] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Define the start and end cells
    Cell start = {0, 0};
    Cell end = {9, 9};

    // Find the shortest path between the start and end cells
    bfs(start, end, grid);

    return 0;
}