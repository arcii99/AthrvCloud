//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the maze grid size
#define MAZE_WIDTH 21
#define MAZE_HEIGHT 11

// Constants for the wall status of each cell
#define WALL_LEFT 1
#define WALL_RIGHT 2
#define WALL_TOP 4
#define WALL_BOTTOM 8

// Prototype for the maze generator function
void generate_maze(int maze[MAZE_WIDTH][MAZE_HEIGHT]);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the maze grid with all walls
    int maze[MAZE_WIDTH][MAZE_HEIGHT];
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            maze[x][y] = WALL_LEFT | WALL_RIGHT | WALL_TOP | WALL_BOTTOM;
        }
    }
    
    // Generate the maze
    generate_maze(maze);
    
    // Print the maze
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        // Print the top row of each cell
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("+");
            if (maze[x][y] & WALL_TOP) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("+\n");
        
        // Print the middle row of each cell
        for (int x = 0; x < MAZE_WIDTH; x++) {
            if (maze[x][y] & WALL_LEFT) {
                printf("|");
            } else {
                printf(" ");
            }
            printf("   ");
            if (x == MAZE_WIDTH-1) {
                printf("|");
            }
        }
        printf("\n");
    }
    
    // Print the bottom row of the maze
    for (int x = 0; x < MAZE_WIDTH; x++) {
        printf("+");
        if (maze[x][MAZE_HEIGHT-1] & WALL_BOTTOM) {
            printf("---");
        } else {
            printf("   ");
        }
    }
    printf("+\n");
    
    return 0;
}

void generate_maze(int maze[MAZE_WIDTH][MAZE_HEIGHT]) {
    // Start at the top-left corner of the maze
    int current_x = 0;
    int current_y = 0;
    
    // Mark the starting cell as visited
    maze[current_x][current_y] &= ~WALL_TOP;
    
    // Loop until the entire maze has been visited
    while (1) {
        // Check if all neighboring cells have been visited
        int unvisited_count = 0;
        int unvisited_x[4];
        int unvisited_y[4];
        if (current_x > 0 && (maze[current_x-1][current_y] & WALL_TOP)) {
            unvisited_x[unvisited_count] = current_x-1;
            unvisited_y[unvisited_count] = current_y;
            unvisited_count++;
        }
        if (current_x < MAZE_WIDTH-1 && (maze[current_x+1][current_y] & WALL_TOP)) {
            unvisited_x[unvisited_count] = current_x+1;
            unvisited_y[unvisited_count] = current_y;
            unvisited_count++;
        }
        if (current_y > 0 && (maze[current_x][current_y-1] & WALL_TOP)) {
            unvisited_x[unvisited_count] = current_x;
            unvisited_y[unvisited_count] = current_y-1;
            unvisited_count++;
        }
        if (current_y < MAZE_HEIGHT-1 && (maze[current_x][current_y+1] & WALL_TOP)) {
            unvisited_x[unvisited_count] = current_x;
            unvisited_y[unvisited_count] = current_y+1;
            unvisited_count++;
        }
        if (unvisited_count == 0) {
            // No unvisited neighbors, backtrack to last visited cell
            if (current_x > 0 && (maze[current_x-1][current_y] & WALL_BOTTOM)) {
                maze[current_x][current_y] &= ~WALL_LEFT;
                current_x--;
            } else if (current_x < MAZE_WIDTH-1 && (maze[current_x+1][current_y] & WALL_BOTTOM)) {
                maze[current_x][current_y] &= ~WALL_RIGHT;
                current_x++;
            } else if (current_y > 0 && (maze[current_x][current_y-1] & WALL_BOTTOM)) {
                maze[current_x][current_y] &= ~WALL_TOP;
                current_y--;
            } else if (current_y < MAZE_HEIGHT-1 && (maze[current_x][current_y+1] & WALL_BOTTOM)) {
                maze[current_x][current_y] &= ~WALL_BOTTOM;
                current_y++;
            } else {
                // All neighbors and current cell have been visited, maze generation is complete
                break;
            }
        } else {
            // Move to a randomly selected unvisited neighbor and remove the wall
            int cell_index = rand() % unvisited_count;
            int next_x = unvisited_x[cell_index];
            int next_y = unvisited_y[cell_index];
            if (next_x < current_x) {
                maze[current_x][current_y] &= ~WALL_LEFT;
                maze[next_x][next_y] &= ~WALL_RIGHT;
            } else if (next_x > current_x) {
                maze[current_x][current_y] &= ~WALL_RIGHT;
                maze[next_x][next_y] &= ~WALL_LEFT;
            } else if (next_y < current_y) {
                maze[current_x][current_y] &= ~WALL_TOP;
                maze[next_x][next_y] &= ~WALL_BOTTOM;
            } else if (next_y > current_y) {
                maze[current_x][current_y] &= ~WALL_BOTTOM;
                maze[next_x][next_y] &= ~WALL_TOP;
            }
            current_x = next_x;
            current_y = next_y;
        }
    }
}