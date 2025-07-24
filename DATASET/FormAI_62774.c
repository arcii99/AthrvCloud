//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: rigorous
#include <stdio.h>
#define ROW 5
#define COL 5
#define INF 1000000

// Function to check if the given cell (row, col) is a valid cell or not.
int isValidCell(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to find the shortest path between a given source cell and a destination cell.
int AStarPathFinding(int graph[][COL], int srcRow, int srcCol, int destRow, int destCol)
{
    // check if source and destination cells are valid.
    if (!isValidCell(srcRow, srcCol) || !isValidCell(destRow, destCol)) {
        printf("Invalid source or destination cell\n");
        return 0;
    }

    // check if source and destination cells are not blocked
    if (graph[srcRow][srcCol] == INF || graph[destRow][destCol] == INF) {
        printf("Source or destination cell is blocked\n");
        return 0;
    }

    // If the source is equal to destination
    if (srcRow == destRow && srcCol == destCol) {
        printf("Source and destination cells are same\n");
        return 0;
    }

    // directions array to move in 8 possible directions
    int rowDirection[] = {-1, 0, 0, 1, -1, -1, 1, 1};
    int colDirection[] = {0, -1, 1, 0, -1, 1, -1, 1};

    // Mark the visited cells and the distance of the source cell from itself as 0.
    int visited[ROW][COL], distance[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = 0;
            distance[i][j] = INF;
        }
    }
    visited[srcRow][srcCol] = 1;            // Mark the source cell as visited.
    distance[srcRow][srcCol] = 0;           // Distance of the source cell from itself is 0.

    // Create an empty queue and add the source cell to it.
    struct Queue {
        int row;
        int col;
        int f_score;
    };
    struct Queue queue[ROW * COL];
    int front = -1, rear = -1;
    queue[++rear] = (struct Queue) {srcRow, srcCol, 0};

    // Loop until the queue becomes empty.
    while (front != rear) {
        // Remove the cell with the smallest f_score value from the queue.
        int currRow = queue[++front].row;
        int currCol = queue[front].col;

        // Check if the destination cell has been reached.
        if (currRow == destRow && currCol == destCol) {
            return distance[currRow][currCol];
        }

        // Loop through all the neighbouring cells.
        for (i = 0; i < 8; i++) {
            int newRow = currRow + rowDirection[i];
            int newCol = currCol + colDirection[i];

            // If this neighbouring cell is a valid cell
            if (isValidCell(newRow, newCol)) {
                // If this neighbouring cell is not blocked and has not been visited before
                if (graph[newRow][newCol] != INF && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1; // Mark this cell as visited.
                    distance[newRow][newCol] = distance[currRow][currCol] + 1; // Update the distance of this cell from the source cell.
                    int h_score = abs(newRow - destRow) + abs(newCol - destCol); // Calculate the heuristic score.
                    queue[++rear] = (struct Queue) {newRow, newCol, distance[newRow][newCol] + h_score}; // Add this neighbouring cell to the queue with its f_score value.
                }
            }
        }
    }

    printf("Destination cell not reachable\n");
    return 0; // Destination cell not reachable.
}

int main()
{
    int graph[ROW][COL] =
    {
        {1, 1, 1, 1, 1},
        {0, INF, 0, INF, 0},
        {0, 1, 1, 1, 0},
        {INF, 1, INF, 1, INF},
        {0, 1, 1, 1, 0}
    };

    int shortestPath = AStarPathFinding(graph, 0, 0, 4, 4); // Find the shortest path between source (0,0) and destination (4,4).

    if (shortestPath) {
        printf("Shortest path between source and destination is %d", shortestPath); // Print the shortest path.
    }

    return 0;
}