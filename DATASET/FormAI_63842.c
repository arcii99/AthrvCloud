//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
// Woohoo! I am thrilled to present to you the Maze Route Finder program!
// This amazing program will help you find your way out of confusing mazes
// with ease and excitement!

#include <stdio.h>
#define ROW 10
#define COL 20

int maze[ROW][COL] = {     // Here's the maze - you can change its numbers to create your own maze!
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}; 

int visited[ROW][COL];      // This array will be used to keep track of the visited cells.

void printMaze() {          // This function prints the maze.
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int findRoute(int startX, int startY, int endX, int endY) {    // This function finds the route to the end of the maze.
    if(startX == endX && startY == endY) {
        return 1;
    }
    if(maze[startX][startY] == 1 || visited[startX][startY] == 1) {
        return 0;
    }
    visited[startX][startY] = 1;
    if(startX < ROW - 1 && findRoute(startX + 1, startY, endX, endY)) {     // Move down
        printf("(%d,%d) --> ", startX, startY);
        return 1;
    }
    if(startY < COL - 1 && findRoute(startX, startY + 1, endX, endY)) {     // Move right
        printf("(%d,%d) --> ", startX, startY);
        return 1;
    }
    if(startX > 0 && findRoute(startX - 1, startY, endX, endY)) {          // Move up
        printf("(%d,%d) --> ", startX, startY);
        return 1;
    }
    if(startY > 0 && findRoute(startX, startY - 1, endX, endY)) {          // Move left
        printf("(%d,%d) --> ", startX, startY);
        return 1;
    }
    return 0;   // If the route is not found, return 0.
}

int main() {
    printf("Welcome to the Maze Route Finder!\n");
    printf("Here's the maze:\n");
    printMaze();
    printf("Let's find the route from the top-left corner to the bottom-right corner:\n");
    if(findRoute(1, 1, 8, 18)) {
        printf("(8,18)\n");
    } else {
        printf("Route not found!\n");
    }
    return 0;
}