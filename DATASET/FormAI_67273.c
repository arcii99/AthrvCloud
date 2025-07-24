//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define constants for the maze dimensions
#define MAZE_WIDTH 12
#define MAZE_HEIGHT 10

// Define constants for the maze elements
#define WALL 'X'
#define SPACE '.'
#define START 'S'
#define END 'E'
#define PATH '*'

// Declare array to store the maze
char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {'X','X','X','X','X','X','X','X','X','X','X','X'},
    {'X','.','.','.','X','X','.','.','.','.','.','X'},
    {'X','.','X','.','X','X','X','.','X','.','X','X'},
    {'X','.','X','.','.','.','X','.','X','.','.','X'},
    {'X','.','X','.','X','.','X','.','X','X','.','X'},
    {'X','X','X','.','X','.','X','.','.','.','.','X'},
    {'X','.','X','X','X','.','X','.','X','X','X','X'},
    {'X','.','.','.','X','.','X','.','.','.','.','X'},
    {'X','X','X','.','X','.','.','.','X','X','X','X'},
    {'X','X','X','X','X','X','X','X','X','X','X','X'},
};

// Define struct for point on the maze
typedef struct Point Point;
struct Point {
    int x;
    int y;
};

// Declare function to print the maze
void printMaze() {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

// Declare function to check if a given point is a valid path
int isValidPath(Point point) {
    // Check that the point is within the maze bounds
    if (point.x < 0 || point.x >= MAZE_WIDTH || point.y < 0 || point.y >= MAZE_HEIGHT) {
        return 0;
    }
    
    // Check that the point is not a wall and has not already been visited
    if (maze[point.y][point.x] == WALL || maze[point.y][point.x] == PATH) {
        return 0;
    }
    
    return 1;
}

// Declare recursive function to find the path through the maze
int findPath(Point point) {
    // Check if we have reached the end of the maze
    if (maze[point.y][point.x] == END) {
        maze[point.y][point.x] = PATH;
        return 1;
    }
    
    // Check if this point is a valid path
    if (!isValidPath(point)) {
        return 0;
    }
    
    // Mark this point as part of the path
    maze[point.y][point.x] = PATH;
    
    // Check all valid directions
    if (findPath((Point){point.x+1, point.y})) {
        return 1;
    }
    if (findPath((Point){point.x-1, point.y})) {
        return 1;
    }
    if (findPath((Point){point.x, point.y+1})) {
        return 1;
    }
    if (findPath((Point){point.x, point.y-1})) {
        return 1;
    }
    
    // Mark this point as visited (but not on the path)
    maze[point.y][point.x] = SPACE;
    
    return 0;
}

int main() {
    // Find the starting point
    Point start;
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (maze[y][x] == START) {
                start.x = x;
                start.y = y;
            }
        }
    }
    
    // Print the initial maze
    printf("Romeo opens the door to a dimly lit room. He pulls out a small lantern that casts a flickering light across the walls. He sees the following...\n");
    printMaze();
    
    // Find the path through the maze
    if (findPath(start)) {
        // Print the final maze with the path
        printf("Juliet's voice echoes through the halls.\n");
        printMaze();
        
        // Romeo reaches Juliet
        printf("Romeo and Juliet are reunited at last! Their love will never be separated again.\n");
    } else {
        // No path was found
        printf("Romeo looks around the room but sees no way out. He is trapped and will never see Juliet again...\n");
    }
    
    return 0;
}