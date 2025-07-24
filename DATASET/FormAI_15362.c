//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_DIM 10 // Change this to set the dimension of the maze
#define WALL '#'
#define SPACE ' '

typedef struct {
    int x;
    int y;
} Position;

char maze[MAZE_DIM][MAZE_DIM];

int rand_int(int min, int max)
{
    static int seed_set = 0;
    if (!seed_set) {
        srand(time(NULL));
        seed_set = 1;
    }
    return (rand() % (max - min + 1)) + min;
}

void print_maze(void)
{
    for (int i = 0; i < MAZE_DIM; i++) {
        for (int j = 0; j < MAZE_DIM; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(void)
{
    // Set all cells to be walls first
    for (int i = 0; i < MAZE_DIM; i++) {
        for (int j = 0; j < MAZE_DIM; j++) {
            maze[i][j] = WALL;
        }
    }

    // Generate starting and ending positions
    Position start = {0, 0};
    Position end = {MAZE_DIM-1, MAZE_DIM-1};

    // Place dots
    maze[start.x][start.y] = '.';
    maze[end.x][end.y] = '.';

    // Generate random path
    Position curr_pos = start;
    while (curr_pos.x != end.x || curr_pos.y != end.y) {
        int dir = rand_int(0, 3); // 0 = upward, 1 = rightward, 2 = downward, 3 = leftward
        Position next_pos = curr_pos;
        switch (dir) {
            case 0:
                if (curr_pos.x > 0) {
                    next_pos.x--;
                }
                break;
            case 1:
                if (curr_pos.y < MAZE_DIM-1) {
                    next_pos.y++;
                }
                break;
            case 2:
                if (curr_pos.x < MAZE_DIM-1) {
                    next_pos.x++;
                }
                break;
            case 3:
                if (curr_pos.y > 0) {
                    next_pos.y--;
                }
                break;
        }
        if (maze[next_pos.x][next_pos.y] == WALL) { // check if the next position is a wall
            maze[next_pos.x][next_pos.y] = SPACE;
            curr_pos = next_pos;
        }
    }
}

int main(void)
{
    generate_maze();
    print_maze();
    return 0;
}