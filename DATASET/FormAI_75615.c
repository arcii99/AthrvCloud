//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

// Structure to hold the coordinates of the cell in the maze
struct cell {
    int x, y;
};

// Function to find the path to the exit of the maze
void mazePathFinder(int** maze, int n, int m, struct cell start, struct cell end) {
    // Create visited array to keep track of visited cells
    int** visited = (int**) malloc(sizeof(int*) * n);
    for(int i=0; i<n; i++) {
        visited[i] = (int*) malloc(sizeof(int) * m);
        for(int j=0; j<m; j++)
            visited[i][j] = 0;
    }

    // Create queue to store the path to the exit of the maze
    struct cell* queue = (struct cell*) malloc(sizeof(struct cell) * n * m);
    int front = 0, rear = -1;

    // Start with the starting cell
    queue[++rear] = start;
    visited[start.x][start.y] = 1;

    // Find the path to the exit of the maze using BFS
    while(rear >= front) {
        struct cell curr = queue[front++];
        // If we reach the end, print the path and return
        if(curr.x == end.x && curr.y == end.y) {
            printf("Path Found!\n");
            printf("Path: (%d, %d)\n", end.x, end.y);
            while(curr.x != start.x || curr.y != start.y) {
                printf("        (%d, %d)\n", curr.x, curr.y);
                curr = queue[curr.x * m + curr.y];
            }
            printf("        (%d, %d)\n", start.x, start.y);
            return;
        }

        // Add adjacent cells to queue if not visited and not a wall
        if(curr.x > 0 && !visited[curr.x-1][curr.y] && maze[curr.x-1][curr.y] != 1) {
            queue[++rear].x = curr.x-1;
            queue[rear].y = curr.y;
            visited[curr.x-1][curr.y] = 1;
        }
        if(curr.y > 0 && !visited[curr.x][curr.y-1] && maze[curr.x][curr.y-1] != 1) {
            queue[++rear].x = curr.x;
            queue[rear].y = curr.y-1;
            visited[curr.x][curr.y-1] = 1;
        }
        if(curr.x < n-1 && !visited[curr.x+1][curr.y] && maze[curr.x+1][curr.y] != 1) {
            queue[++rear].x = curr.x+1;
            queue[rear].y = curr.y;
            visited[curr.x+1][curr.y] = 1;
        }
        if(curr.y < m-1 && !visited[curr.x][curr.y+1] && maze[curr.x][curr.y+1] != 1) {
            queue[++rear].x = curr.x;
            queue[rear].y = curr.y+1;
            visited[curr.x][curr.y+1] = 1;
        }
    }

    // If we reach here, there is no path to the exit of the maze
    printf("No Path Found!\n");
}

int main() {
    // Maze with 1s representing walls and 0s representing paths
    int maze[5][5] = { { 0, 1, 0, 0, 1 },
                       { 0, 1, 0, 1, 0 },
                       { 0, 0, 0, 1, 0 },
                       { 0, 1, 0, 1, 0 },
                       { 0, 1, 0, 0, 0 } };
    
    // Start and end coordinates
    struct cell start = {0, 0};
    struct cell end = {4, 4};

    // Find the path to the exit of the maze
    mazePathFinder((int**)maze, 5, 5, start, end);

    return 0;
}