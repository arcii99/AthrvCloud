//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the maze size
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

// define constants for the tile types
#define TILE_WALL '#'
#define TILE_PATH '.'
#define TILE_START 'S'
#define TILE_END 'E'

// define the maze and the visited array
char maze[MAZE_HEIGHT][MAZE_WIDTH];
int visited[MAZE_HEIGHT][MAZE_WIDTH];

// define the start and end positions
int start_x, start_y;
int end_x, end_y;

// function to initialize the maze
void initMaze() {
    // set all tiles to walls
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = TILE_WALL;
        }
    }
    
    // set the start and end positions
    start_x = rand() % MAZE_WIDTH;
    start_y = rand() % MAZE_HEIGHT;
    end_x = rand() % MAZE_WIDTH;
    end_y = rand() % MAZE_HEIGHT;
    maze[start_y][start_x] = TILE_START;
    maze[end_y][end_x] = TILE_END;
    
    // set a few random paths (20% chance of a path being set)
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (rand() % 100 < 20) maze[i][j] = TILE_PATH;
        }
    }
}

// function to print the maze
void printMaze() {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if a tile is valid (i.e., not a wall and not visited)
int isValidTile(int x, int y) {
    if (x < 0 || y < 0 || x >= MAZE_WIDTH || y >= MAZE_HEIGHT) return 0;
    if (maze[y][x] == TILE_WALL || visited[y][x]) return 0;
    return 1;
}

// function to find the shortest path from start to end
int findPath(int x, int y, int steps) {
    // check if we reached the end
    if (x == end_x && y == end_y) return steps;
    
    // mark the tile as visited
    visited[y][x] = 1;
    
    // check all possible neighbor tiles
    int best_path = 0;
    if (isValidTile(x+1, y)) {
        int path = findPath(x+1, y, steps+1);
        if (path && (best_path == 0 || path < best_path)) best_path = path;
    }
    if (isValidTile(x-1, y)) {
        int path = findPath(x-1, y, steps+1);
        if (path && (best_path == 0 || path < best_path)) best_path = path;
    }
    if (isValidTile(x, y+1)) {
        int path = findPath(x, y+1, steps+1);
        if (path && (best_path == 0 || path < best_path)) best_path = path;
    }
    if (isValidTile(x, y-1)) {
        int path = findPath(x, y-1, steps+1);
        if (path && (best_path == 0 || path < best_path)) best_path = path;
    }
    
    // mark the tile as unvisited
    visited[y][x] = 0;
    
    // return the best path length (or 0 if no path found)
    return best_path;
}

// main function
int main() {
    // seed random number generator
    srand(time(NULL));
    
    // generate the maze
    initMaze();
    
    // print the maze
    printf("Maze:\n");
    printMaze();
    printf("\n");
    
    // find the shortest path from start to end
    int path_length = findPath(start_x, start_y, 0);
    
    // print the result
    if (path_length) {
        printf("Shortest path found! Length: %d\n", path_length);
    } else {
        printf("No path found!\n");
    }
    
    return 0;
}