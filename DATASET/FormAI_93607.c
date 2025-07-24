//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 25
#define COL 25

// Define struct for cell
struct cell {
    int x;
    int y;
    int visited;
    int walls[4]; // 0: up, 1: right, 2: down, 3: left
};
typedef struct cell Cell;

// Function declarations
void init(Cell maze[][COL]);
void print_maze(Cell maze[][COL]);
int get_rand(int min, int max);
void generate_maze(Cell maze[][COL], int x, int y);
int check_neighbors(Cell maze[][COL], int x, int y);

int main() {
    Cell maze[ROW][COL];
    init(maze);
    print_maze(maze);
    generate_maze(maze, 0, 0);
    printf("Maze after generation:\n");
    print_maze(maze);
    return 0;
}

// Initialize the maze with all walls
void init(Cell maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].visited = 0;
            maze[i][j].walls[0] = 1; // up
            maze[i][j].walls[1] = 1; // right
            maze[i][j].walls[2] = 1; // down
            maze[i][j].walls[3] = 1; // left
        }
    }
}

// Print the maze
void print_maze(Cell maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("+");
            if (maze[i][j].walls[0]) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("+\n");
        for (int j = 0; j < COL; j++) {
            if (maze[i][j].walls[3]) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < COL; j++) {
        printf("+---");
    }
    printf("+\n");
}

// Get random integer between min and max
int get_rand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate the maze recursively
void generate_maze(Cell maze[][COL], int x, int y) {
    maze[x][y].visited = 1;
    while (check_neighbors(maze, x, y)) {
        int dir = get_rand(0, 3);
        switch (dir) {
            case 0: // up
                if (x > 0 && !maze[x-1][y].visited) {
                    maze[x][y].walls[0] = 0;
                    maze[x-1][y].walls[2] = 0;
                    generate_maze(maze, x-1, y);
                }
                break;
            case 1: // right
                if (y < COL-1 && !maze[x][y+1].visited) {
                    maze[x][y].walls[1] = 0;
                    maze[x][y+1].walls[3] = 0;
                    generate_maze(maze, x, y+1);
                }
                break;
            case 2: // down
                if (x < ROW-1 && !maze[x+1][y].visited) {
                    maze[x][y].walls[2] = 0;
                    maze[x+1][y].walls[0] = 0;
                    generate_maze(maze, x+1, y);
                }
                break;
            case 3: // left
                if (y > 0 && !maze[x][y-1].visited) {
                    maze[x][y].walls[3] = 0;
                    maze[x][y-1].walls[1] = 0;
                    generate_maze(maze, x, y-1);
                }
                break;
        }
    }
}

// Check if there are unvisited neighbors
int check_neighbors(Cell maze[][COL], int x, int y) {
    int up = (x > 0 && !maze[x-1][y].visited) ? 1 : 0;
    int right = (y < COL-1 && !maze[x][y+1].visited) ? 1 : 0;
    int down = (x < ROW-1 && !maze[x+1][y].visited) ? 1 : 0;
    int left = (y > 0 && !maze[x][y-1].visited) ? 1 : 0;
    return up || right || down || left;
}