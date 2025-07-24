//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_OBSTACLES 10

// Define a struct to represent each point on the grid
typedef struct Point {
    int x;
    int y;
} Point;

// Define a struct to represent each obstacle on the grid
typedef struct Obstacle {
    Point position;
    int size;
} Obstacle;

// Function to randomly generate obstacles
Obstacle generateObstacle() {
    Obstacle obstacle;
    obstacle.position.x = rand() % GRID_SIZE + 1;
    obstacle.position.y = rand() % GRID_SIZE + 1;
    obstacle.size = rand() % 5 + 1;
    
    return obstacle;
}

// Function to check if a point is inside an obstacle
int insideObstacle(Point point, Obstacle obstacle) {
    int xDistance = point.x - obstacle.position.x;
    int yDistance = point.y - obstacle.position.y;
    
    if (xDistance >= 0 && xDistance < obstacle.size
        && yDistance >= 0 && yDistance < obstacle.size) {
        return 1;
    }
    
    return 0;
}

// Function to check if a point is valid on the grid
int isValidPoint(Point point, Obstacle obstacles[]) {
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        if (insideObstacle(point, obstacles[i])) {
            return 0;
        }
    }
    
    if (point.x >= 1 && point.x <= GRID_SIZE
        && point.y >= 1 && point.y <= GRID_SIZE) {
        return 1;
    }
    
    return 0;
}

// Function to find the shortest path on the grid between two points
int findShortestPath(Point start, Point end, Obstacle obstacles[]) {
    // Define an array to keep track of visited points on the grid
    int visited[GRID_SIZE][GRID_SIZE] = {0};
    
    // Define an array to keep track of the shortest path to each point on the grid
    int distances[GRID_SIZE][GRID_SIZE] = {0};
    
    // Define a queue to store points that still need to be visited
    Point queue[GRID_SIZE * GRID_SIZE];
    int front = 0;
    int rear = 0;
    
    // Add the starting point to the queue and mark it as visited
    queue[rear++] = start;
    visited[start.x - 1][start.y - 1] = 1;
    
    // Check if the start point is invalid
    if (!isValidPoint(start, obstacles)) {
        printf("Error: Start point is invalid!\n");
        return -1;
    }
    
    // Check if the end point is invalid
    if (!isValidPoint(end, obstacles)) {
        printf("Error: End point is invalid!\n");
        return -1;
    }
    
    while (front != rear) {
        // Dequeue the next point from the front of the queue
        Point current = queue[front++];
        
        // Check if we have reached the end point
        if (current.x == end.x && current.y == end.y) {
            return distances[current.x - 1][current.y - 1];
        }
        
        // Define an array of possible moves from the current point
        Point moves[] = {{current.x - 1, current.y},
                         {current.x + 1, current.y},
                         {current.x, current.y - 1},
                         {current.x, current.y + 1}};
                         
        // Loop through each possible move
        for (int i = 0; i < 4; i++) {
            Point move = moves[i];
            
            // Check if the move is valid and has not been visited before
            if (isValidPoint(move, obstacles) && !visited[move.x - 1][move.y - 1]) {
                // Mark the move as visited and add it to the queue
                visited[move.x - 1][move.y - 1] = 1;
                queue[rear++] = move;
                
                // Update the distance to the move
                distances[move.x - 1][move.y - 1] = distances[current.x - 1][current.y - 1] + 1;
            }
        }
    }
    
    printf("Error: No path found!\n");
    return -1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the obstacles
    Obstacle obstacles[NUM_OBSTACLES];
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        obstacles[i] = generateObstacle();
    }
    
    // Print the obstacles
    printf("Obstacles:\n");
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        printf("Obstacle %d: (%d, %d), Size: %d\n", i + 1, obstacles[i].position.x, obstacles[i].position.y, obstacles[i].size);
    }
    
    // Define the start and end points
    Point start = {1, 1};
    Point end = {GRID_SIZE, GRID_SIZE};
    
    // Find the shortest path on the grid between the start and end points
    int shortestPath = findShortestPath(start, end, obstacles);
    
    // Print the shortest path
    printf("Shortest Path: %d\n", shortestPath);
    
    return 0;
}