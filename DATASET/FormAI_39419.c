//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// struct to represent the node
struct Node {
    int row, col;
};

// function to check if the node is inside the maze
bool isValidCell(int maze[][COL], int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0;
}

// function to check if the given node is a destination
bool isDestination(int row, int col, struct Node dest) {
    return row == dest.row && col == dest.col;
}

// function to find the path using BFS algorithm
void findPath(int maze[][COL], struct Node start, struct Node dest) {
    // array to store the visited nodes
    bool visited[ROW][COL] = {{false}};

    // create a queue for BFS
    struct Node queue[ROW * COL];

    // initialize the queue with start node
    queue[0] = start;

    // mark the start node as visited
    visited[start.row][start.col] = true;

    // initialize the front and rear of the queue
    int front = 0, rear = 1;

    // array to store the path
    struct Node parents[ROW][COL] = {{-1, -1}};

    // loop until the queue is empty or destination node is found
    while (front < rear) {
        // remove the first node from queue
        struct Node current = queue[front++];
        
        // check if the current node is the destination
        if (isDestination(current.row, current.col, dest)) {
            break;
        }
        
        // check for all the adjacent nodes of the current node
        int nextRow, nextCol;
        nextRow = current.row + 1; nextCol = current.col;
        if (isValidCell(maze, nextRow, nextCol) && !visited[nextRow][nextCol]) {
            visited[nextRow][nextCol] = true;
            queue[rear++] = (struct Node) {nextRow, nextCol};
            parents[nextRow][nextCol] = current;
        }
        nextRow = current.row - 1; nextCol = current.col;
        if (isValidCell(maze, nextRow, nextCol) && !visited[nextRow][nextCol]) {
            visited[nextRow][nextCol] = true;
            queue[rear++] = (struct Node) {nextRow, nextCol};
            parents[nextRow][nextCol] = current;
        }
        nextRow = current.row; nextCol = current.col + 1;
        if (isValidCell(maze, nextRow, nextCol) && !visited[nextRow][nextCol]) {
            visited[nextRow][nextCol] = true;
            queue[rear++] = (struct Node) {nextRow, nextCol};
            parents[nextRow][nextCol] = current;
        }
        nextRow = current.row; nextCol = current.col - 1;
        if (isValidCell(maze, nextRow, nextCol) && !visited[nextRow][nextCol]) {
            visited[nextRow][nextCol] = true;
            queue[rear++] = (struct Node) {nextRow, nextCol};
            parents[nextRow][nextCol] = current;
        }
    }

    // check if the destination node is reached
    if (parents[dest.row][dest.col].row == -1 && parents[dest.row][dest.col].col == -1) {
        printf("No path found.\n");
    } else {
        // print the path from start to destination
        int steps = 0;
        struct Node path[ROW * COL] = {{-1, -1}};
        struct Node current = dest;
        while (!(current.row == start.row && current.col == start.col)) {
            path[steps++] = current;
            current = parents[current.row][current.col];
        }
        path[steps++] = start;
        printf("Path found with %d steps:\n", steps);
        for (int i = steps - 1; i >= 0; i--) {
            printf("- (%d, %d)\n", path[i].row, path[i].col);
        }
    }
}

int main() {
    // the maze matrix representing the obstacles
    int maze[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 1, 1, 0},
    };

    // initialize the start and destination nodes
    struct Node start = {0, 0};
    struct Node dest = {ROW - 1, COL - 1};

    // find the path using BFS algorithm
    findPath(maze, start, dest);

    return 0;
}