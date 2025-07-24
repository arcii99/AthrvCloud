//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

char maze[10][10] = {
    {'#','#','#','#','#','#','#','#','e','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#','#'},
    {'#',' ','#',' ','#','#','#',' ',' ','#'},
    {'#',' ','#','#','#',' ',' ','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#','#',' ','#'},
    {'#','#','#',' ','#',' ',' ','#','#','#'},
    {'#',' ','#',' ',' ','#','#','#',' ','#'},
    {'#',' ','#','#',' ','#',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ','#',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','s','#'}
};

int start_x, start_y, end_x, end_y;
int done = 0;

// Function to print the maze
void printMaze() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find the starting and ending points
void findStartAndEnd() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(maze[i][j] == 's') {
                start_x = i;
                start_y = j;
            }
            if(maze[i][j] == 'e') {
                end_x = i;
                end_y = j;
            }
        }
    }
}

// Function to move in a direction
void move(int x, int y) {
    if(maze[x][y] == ' ') { // If it's a space
        maze[x][y] = '.'; // Mark as visited
        printMaze(); // Print the maze
        if(x == end_x && y == end_y) { // If we've reached the end
            done = 1; // Set done to true
            return;
        }
        move(x+1, y); // Move down
        if(done) return; // If we've reached the end, return
        move(x, y+1); // Move right
        if(done) return; // If we've reached the end, return
        move(x-1, y); // Move up
        if(done) return; // If we've reached the end, return
        move(x, y-1); // Move left
    }
}

// Main function
int main() {
    findStartAndEnd(); // Find the starting and ending points
    printMaze(); // Print the maze
    printf("\n");
    move(start_x, start_y); // Start solving the maze
    printf("Done!\n");
    return 0;
}