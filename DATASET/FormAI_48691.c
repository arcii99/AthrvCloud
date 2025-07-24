//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>

// Create a maze with '#' as walls and '.' as open spaces
char maze[10][10] = { 
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define struct for storing coordinates
struct Coordinate {
    int x, y;
};

// Define function to print the maze
void printMaze() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Define function to check if a coordinate is within the maze
int isWithinMaze(struct Coordinate coordinate) {
    return (coordinate.x >= 0 && coordinate.x < 10 && coordinate.y >= 0 && coordinate.y < 10);
}

// Define function to check if a coordinate is an open space
int isOpenSpace(struct Coordinate coordinate) {
    return (maze[coordinate.x][coordinate.y] == '.');
}

// Define function to check if a coordinate has already been visited
int isNotVisited(struct Coordinate coordinate, struct Coordinate visited[100]) {
    for(int i = 0; i < 100; i++) {
        if(coordinate.x == visited[i].x && coordinate.y == visited[i].y) {
            return 0;
        }
    }
    return 1;
}

// Define function to find a route through the maze
int mazeRoute(struct Coordinate start, struct Coordinate end, struct Coordinate visited[100], int visitedCount) {
    // Check if the current coordinate is the end coordinate
    if(start.x == end.x && start.y == end.y) {
        return 1;
    }
    // Check all adjacent coordinates
    struct Coordinate up = {start.x - 1, start.y};
    struct Coordinate right = {start.x, start.y + 1};
    struct Coordinate down = {start.x + 1, start.y};
    struct Coordinate left = {start.x, start.y - 1};
    struct Coordinate adjacentCoordinates[4] = {up, right, down, left};
    // Check each adjacent coordinate
    for(int i = 0; i < 4; i++) {
        // Check if the coordinate is within the maze, is an open space, and has not been visited
        if(isWithinMaze(adjacentCoordinates[i]) && isOpenSpace(adjacentCoordinates[i]) && isNotVisited(adjacentCoordinates[i], visited)) {
            // Add the coordinate to the list of visited coordinates
            visited[visitedCount] = adjacentCoordinates[i];
            visitedCount++;
            // Recursively call the mazeRoute function for the adjacent coordinate
            if(mazeRoute(adjacentCoordinates[i], end, visited, visitedCount)) {
                // If the mazeRoute function returns 1, it has found a valid route through the maze
                return 1;
            }
        }
    }
    // If none of the adjacent coordinates lead to a valid route, return 0
    return 0;
}

int main() {
    // Define starting and ending coordinates
    struct Coordinate start = {1, 1};
    struct Coordinate end = {8, 8};
    // Define an array for storing visited coordinates
    struct Coordinate visited[100] = {start};
    // Call the mazeRoute function to find a route through the maze
    if(mazeRoute(start, end, visited, 1)) {
        // If mazeRoute returns 1, a route has been found
        printf("Route found!\n");
        // Mark the route with 'X'
        for(int i = 1; i < 100; i++) {
            if(visited[i].x == end.x && visited[i].y == end.y) {
                maze[visited[i].x][visited[i].y] = 'X';
                break;
            } else {
                maze[visited[i].x][visited[i].y] = 'X';
            }
        }
        // Print the marked maze
        printMaze();
    } else {
        // If mazeRoute returns 0, no route has been found
        printf("No route found.\n");
    }
    return 0;
}