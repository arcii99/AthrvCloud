//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

// Structure for a cell in the maze
typedef struct {
    int north, south, east, west;
    int visited;
} Cell;

// Initialize the maze grid
void initializeMaze(Cell maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j].visited = 0;
            maze[i][j].north = 1;
            maze[i][j].south = 1;
            maze[i][j].east = 1;
            maze[i][j].west = 1;
        }
    }
}

// Print the maze
void printMaze(Cell maze[HEIGHT][WIDTH]) {
    // Print top border
    for(int i = 0; i < WIDTH; i++) {
        printf("__");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j].east == 1) {
                printf("  ");
            } else {
                printf("| ");
            }
        }
        printf("\n");
        
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j].south == 1) {
                printf("__");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Check if all cells are visited
int allVisited(Cell maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j].visited == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Generate the maze
void generateMaze(Cell maze[HEIGHT][WIDTH], int cur_i, int cur_j) {
    maze[cur_i][cur_j].visited = 1;
    while (!allVisited(maze)) {
        int dir = rand() % 4;
        switch (dir) {
            case 0: // North
                if (cur_i > 0 && maze[cur_i-1][cur_j].visited == 0) {
                    maze[cur_i][cur_j].north = 0;
                    maze[cur_i-1][cur_j].south = 0;
                    generateMaze(maze, cur_i-1, cur_j);
                }
                break;
            case 1: // South
                if (cur_i < HEIGHT-1 && maze[cur_i+1][cur_j].visited == 0) {
                    maze[cur_i][cur_j].south = 0;
                    maze[cur_i+1][cur_j].north = 0;
                    generateMaze(maze, cur_i+1, cur_j);
                }
                break;
            case 2: // East
                if (cur_j < WIDTH-1 && maze[cur_i][cur_j+1].visited == 0) {
                    maze[cur_i][cur_j].east = 0;
                    maze[cur_i][cur_j+1].west = 0;
                    generateMaze(maze, cur_i, cur_j+1);
                }
                break;
            case 3: // West
                if (cur_j > 0 && maze[cur_i][cur_j-1].visited == 0) {
                    maze[cur_i][cur_j].west = 0;
                    maze[cur_i][cur_j-1].east = 0;
                    generateMaze(maze, cur_i, cur_j-1);
                }
                break;
            default:
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    Cell maze[HEIGHT][WIDTH];
    initializeMaze(maze);
    generateMaze(maze, HEIGHT/2, WIDTH/2);
    printMaze(maze);

    return 0;
}