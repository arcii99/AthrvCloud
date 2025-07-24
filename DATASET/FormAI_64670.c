//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 // Width of maze
#define HEIGHT 10 // Height of maze

// Function to print out maze
void printMaze(int maze[][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze using depth-first search algorithm
void generateMaze(int maze[][WIDTH], int x, int y) {
    maze[y][x] = ' '; // Set current cell as visited
    
    // Array to keep track of unvisited neighbors
    int neighbors[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int num_neighbors = 4;
    
    // Shuffle the array
    for(int i=0; i<num_neighbors; i++) {
        int j = rand() % num_neighbors;
        int tmp_x = neighbors[i][0];
        int tmp_y = neighbors[i][1];
        neighbors[i][0] = neighbors[j][0];
        neighbors[i][1] = neighbors[j][1];
        neighbors[j][0] = tmp_x;
        neighbors[j][1] = tmp_y;
    }
    
    // Loop through each neighbor
    for(int i=0; i<num_neighbors; i++) {
        int neighbor_x = x + neighbors[i][0];
        int neighbor_y = y + neighbors[i][1];
        // Check if neighbor is within bounds of maze and is unvisited
        if(neighbor_x >= 0 && neighbor_x < WIDTH && neighbor_y >= 0 && neighbor_y < HEIGHT && maze[neighbor_y][neighbor_x] == '#') {
            // Check if neighbor is to the left or right
            if(neighbors[i][0] == -1) {
                maze[y][x-1] = ' ';
            } else if(neighbors[i][0] == 1) {
                maze[y][x+1] = ' ';
            }
            // Check if neighbor is above or below
            if(neighbors[i][1] == -1) {
                maze[y-1][x] = ' ';
            } else if(neighbors[i][1] == 1) {
                maze[y+1][x] = ' ';
            }
            // Recursively call generateMaze on neighbor
            generateMaze(maze, neighbor_x, neighbor_y);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int maze[HEIGHT][WIDTH]; // 2D array to represent maze
    
    // Initialize maze with walls
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            maze[i][j] = '#';
        }
    }
    
    generateMaze(maze, 0, 0); // Generate the maze starting from top-left corner
    printMaze(maze); // Print out the maze
    
    return 0;
}