//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ROW 10      // Define the number of rows in the grid
#define COL 10      // Define the number of columns in the grid

int main()
{
    int grid[ROW][COL] = {   // Define the grid as a 2D array
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int startROW = 1;   // Define the rows and columns of the starting point
    int startCOL = 1;

    int endROW = 8;     // Define the rows and columns of the end point
    int endCOL = 8;

    int visited[ROW][COL];  // Define a 2D array to keep track of the visited points

    for (int i = 0; i < ROW; i++) {  // Initialize the visited array to all zeros
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }

    int queue[ROW * COL][2];    // Define a queue to hold the points to visit
    int front = 0;
    int rear = 0;

    queue[rear][0] = startROW;  // Enqueue the starting point
    queue[rear][1] = startCOL;
    rear++;

    visited[startROW][startCOL] = 1;   // Mark the starting point as visited

    int parent[ROW][COL][2];    // Define a 3D array to keep track of the parent of each point

    while (front < rear) {  // Perform BFS until the queue is empty
        int currROW = queue[front][0];  // Dequeue the first point
        int currCOL = queue[front][1];
        front++;

        if (currROW == endROW && currCOL == endCOL) {   // Exit if the end point is found
            break;
        }

        // Check the neighbors of the current point
        if (grid[currROW-1][currCOL] == 0 && visited[currROW-1][currCOL] == 0) {  // Check north neighbor
            queue[rear][0] = currROW-1;
            queue[rear][1] = currCOL;
            rear++;

            visited[currROW-1][currCOL] = 1;
            parent[currROW-1][currCOL][0] = currROW;
            parent[currROW-1][currCOL][1] = currCOL;
        }

        if (grid[currROW+1][currCOL] == 0 && visited[currROW+1][currCOL] == 0) {  // Check south neighbor
            queue[rear][0] = currROW+1;
            queue[rear][1] = currCOL;
            rear++;

            visited[currROW+1][currCOL] = 1;
            parent[currROW+1][currCOL][0] = currROW;
            parent[currROW+1][currCOL][1] = currCOL;
        }

        if (grid[currROW][currCOL-1] == 0 && visited[currROW][currCOL-1] == 0) {  // Check west neighbor
            queue[rear][0] = currROW;
            queue[rear][1] = currCOL-1;
            rear++;

            visited[currROW][currCOL-1] = 1;
            parent[currROW][currCOL-1][0] = currROW;
            parent[currROW][currCOL-1][1] = currCOL;
        }

        if (grid[currROW][currCOL+1] == 0 && visited[currROW][currCOL+1] == 0) {  // Check east neighbor
            queue[rear][0] = currROW;
            queue[rear][1] = currCOL+1;
            rear++;

            visited[currROW][currCOL+1] = 1;
            parent[currROW][currCOL+1][0] = currROW;
            parent[currROW][currCOL+1][1] = currCOL;
        }
    }

    int path[ROW*COL][2];   // Define an array to hold the path

    int pathIndex = 0;
    int currROW = endROW;
    int currCOL = endCOL;

    // Trace back the path using the parent array
    while (currROW != startROW || currCOL != startCOL) {
        path[pathIndex][0] = currROW;
        path[pathIndex][1] = currCOL;
        pathIndex++;

        int tempROW = currROW;
        currROW = parent[tempROW][currCOL][0];
        currCOL = parent[tempROW][currCOL][1];
    }

    path[pathIndex][0] = startROW;  // Add the starting point to the path
    path[pathIndex][1] = startCOL;

    // Print the path in reverse order, starting from the end
    printf("The path from (%d,%d) to (%d,%d) is:\n", startROW, startCOL, endROW, endCOL);
    for (int i = pathIndex; i >= 0; i--) {
        printf("(%d,%d) ", path[i][0], path[i][1]);
    }
    printf("\n");

    return 0;
}