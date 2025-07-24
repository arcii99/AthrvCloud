//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>

#define ROWS 10
#define COLUMNS 10

// Define the maze as a 2D array
int maze[ROWS][COLUMNS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define a struct to hold the current location in the maze
struct Location {
    int row;
    int column;
};

// Define a struct to hold a path through the maze
struct Path {
    struct Location locations[ROWS * COLUMNS]; // A path can never be more than the size of the maze
    int length;
};

// Function to check if a location is valid (ie. not out of bounds and not a wall)
int isValidLocation(int row, int column) {
    if (row < 0 || column < 0 || row >= ROWS || column >= COLUMNS) {
        return 0; // Out of bounds
    }
    return !maze[row][column]; // Return whether the location is not a wall
}

// Function to find a path through the maze
struct Path findPath(struct Location start, struct Location end) {
    struct Path path;
    path.length = 0; // Initialize the path length to 0
    int visited[ROWS][COLUMNS] = { 0 }; // Initialize the visited array to 0
    int found = 0; // Initialize found to false

    // Create a queue to hold locations to visit
    struct Location queue[ROWS * COLUMNS];
    int front = 0, back = 0;
    queue[back++] = start;

    visited[start.row][start.column] = 1;

    // Loop until we find the end location or there are no more locations to visit
    while (front < back && !found) {
        struct Location current = queue[front++];

        // Check if we have found the end location
        if (current.row == end.row && current.column == end.column) {
            found = 1;
            int i;
            for (i = 0; i < path.length; i++) {
                if (i > 0) {
                    printf(" -> ");
                }
                printf("(%d,%d)", path.locations[i].row, path.locations[i].column);
            }
            printf(" -> (%d,%d)\n", current.row, current.column);
            path.locations[path.length++] = current;
            break;
        }

        // Check up
        if (isValidLocation(current.row - 1, current.column) && !visited[current.row - 1][current.column]) {
            struct Location next = { current.row - 1, current.column };
            queue[back++] = next;
            visited[next.row][next.column] = 1;
        }

        // Check right
        if (isValidLocation(current.row, current.column + 1) && !visited[current.row][current.column + 1]) {
            struct Location next = { current.row, current.column + 1 };
            queue[back++] = next;
            visited[next.row][next.column] = 1;
        }

        // Check down
        if (isValidLocation(current.row + 1, current.column) && !visited[current.row + 1][current.column]) {
            struct Location next = { current.row + 1, current.column };
            queue[back++] = next;
            visited[next.row][next.column] = 1;
        }

        // Check left
        if (isValidLocation(current.row, current.column - 1) && !visited[current.row][current.column - 1]) {
            struct Location next = { current.row, current.column - 1 };
            queue[back++] = next;
            visited[next.row][next.column] = 1;
        }

        // Add the current location to the path
        path.locations[path.length++] = current;
    }

    // If we didn't find a path, print an error message
    if (!found) {
        printf("No path found.\n");
    }

    return path;
}

int main() {
    // Define the start and end locations
    struct Location start = { 1, 1 };
    struct Location end = { 5, 8 };

    // Find a path from the start to the end
    struct Path path = findPath(start, end);

    return 0;
}