//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Size of the maze
#define N 10
#define M 20

// Directions
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// Structure for maze cells
struct cell {
    int visited;
    int walls[5];
};

// A function to generate random integer between a and b
int randInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

// Create initial maze with all walls closed
void initMaze(struct cell maze[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            maze[i][j].visited = 0;
            for(int k = 1; k <= 4; k++) {
                maze[i][j].walls[k] = 1;
            }
        }
    }
}

// Print maze to console
void printMaze(struct cell maze[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("+");
            if(maze[i][j].walls[NORTH] == 1) printf("---");
            else printf("   ");
            printf("+");
        }
        printf("\n");
        for(int j = 0; j < M; j++) {
            if(maze[i][j].walls[WEST] == 1) printf("|");
            else printf(" ");
            if(maze[i][j].visited == 1) printf("*");
            else printf(" ");
            printf(" ");
            if(maze[i][j].walls[EAST] == 1) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
    for(int j = 0; j < M; j++) {
        printf("+");
        if(maze[N-1][j].walls[SOUTH] == 1) printf("---");
        else printf("   ");
        printf("+");
    }
    printf("\n");
}

// Function to remove wall between current cell and next cell
void removeWall(struct cell maze[N][M], int curr_row, int curr_col, int next_row, int next_col) {
    if(curr_row == next_row && curr_col == next_col + 1) { // Current cell is west of next cell
        maze[curr_row][curr_col].walls[WEST] = 0;
        maze[next_row][next_col].walls[EAST] = 0;
    } else if(curr_row == next_row && curr_col == next_col - 1) { // Current cell is east of next cell
        maze[curr_row][curr_col].walls[EAST] = 0;
        maze[next_row][next_col].walls[WEST] = 0;
    } else if(curr_row == next_row + 1 && curr_col == next_col) { // Current cell is north of next cell
        maze[curr_row][curr_col].walls[NORTH] = 0;
        maze[next_row][next_col].walls[SOUTH] = 0;
    } else if(curr_row == next_row - 1 && curr_col == next_col) { // Current cell is south of next cell
        maze[curr_row][curr_col].walls[SOUTH] = 0;
        maze[next_row][next_col].walls[NORTH] = 0;
    }
}

// Recursive function to generate the maze
void generateMazeRecursive(struct cell maze[N][M], int curr_row, int curr_col) {
    maze[curr_row][curr_col].visited = 1;
    // Randomize order of directions to explore
    int directions[] = {NORTH, EAST, SOUTH, WEST};
    for(int i = 0; i < 4; i++) {
        int index = randInt(i, 3);
        int temp = directions[index];
        directions[index] = directions[i];
        directions[i] = temp;
    }
    // Explore each direction
    for(int i = 0; i < 4; i++) {
        int next_row, next_col;
        switch(directions[i]) {
            case NORTH:
                next_row = curr_row - 1;
                next_col = curr_col;
                break;
            case EAST:
                next_row = curr_row;
                next_col = curr_col + 1;
                break;
            case SOUTH:
                next_row = curr_row + 1;
                next_col = curr_col;
                break;
            case WEST:
                next_row = curr_row;
                next_col = curr_col - 1;
                break;
        }
        // Check if next cell is within bounds and not visited
        if(next_row >= 0 && next_row < N && next_col >= 0 && next_col < M && maze[next_row][next_col].visited == 0) {
            removeWall(maze, curr_row, curr_col, next_row, next_col);
            generateMazeRecursive(maze, next_row, next_col);
        }
    }
}

// Function to generate the maze
void generateMaze(struct cell maze[N][M]) {
    initMaze(maze);
    srand(time(0));
    generateMazeRecursive(maze, 0, 0);
}

// Main function to run the program
int main() {
    struct cell maze[N][M];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}