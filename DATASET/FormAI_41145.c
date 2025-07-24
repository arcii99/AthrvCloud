//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the maximum row and column size
#define ROW_SIZE 5
#define COL_SIZE 5

// Define a struct for each cell in the grid
struct Node {
    int row;
    int col;
    int distance;
};

// Define a 2D grid to be used as the map
int map[ROW_SIZE][COL_SIZE] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// Define a function for printing the grid
void printMap() {
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            if (map[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Define a function for finding the shortest path from start to end
void shortestPath(struct Node start, struct Node end) {
    // Define an array of visited nodes and initialize all to zero
    int visited[ROW_SIZE][COL_SIZE];
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            visited[i][j] = 0;
        }
    }

    // Define an array of nodes to be evaluated and add the start node
    struct Node queue[ROW_SIZE*COL_SIZE];
    int head = 0;
    int tail = 0;
    queue[tail] = start;
    tail++;

    // Mark start node as visited
    visited[start.row][start.col] = 1;

    // Define an array of possible moves
    int moves[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };

    // Loop until all nodes are evaluated or the end node is found
    while (head < tail) {
        // Get the current node and remove it from the queue
        struct Node current = queue[head];
        head++;

        // Check if the current node is the end node
        if (current.row == end.row && current.col == end.col) {
            printf("\nShortest path found!\n");
            printf("Distance: %d\n", current.distance);
            return;
        }

        // Evaluate all possible moves
        for (int i = 0; i < 4; i++) {
            // Calculate the new position
            int new_row = current.row + moves[i][0];
            int new_col = current.col + moves[i][1];

            // Check if the new position is within the map boundaries and not an obstacle
            if (new_row >= 0 && new_col >= 0 && new_row < ROW_SIZE && new_col < COL_SIZE && map[new_row][new_col] == 0 && visited[new_row][new_col] == 0) {
                // Add the new node to the queue
                struct Node new_node = { new_row, new_col, current.distance + 1 };
                queue[tail] = new_node;
                tail++;

                // Mark the new node as visited
                visited[new_row][new_col] = 1;
            }
        }
    }

    // If the end node was not found, print a message
    printf("\nNo path found!\n");
}

int main() {
    struct Node start = { 0, 0, 0 };
    struct Node end = { 4, 4, 0 };

    printf("Welcome to the pathfinding algorithm!\n");

    printf("\nThe map:\n");
    printMap();

    shortestPath(start, end);

    return 0;
}