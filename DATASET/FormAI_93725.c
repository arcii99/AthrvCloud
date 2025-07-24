//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 10
#define COLS 10

// Structure to represent a node in the graph
struct Node {
    int row, col;   // Coordinates of the node
};

// Function to check whether a given node is valid or not
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Function to check whether a given node is a wall or not
bool isWall(int mat[][COLS], int row, int col) {
    return (mat[row][col] == INT_MAX);
}

// Function to calculate the Manhattan distance between two nodes
int manhattanDistance(struct Node a, struct Node b) {
    return abs(a.row - b.row) + abs(a.col - b.col);
}

// Function to find the shortest path between two nodes using A* algorithm
void findShortestPath(int mat[][COLS], struct Node start, struct Node end) {
    // Create two arrays to store the g-score and f-score of each node
    int gScore[ROWS][COLS], fScore[ROWS][COLS];

    // Initialize all scores to infinity
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gScore[i][j] = INT_MAX;
            fScore[i][j] = INT_MAX;
        }
    }

    // Set the score of the start node to 0
    gScore[start.row][start.col] = 0;
    fScore[start.row][start.col] = manhattanDistance(start, end);

    // Create a boolean array to keep track of visited nodes
    bool visited[ROWS][COLS] = {false};

    // Create a priority queue of nodes to be processed
    struct Node queue[ROWS * COLS];
    int front = 0, rear = 0;
    queue[rear++] = start;

    // Loop until the queue is empty
    while (front != rear) {
        // Get the node with the lowest f-score
        int minIndex = front;
        for (int i = front + 1; i < rear; i++) {
            if (fScore[queue[i].row][queue[i].col] < fScore[queue[minIndex].row][queue[minIndex].col]) {
                minIndex = i;
            }
        }
        struct Node current = queue[minIndex];

        // Check if we have reached the end node
        if (current.row == end.row && current.col == end.col) {
            printf("Shortest path exists with distance: %d\n", gScore[current.row][current.col]);
            return;
        }

        // Remove the current node from the queue
        queue[minIndex] = queue[front++];
        visited[current.row][current.col] = true;

        // Check the neighbors of the current node
        struct Node neighbors[4] = { {current.row-1, current.col}, {current.row, current.col-1},
                                     {current.row+1, current.col}, {current.row, current.col+1} };
        for (int i = 0; i < 4; i++) {
            if (isValid(neighbors[i].row, neighbors[i].col) && !isWall(mat, neighbors[i].row, neighbors[i].col)) {
                int tentativeGScore = gScore[current.row][current.col] + 1;
                if (tentativeGScore < gScore[neighbors[i].row][neighbors[i].col]) {
                    gScore[neighbors[i].row][neighbors[i].col] = tentativeGScore;
                    fScore[neighbors[i].row][neighbors[i].col] = tentativeGScore + manhattanDistance(neighbors[i], end);
                    if (!visited[neighbors[i].row][neighbors[i].col]) {
                        queue[rear++] = neighbors[i];
                    }
                }
            }
        }
    }

    printf("Shortest path does not exist.\n");
}

int main() {
    int mat[ROWS][COLS] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, 0, 0},
                            {0, 0, INT_MAX, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
                            {0, 0, INT_MAX, 0, 0, 0, 0, 0, INT_MAX, 0},
                            {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, INT_MAX, 0},
                            {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
                            {0, 0, 0, INT_MAX, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0} };
    struct Node start = {0, 0};
    struct Node end = {9, 9};
    findShortestPath(mat, start, end);
    return 0;
}