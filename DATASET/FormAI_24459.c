//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

#define ROW 5 // Number of rows in the map
#define COL 5 // Number of columns in the map

// Map of the environment 
int map[ROW][COL] = {
    {1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
};

// Structure to store the coordinate of each location in the map
typedef struct {
    int row;    // Row number
    int col;    // Column number
} Location;

// Queue to store the location to be explored in BFS
typedef struct {
    Location queue[ROW*COL];
    int front, rear;
} Queue;

// Function to check if the coordinate (row, col) is a valid location in the map
bool is_valid(int row, int col) {
    return (row >= 0 && row < ROW) && (col >= 0 && col < COL);
}

// Function to check if the coordinate (row, col) is free to pass through
bool is_free(int row, int col) {
    return map[row][col] == 1;
}

// Function to check if the coordinate (row, col) is the destination
bool is_destination(int row, int col, Location dest) {
    return row == dest.row && col == dest.col;
}

// Function to get the shortest path from source to destination using BFS algorithm
void BFS(Location src, Location dest) {

    // Check if source and destination coordinates are valid
    if (!is_valid(src.row, src.col)) {
        printf("Invalid source location.\n");
        return;
    }

    if (!is_valid(dest.row, dest.col)) {
        printf("Invalid destination location.\n");
        return;
    }

    // Check if source and destination coordinates are free to pass through
    if (!is_free(src.row, src.col)) {
        printf("Blocked source location.\n");
        return;
    }

    if (!is_free(dest.row, dest.col)) {
        printf("Blocked destination location.\n");
        return;
    }

    // Create a visited array to store visited status of each location in the map
    bool visited[ROW][COL] = {false};

    // Initialize the queue and enqueue the source location
    Queue q = {{0}, -1, -1};
    q.front = q.rear = 0;
    q.queue[q.rear] = src;
    visited[src.row][src.col] = true;

    while (q.front <= q.rear) {
        // Dequeue the front location from queue and mark it as visited
        Location curr_loc = q.queue[q.front++];
        
        // Check if the current location is the destination
        if (is_destination(curr_loc.row, curr_loc.col, dest)) {
            printf("Destination reached!\n");
            return;
        }
        
        // Explore all the valid neighbors of the current location
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Skip the current location and diagonally adjacent locations
                if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                    continue;
                }
                
                int neigh_row = curr_loc.row + i;
                int neigh_col = curr_loc.col + j;
                
                // Check if the neighbor is a valid location and free to pass through
                if (is_valid(neigh_row, neigh_col) && is_free(neigh_row, neigh_col)) {
                    // Mark the neighbor as visited and enqueue it in the queue
                    if (!visited[neigh_row][neigh_col]) {
                        visited[neigh_row][neigh_col] = true;
                        Location neigh_loc = {neigh_row, neigh_col};
                        q.queue[++q.rear] = neigh_loc;
                    }
                }
            }
        }
    }

    printf("Destination not reachable.\n");
}

// Driver program
int main() {
    Location src = {0, 0};
    Location dest = {4, 4};

    printf("Source: (%d, %d)\n", src.row, src.col);
    printf("Destination: (%d, %d)\n", dest.row, dest.col);

    BFS(src, dest);

    return 0;
}