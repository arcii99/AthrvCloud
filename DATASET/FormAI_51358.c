//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 8

// A function to print the path taken by the algorithm
void print_path(int path[ROW][COL], int start_x, int start_y, int end_x, int end_y) {
    int x = end_x;
    int y = end_y;
    while (x != start_x || y != start_y) {
        printf("(%d,%d) -> ", x, y);
        int prev_x = path[x][y] / COL; // Previous node's x co-ordinate
        y = path[x][y] % COL; // Previous node's y co-ordinate
        x = prev_x;
    }
    printf("(%d,%d)\n", start_x, start_y);
}

// A function to check whether a given point is inside the matrix or not
bool is_inside(int x, int y) {
    return (x >= 0 && x < ROW) && (y >= 0 && y < COL);
}

// A function to check whether a given point is a valid point to move or not
bool is_valid(int matrix[ROW][COL], int visited[ROW][COL], int x, int y) {
    return is_inside(x, y) && matrix[x][y] == 1 && visited[x][y] == 0;
}

// A function to perform Breadth-First Search algorithm and find the shortest path
void bfs(int matrix[ROW][COL], int start_x, int start_y, int end_x, int end_y) {
    // Create a 2D array to keep track of visited nodes
    int visited[ROW][COL] = {0};

    // Create a 2D array to keep track of parent nodes (to find the path later)
    int path[ROW][COL] = {0};

    // Create a queue for BFS algorithm
    int queue[ROW*COL][2];
    int front = 0;
    int rear = 0;

    // Add the starting node to the queue
    queue[rear][0] = start_x;
    queue[rear][1] = start_y;
    rear++;

    // Mark the starting node as visited
    visited[start_x][start_y] = 1;

    // Perform BFS algorithm
    while (front != rear) {
        // Dequeue the front node and process it
        int current_x = queue[front][0];
        int current_y = queue[front][1];
        front++;

        // If the end node is found, print the path and return
        if (current_x == end_x && current_y == end_y) {
            print_path(path, start_x, start_y, end_x, end_y);
            return;
        }

        // Try moving to the up node
        if (is_valid(matrix, visited, current_x-1, current_y)) {
            queue[rear][0] = current_x-1;
            queue[rear][1] = current_y;
            rear++;
            visited[current_x-1][current_y] = 1;
            path[current_x-1][current_y] = current_x*COL + current_y; // Mark parent
        }

        // Try moving to the down node
        if (is_valid(matrix, visited, current_x+1, current_y)) {
            queue[rear][0] = current_x+1;
            queue[rear][1] = current_y;
            rear++;
            visited[current_x+1][current_y] = 1;
            path[current_x+1][current_y] = current_x*COL + current_y; // Mark parent
        }

        // Try moving to the left node
        if (is_valid(matrix, visited, current_x, current_y-1)) {
            queue[rear][0] = current_x;
            queue[rear][1] = current_y-1;
            rear++;
            visited[current_x][current_y-1] = 1;
            path[current_x][current_y-1] = current_x*COL + current_y; // Mark parent
        }

        // Try moving to the right node
        if (is_valid(matrix, visited, current_x, current_y+1)) {
            queue[rear][0] = current_x;
            queue[rear][1] = current_y+1;
            rear++;
            visited[current_x][current_y+1] = 1;
            path[current_x][current_y+1] = current_x*COL + current_y; // Mark parent
        }
    }
}

int main() {
    // Create a matrix representing the graph
    int matrix[ROW][COL] = {
        {1, 0, 0, 1, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 1},
        {0, 0 ,0, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 0}
    };

    // Starting and ending points
    int start_x = 4;
    int start_y = 7;
    int end_x = 1;
    int end_y = 3;

    printf("The shortest path from (%d,%d) to (%d,%d) is:\n", start_x, start_y, end_x, end_y);
    bfs(matrix, start_x, start_y, end_x, end_y);

    return 0;
}