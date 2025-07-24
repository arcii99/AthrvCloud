//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 20
#define COL_SIZE 30
#define WALL 0
#define PATH 1
#define START_ROW 1
#define START_COL 1
#define GOAL_ROW ROW_SIZE - 2
#define GOAL_COL COL_SIZE - 2

// Function prototypes
void initMaze(int maze[][COL_SIZE]);
void generateMaze(int maze[][COL_SIZE], int row, int col);
void printMaze(int maze[][COL_SIZE]);

int main(void) {
    int maze[ROW_SIZE][COL_SIZE];
    srand(time(NULL));
    initMaze(maze);
    generateMaze(maze, START_ROW, START_COL);
    printMaze(maze);
    return 0;
}

void initMaze(int maze[][COL_SIZE]) {
    // Initialize the maze with walls everywhere
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            maze[row][col] = WALL;
        }
    }
    // Make holes for start and goal
    maze[START_ROW][START_COL] = PATH;
    maze[GOAL_ROW][GOAL_COL] = PATH;
}

void generateMaze(int maze[][COL_SIZE], int row, int col) {
    // Generate a procedurally generated maze using DFS algorithm
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // Directions to explore
    int num_dirs = 4;
    int indices[4] = {0, 1, 2, 3}; // Indices of dirs to shuffle
    for (int i = 0; i < num_dirs; i++) {
        int j = rand() % num_dirs;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
    maze[row][col] = PATH;
    for (int i = 0; i < num_dirs; i++) {
        int next_row = row + dirs[indices[i]][0];
        int next_col = col + dirs[indices[i]][1];
        if (next_row < 0 || next_row >= ROW_SIZE || next_col < 0 || next_col >= COL_SIZE) {
            continue; // Skip out of bounds cells
        }
        if (maze[next_row][next_col] == PATH) {
            continue; // Skip already visited cells
        }
        int wall_row = (row + next_row) / 2;
        int wall_col = (col + next_col) / 2;
        maze[wall_row][wall_col] = PATH;
        generateMaze(maze, next_row, next_col);
    }
}

void printMaze(int maze[][COL_SIZE]) {
    // Print the generated maze
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (maze[row][col] == WALL) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}