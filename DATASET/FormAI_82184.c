//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 10
#define COLS 10

// Define the maze
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '.'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '#', '#', '#', '.', '.'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define the starting and ending points
int startRow = 1;
int startCol = 1;
int endRow = 8;
int endCol = 8;

// Define the queue for the BFS algorithm
typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position positions[ROWS*COLS];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == -1 && queue->rear == -1;
}

bool isQueueFull(Queue* queue) {
    return queue->rear == ROWS*COLS - 1;
}

void enqueue(Queue* queue, int row, int col) {
    if (isQueueFull(queue)) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->positions[queue->rear].row = row;
    queue->positions[queue->rear].col = col;
}

Position dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        exit(1);
    }
    Position position = queue->positions[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return position;
}

// Define the BFS algorithm to traverse the maze
void bfs() {
    Queue queue;
    initQueue(&queue);
    
    // Add the starting point to the queue
    enqueue(&queue, startRow, startCol);
    
    // Initialize the visited array
    bool visited[ROWS][COLS] = {false};
    visited[startRow][startCol] = true;
    
    // Initialize the parent array
    Position parent[ROWS][COLS] = {{0}};
    
    // Traverse the maze using BFS
    while(!isQueueEmpty(&queue)) {
        Position currentPosition = dequeue(&queue);
        int row = currentPosition.row;
        int col = currentPosition.col;

        // Check if we have reached the end of the maze
        if (row == endRow && col == endCol) {
            break;
        }
        
        // Traverse the neighbors of the current position
        if (row < ROWS - 1 && !visited[row+1][col] && maze[row+1][col] != '#') {
            visited[row+1][col] = true;
            parent[row+1][col] = currentPosition;
            enqueue(&queue, row+1, col);
        }
        if (row > 0 && !visited[row-1][col] && maze[row-1][col] != '#') {
            visited[row-1][col] = true;
            parent[row-1][col] = currentPosition;
            enqueue(&queue, row-1, col);
        }
        if (col < COLS - 1 && !visited[row][col+1] && maze[row][col+1] != '#') {
            visited[row][col+1] = true;
            parent[row][col+1] = currentPosition;
            enqueue(&queue, row, col+1);
        }
        if (col > 0 && !visited[row][col-1] && maze[row][col-1] != '#') {
            visited[row][col-1] = true;
            parent[row][col-1] = currentPosition;
            enqueue(&queue, row, col-1);
        }
    }
    
    // Print the path from start to end
    if (!visited[endRow][endCol]) {
        printf("No path found\n");
    } else {
        Position currentPosition = {endRow, endCol};
        printf("Path:\n");
        while(!(currentPosition.row == startRow && currentPosition.col == startCol)) {
            printf("Row: %d Col: %d\n", currentPosition.row, currentPosition.col);
            currentPosition = parent[currentPosition.row][currentPosition.col];
        }
        printf("Row: %d Col: %d\n", startRow, startCol);
    }
}

int main() {
    bfs();
    return 0;
}