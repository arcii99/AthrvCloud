//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define N 8

// Heuristic Function to determine the best path
int heuristic(int x, int y, int xDest, int yDest) {
    return abs(x - xDest) + abs(y - yDest);
}

// Function to find the shortest path through A* algorithm
void AStar(char grid[][N], int start[], int dest[]) {
    int closedList[N][N];
    int openList[N][N];
    int parent[N][N]; // Parent of each node in the path
    
    int x, y, newX, newY, g, f, h, smallestF;
    
    // Initialize the lists
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            closedList[x][y] = 0;
            openList[x][y] = 0;
            parent[x][y] = -1;
        }
    }
    
    // Add the start point to the open list and set its g and f values to 0
    openList[start[0]][start[1]] = 1;
    g = 0;
    f = g + heuristic(start[0], start[1], dest[0], dest[1]);
    smallestF = f;
    
    // Explore the open list
    while (smallestF < INT_MAX) {
        // Find the node with the smallest f value
        for (y = 0; y < N; y++) {
            for (x = 0; x < N; x++) {
                if (openList[x][y]) {
                    if (grid[x][y] == '#') {
                        closedList[x][y] = 1;
                        openList[x][y] = 0;
                        smallestF = INT_MAX;
                    } else {
                        f = g + heuristic(x, y, dest[0], dest[1]);
                        if (f <= smallestF) {
                            smallestF = f;
                            newX = x;
                            newY = y;
                        }
                    }
                }
            }
        }
        
        // If the destination is reached, exit
        if (newX == dest[0] && newY == dest[1]) {
            break;
        }
        
        // Move the current node from the open list to the closed list
        openList[newX][newY] = 0;
        closedList[newX][newY] = 1;
        
        // Explore the neighboring nodes
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                x = newX + i;
                y = newY + j;
                if (x >= 0 && x < N && y >= 0 && y < N && !closedList[x][y] && grid[x][y] != '#') {
                    g = 1 + heuristic(newX, newY, x, y);
                    f = g + heuristic(x, y, dest[0], dest[1]);
                    if (!openList[x][y]) {
                        openList[x][y] = 1;
                        parent[x][y] = newX * N + newY;
                    } else if (g >= (1 + heuristic(parent[x][y]/N, parent[x][y]%N, x, y))) {
                        continue;
                    }
                    smallestF = f;
                }
            }
        }
    }
    
    // If the destination is reached, find the path and print it
    if (smallestF != INT_MAX) {
        int path[N*N][2];
        int pathLength = 0;
        int node = dest[0] * N + dest[1];
        while (node != -1) {
            path[pathLength][0] = node/N;
            path[pathLength][1] = node%N;
            pathLength++;
            node = parent[path[pathLength-1][0]][path[pathLength-1][1]];
        }
        printf("\nShortest Path:\n");
        for (int i = pathLength - 1; i >= 0; i--) {
            printf("(%d,%d)\n", path[i][0], path[i][1]);
        }
    } else {
        printf("\nNo Path Found.\n");
    }
}

// Main function to test the A* algorithm
int main() {
    char grid[N][N] = {
        { '.', '.', '.', '.', '.', '.', '.', '.' },
        { '#', '.', '#', '#', '.', '#', '.', '#' },
        { '.', '.', '.', '#', '.', '.', '.', '.' },
        { '.', '#', '.', '#', '.', '.', '#', '.' },
        { '.', '.', '.', '.', '#', '.', '.', '.' },
        { '.', '#', '#', '.', '.', '#', '#', '.' },
        { '.', '#', '.', '.', '.', '.', '#', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.' }
    };
    int start[2] = { 0, 0 };
    int dest[2] = { 7, 7 };
    AStar(grid, start, dest);
    return 0;
}