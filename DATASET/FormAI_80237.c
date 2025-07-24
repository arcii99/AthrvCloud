//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define maze size
#define ROW 6
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the structure to store the position of each cell in the maze
typedef struct Position {
    int x;
    int y;
} Position;

// Define the function to print the maze
void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%3d", maze[i][j]);
        }
        printf("\n");
    }
}

// Define the function to find the path from the start position to the end position in the maze
int findPath(Position start, Position end, Position path[], int length) {

    // If the start and end positions are the same, return true
    if (start.x == end.x && start.y == end.y) {
        path[length++] = start;
        return length;
    }

    // If the start position is outside the maze, return false
    if (start.x < 0 || start.x >= ROW || start.y < 0 || start.y >= COL) {
        return 0;
    }

    // If the start position is a wall or has already been visited, return false
    if (maze[start.x][start.y] == 1) {
        return 0;
    }
    
    // Mark the start position as visited
    maze[start.x][start.y] = 1;
    
    // Try to find the path to the end position from each direction
    int foundPath = 0;
    Position next = {start.x - 1, start.y};
    foundPath = findPath(next, end, path, length);
    if (foundPath) {
        path[length++] = start;
        return foundPath;
    }
    next.x = start.x + 1;
    next.y = start.y;
    foundPath = findPath(next, end, path, length);
    if (foundPath) {
        path[length++] = start;
        return foundPath;
    }
    next.x = start.x;
    next.y = start.y - 1;
    foundPath = findPath(next, end, path, length);
    if (foundPath) {
        path[length++] = start;
        return foundPath;
    }
    next.x = start.x;
    next.y = start.y + 1;
    foundPath = findPath(next, end, path, length);
    if (foundPath) {
        path[length++] = start;
        return foundPath;
    }

    // If no path was found, mark the start position as not visited
    maze[start.x][start.y] = 0;

    return 0;
}

int main() {
    // Define the start and end positions
    Position start = {1, 1};
    Position end = {4, 8};

    // Find the path from the start position to the end position
    Position path[ROW * COL];
    int length = 0;
    int foundPath = findPath(start, end, path, length);

    // If a path was found, print it
    if (foundPath) {
        printf("The path from (%d, %d) to (%d, %d) is: \n", start.x, start.y, end.x, end.y);
        for (int i = foundPath - 1; i >= 0; i--) {
            printf("(%d, %d) ", path[i].x, path[i].y);
        }
        printf("\n");
    }

    // If no path was found, print error message
    else {
        printf("No path was found from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    }

    // Print the maze with the path
    printf("\n");
    for (int i = foundPath - 1; i >= 0; i--) {
        maze[path[i].x][path[i].y] = 2;
    }
    printMaze();

    return 0;
}