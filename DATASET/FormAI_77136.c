//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define maze dimensions
#define DIM 10

// Define the maze
int maze[DIM][DIM] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
};

// Define the path
int path[DIM][DIM];

// Define the start and end points
int start_row = 1;
int start_col = 1;
int end_row = 8;
int end_col = 8;

// Define the queue for BFS
struct QueueNode {
    int row;
    int col;
    struct QueueNode* next;
};

struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;
int queue_size = 0;

/**
 * Enqueue a node to the back of the queue
 */
void enqueue(int row, int col) {
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    queue_size++;
}

/**
 * Dequeue a node from the front of the queue
 */
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct QueueNode* temp = front;

    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
    queue_size--;
}

/**
 * Check if the queue is empty
 */
int is_empty() {
    if (front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Print the path
 */
void print_path() {
    for (int row = 0; row < DIM; row++) {
        for (int col = 0; col < DIM; col++) {
            printf("%d ", path[row][col]);
        }
        printf("\n");
    }
}

/**
 * Breadth-first search algorithm to find the shortest path
 */
void bfs() {
    enqueue(start_row, start_col);
    path[start_row][start_col] = 1;

    while (!is_empty()) {
        int row = front->row;
        int col = front->col;
        dequeue();

        // Check if we have reached the end
        if (row == end_row && col == end_col) {
            return;
        }

        // Check if we can move up
        if (maze[row - 1][col] == 0 && path[row - 1][col] == 0) {
            enqueue(row - 1, col);
            path[row - 1][col] = path[row][col] + 1;
        }

        // Check if we can move down
        if (maze[row + 1][col] == 0 && path[row + 1][col] == 0) {
            enqueue(row + 1, col);
            path[row + 1][col] = path[row][col] + 1;
        }

        // Check if we can move left
        if (maze[row][col - 1] == 0 && path[row][col - 1] == 0) {
            enqueue(row, col - 1);
            path[row][col - 1] = path[row][col] + 1;
        }

        // Check if we can move right
        if (maze[row][col + 1] == 0 && path[row][col + 1] == 0) {
            enqueue(row, col + 1);
            path[row][col + 1] = path[row][col] + 1;
        }
    }
}

int main() {
    // Initialize path to 0
    for (int row = 0; row < DIM; row++) {
        for (int col = 0; col < DIM; col++) {
            path[row][col] = 0;
        }
    }

    bfs();

    // Print the shortest path
    printf("Shortest path from (%d, %d) to (%d, %d) is:\n", start_row, start_col, end_row, end_col);
    print_path();

    return 0;
}