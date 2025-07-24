//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

struct Node {
    int x, y;
    int distance_traveled;
};

typedef struct Node Node;

// The following function checks if a point is valid or not.
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// The following function checks if point (row, col) is unblocked or not
int isUnblocked(int grid[][COL], int row, int col) {
    return grid[row][col] == 1;
}

// The following function checks if the current node is a destination or not
int isDestination(int row, int col, Node dest) {
    return row == dest.x && col == dest.y;
}

// The following function calculates the Manhattan distance
int calculateManhattanDistance(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

// The following function returns the shortest path from start to destination
int shortestPath(int grid[][COL], Node start, Node dest) {
    // If the start node and destination node are the same node
    if (isDestination(start.x, start.y, dest)) {
        return 0;
    }

    // Two-dimensional grid to represent visited nodes
    int visited[ROW][COL] = {0};

    // Creating a queue for BFS traversal
    Node queue[ROW * COL];

    int front = 0;
    int rear = 0;

    // Enqueue the starting node
    queue[rear++] = start;
    visited[start.x][start.y] = 1;

    // Loops until we find the destination node or all the nodes in the queue are traversed
    while (front < rear) {
        // Pop the front node from the queue
        Node current = queue[front++];
        int row = current.x, col = current.y, distance_traveled = current.distance_traveled;

        // travel in all 4 directions from the current node
        if (isValid(row - 1, col) && 
            isUnblocked(grid, row - 1, col) && 
            !visited[row - 1][col]) {
            Node adjacent = { row - 1, col, distance_traveled + 1 }; // distance traveled incremented by 1 since this is a neighbor node
            if (isDestination(adjacent.x, adjacent.y, dest)) {
                return adjacent.distance_traveled;
            }
            visited[adjacent.x][adjacent.y] = 1;
            queue[rear++] = adjacent;
        }

        if (isValid(row + 1, col) && 
            isUnblocked(grid, row + 1, col) && 
            !visited[row + 1][col]) {
            Node adjacent = { row + 1, col, distance_traveled + 1 };
            if (isDestination(adjacent.x, adjacent.y, dest)) {
                return adjacent.distance_traveled;
            }
            visited[adjacent.x][adjacent.y] = 1;
            queue[rear++] = adjacent;
        }

        if (isValid(row, col - 1) && 
            isUnblocked(grid, row, col - 1) && 
            !visited[row][col - 1]) {
            Node adjacent = { row, col - 1, distance_traveled + 1 };
            if (isDestination(adjacent.x, adjacent.y, dest)) {
                return adjacent.distance_traveled;
            }
            visited[adjacent.x][adjacent.y] = 1;
            queue[rear++] = adjacent;
        }

        if (isValid(row, col + 1) && 
            isUnblocked(grid, row, col + 1) && 
            !visited[row][col + 1]) {
            Node adjacent = { row, col + 1, distance_traveled + 1 };
            if (isDestination(adjacent.x, adjacent.y, dest)) {
                return adjacent.distance_traveled;
            }
            visited[adjacent.x][adjacent.y] = 1;
            queue[rear++] = adjacent;
        }
    }

    // If the destination node is not found
    return -1;
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 0, 1}
    };

    Node start = {0, 0, 0};
    Node dest = {ROW - 1, COL - 1, 0};
    int dist = shortestPath(grid, start, dest);

    printf("Shortest path from source to destination is %d\n", dist);

    return 0;
}