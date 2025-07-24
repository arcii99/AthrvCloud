//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a point in 2D plane
typedef struct {
    int x, y;
} Point;

// Function to calculate the distance between two points
int distance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Function to print the path from start to end
void printPath(Point path[], int n) {
    printf("Path: ");
    for (int i = 0; i < n; i++) {
        printf("(%d,%d)", path[i].x, path[i].y);
        if (i != n-1) printf(" -> ");
    }
    printf("\n");
}

// Function to perform depth first search to find the path
bool dfs(Point maze[][5], bool visited[][5], Point start, Point end, Point path[], int n) {
    // Mark current point as visited
    visited[start.x][start.y] = true;
    
    // Add current point to path
    path[n++] = start;
    
    // Check if we have reached the end point
    if (start.x == end.x && start.y == end.y) {
        printPath(path, n);
        return true;
    }
    
    // Explore all neighbouring points
    int minDistance = -1;
    Point nearestPoint;
    for (int i = start.x-1; i <= start.x+1; i++) {
        for (int j = start.y-1; j <= start.y+1; j++) {
            if (i >= 0 && j >= 0 && i < 5 && j < 5 && !visited[i][j] && maze[i][j].x != -1) {
                int d = distance(maze[i][j], end);
                if (minDistance == -1 || d < minDistance) {
                    minDistance = d;
                    nearestPoint = maze[i][j];
                }
            }
        }
    }
    
    // Check if there is a valid neighbouring point
    if (minDistance != -1) {
        return dfs(maze, visited, nearestPoint, end, path, n);
    }
    else {
        return false;
    }
}

int main() {
    // Create a maze
    Point maze[5][5] = {
        {{0,0}, {0,1}, {0,2}, {-1,-1}, {0,3}},
        {{1,0}, {-1,-1}, {1,2}, {1,3}, {1,4}},
        {{2,0}, {-1,-1}, {2,2}, {2,3}, {2,4}},
        {{3,0}, {3,1}, {3,2}, {-1,-1}, {3,3}},
        {{4,0}, {4,1}, {4,2}, {4,3}, {4,4}}
    };
    
    // Initialize visited array
    bool visited[5][5] = {{false}};
    
    // Initialize start and end points
    Point start = {2, 0};
    Point end = {0, 3};
    
    // Initialize path and path length
    Point path[25];
    int n = 0;
    
    // Find the path using depth first search
    bool found = dfs(maze, visited, start, end, path, n);
    
    // Display result
    if (found) printf("Path found\n");
    else printf("Path not found\n");
    
    return 0;
}