//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL 0
#define PATH 1
#define VISITED 2

int maze[MAZE_SIZE][MAZE_SIZE];
int start_x, start_y, end_x, end_y;

void generate_maze();
void print_maze();
int find_exit(int x, int y);

int main()
{
    srand(time(NULL));
    generate_maze();
    print_maze();
    if (find_exit(start_x, start_y)) {
        printf("Exit found at (%d,%d)\n", end_x, end_y);
    } else {
        printf("No exit found.\n");
    }
    return 0;
}

void generate_maze()
{
    int i, j;
    // Initialize maze with all walls
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL;
        }
    }
    // Select random starting point
    start_x = rand() % MAZE_SIZE;
    start_y = rand() % MAZE_SIZE;
    // Set starting point as path
    maze[start_x][start_y] = PATH;
    // Generate maze recursively
    // TODO: Implement recursive maze generation algorithm
}

void print_maze()
{
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            switch (maze[i][j]) {
                case WALL:
                    printf("█");
                    break;
                case PATH:
                    printf(" ");
                    break;
                case VISITED:
                    printf(".");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

int find_exit(int x, int y)
{
    // Mark current location as visited
    maze[x][y] = VISITED;
    // Look for exit in adjacent cells
    int found_exit = 0;
    if (x > 0 && maze[x-1][y] == PATH) {
        found_exit = find_exit(x-1, y);
    }
    if (x < MAZE_SIZE-1 && maze[x+1][y] == PATH && !found_exit) {
        found_exit = find_exit(x+1, y);
    }
    if (y > 0 && maze[x][y-1] == PATH && !found_exit) {
        found_exit = find_exit(x, y-1);
    }
    if (y < MAZE_SIZE-1 && maze[x][y+1] == PATH && !found_exit) {
        found_exit = find_exit(x, y+1);
    }
    if (found_exit) {
        end_x = x;
        end_y = y;
    }
    return found_exit;
}