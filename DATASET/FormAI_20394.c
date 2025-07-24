//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {' ',' ','#',' ','#',' ','#','#','#','#'},
    {'#','#','#',' ','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#','#','#',' ','#'},
    {'#','#','#','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ','#',' ','#',' ','#',' ','#'},
    {'#','#',' ','#',' ',' ',' ','#',' ','#'},
    {'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

int visited[ROW][COL] = {0};

// A function to print the maze
void printMaze() {
    printf("\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// A recursive function to find the route
int findRoute(int row, int col) {
    
    if(row<0 || row>=ROW || col<0 || col>=COL) { // Out of maze
        return 0;
    }
    
    if(maze[row][col] == '#' || visited[row][col]) { // Wall or already visited
        return 0;
    }
    
    visited[row][col] = 1; // Mark as visited
    
    if(maze[row][col] == 'G') { // Reached goal
        printf("Goal reached!\n");
        return 1;
    }
    
    if(findRoute(row+1, col) || findRoute(row-1, col) || findRoute(row, col+1) || findRoute(row, col-1)) { // Move in all directions
        printf("(%d,%d)\n", row, col); // Print the route
        return 1;
    }
    
    return 0; // No route found
}

int main() {
    
    printf("Maze:\n");
    printMaze();
    
    int start_row, start_col;
    printf("\nEnter the starting point (row, column) coordinates: ");
    scanf("%d %d", &start_row, &start_col);
    
    if(findRoute(start_row, start_col)) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }
    
    return 0;
}