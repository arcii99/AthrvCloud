//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

// define cell struct
typedef struct cell {
    int x;
    int y;
    int visited;
    int wall[4];
} cell;

// define function prototypes
int get_random(int, int);
void init_maze(cell maze[HEIGHT][WIDTH]);
void generate_maze(cell maze[HEIGHT][WIDTH], int x, int y);
void print_maze(cell maze[HEIGHT][WIDTH]);

int main() {

    // initialize maze
    cell maze[HEIGHT][WIDTH];
    init_maze(maze);

    // generate maze
    generate_maze(maze, 0, 0);

    // print maze
    print_maze(maze);

    return 0;
}

int get_random(int min, int max) {
    // returns a random number between min and max (inclusive)
    return (rand() % (max - min + 1)) + min;
}

void init_maze(cell maze[HEIGHT][WIDTH]) {
    // initializes all cells in maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j].x = j;
            maze[i][j].y = i;
            maze[i][j].visited = 0;
            maze[i][j].wall[0] = 1; // top
            maze[i][j].wall[1] = 1; // right
            maze[i][j].wall[2] = 1; // bottom
            maze[i][j].wall[3] = 1; // left
        }
    }
}

void generate_maze(cell maze[HEIGHT][WIDTH], int x, int y) {
    // recursive function to generate maze

    // mark cell as visited
    maze[y][x].visited = 1;

    // randomly shuffle directions
    int directions[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int index = get_random(0, 3);
        int temp = directions[index];
        directions[index] = directions[i];
        directions[i] = temp;
    }

    // for each direction, check if next cell is valid and unvisited
    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        int next_x, next_y;
        switch (direction) {
            case 0: // top
                next_x = x;
                next_y = y-1;
                break;
            case 1: // right
                next_x = x+1;
                next_y = y;
                break;
            case 2: // bottom
                next_x = x;
                next_y = y+1;
                break;
            case 3: // left
                next_x = x-1;
                next_y = y;
                break;
        }
        // check if next cell is valid and unvisited
        if (next_x >= 0 && next_x < WIDTH && next_y >= 0 && next_y < HEIGHT && maze[next_y][next_x].visited == 0) {
            // remove walls between current cell and next cell
            switch (direction) {
                case 0: // top
                    maze[y][x].wall[0] = 0;
                    maze[next_y][next_x].wall[2] = 0;
                    break;
                case 1: // right
                    maze[y][x].wall[1] = 0;
                    maze[next_y][next_x].wall[3] = 0;
                    break;
                case 2: // bottom
                    maze[y][x].wall[2] = 0;
                    maze[next_y][next_x].wall[0] = 0;
                    break;
                case 3: // left
                    maze[y][x].wall[3] = 0;
                    maze[next_y][next_x].wall[1] = 0;
                    break;
            }
            // recursively generate maze from next cell
            generate_maze(maze, next_x, next_y);
        }
    }
}

void print_maze(cell maze[HEIGHT][WIDTH]) {
    // print maze

    // horizontal border
    printf("+");
    for (int i = 0; i < WIDTH; i++) {
        printf("--+");
    }
    printf("\n");

    // vertical walls and cells
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j].wall[0] == 1) {
                printf("  |");
            } else {
                printf("   ");
            }
        }
        printf("\n+");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j].wall[1] == 1) {
                printf("--+");
            } else {
                printf("  +");
            }
        }
        printf("\n");
    }
}