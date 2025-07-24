//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

// colors for maze display
#define COLOR_RESET "\033[0m"
#define COLOR_WALL "\033[0;37m"
#define COLOR_PATH "\033[0;32m"

// randomly generates the maze
void generate_maze(int maze[HEIGHT][WIDTH])
{
    // initialize maze to all walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    // generate random starting position
    int x_start = rand() % (WIDTH-2) + 1;
    int y_start = rand() % (HEIGHT-2) + 1;
    
    maze[y_start][x_start] = 0; // set starting position as path
    
    // recursively carve out maze
    void generate_path(int x, int y) {
        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int index = rand() % (4-i) + i;
            int dx = 0, dy = 0;
            if (directions[index] == 0) {
                dy = -1;
            } else if (directions[index] == 1) {
                dx = 1;
            } else if (directions[index] == 2) {
                dy = 1;
            } else if (directions[index] == 3) {
                dx = -1;
            }
            int x_new = x + dx;
            int y_new = y + dy;
            if (x_new > 0 && x_new < WIDTH-1 && y_new > 0 && y_new < HEIGHT-1 &&
                    maze[y_new][x_new] == 1) {
                maze[y_new][x_new] = 0;
                maze[y_new+dy/2][x_new+dx/2] = 0;
                generate_path(x_new, y_new);
            }
            // remove direction from list of possible directions
            int temp = directions[i];
            directions[i] = directions[index];
            directions[index] = temp;
        }
    }
    generate_path(x_start, y_start);
}

// displays the maze
void display_maze(int maze[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf(COLOR_WALL "X" COLOR_RESET);
            } else {
                printf(COLOR_PATH " " COLOR_RESET);
            }
        }
        printf("\n");
    }
}

int main()
{
    int maze[HEIGHT][WIDTH];
    srand(time(NULL));
    generate_maze(maze);
    display_maze(maze);
    return 0;
}