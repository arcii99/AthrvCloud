//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 15

int count = 0;

typedef enum {
    EMPTY = ' ',
    BLOCK = 'X',
    PATH  = '|',
    USED  = '.'
} MAZE_TYPE;

typedef struct _maze {
    MAZE_TYPE type;
} MAZE;

void init_maze(MAZE maze[MAZE_SIZE][MAZE_SIZE]) {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            maze[i][j].type = BLOCK;
        }
    }
}

void print_maze(MAZE maze[MAZE_SIZE][MAZE_SIZE]) {
    int i, j;
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j].type);
        }
        printf("\n");
    }
}

int get_direction(int current, int last) {
    int next;
    switch (current) {
        case 0:
            if (last == 1) {
                next = 3;
            } else {
                next = last == 2 ? 3 : rand() % 4;
            }
            break;
        case 1:
            if (last == 0) {
                next = 2;
            } else {
                next = last == 3 ? 2 : rand() % 4;
            }
            break;
        case 2:
            if (last == 3) {
                next = 1;
            } else {
                next = last == 0 ? 1 : rand() % 4;
            }
            break;
        case 3:
            if (last == 2) {
                next = 0;
            } else {
                next = last == 1 ? 0 : rand() % 4;
            }
            break;
    }
    return next;
}

void generate_maze(MAZE maze[MAZE_SIZE][MAZE_SIZE]) {
    int x = 2, y = 2;
    int last_direction = -1;
    while (maze[x][y-1].type != EMPTY || maze[x][y+1].type != EMPTY
        || maze[x-1][y].type != EMPTY || maze[x+1][y].type != EMPTY) {
        int direction;
        do {
            direction = rand() % 4;
        } while (direction == last_direction);
        int next_direction = get_direction(direction, last_direction);
        switch (next_direction) {
            case 0:
                if (y > 1 && maze[x][y-2].type == BLOCK) {
                    maze[x][--y].type = EMPTY;
                    maze[x][--y].type = EMPTY;
                    last_direction = next_direction;
                    count++;
                }
                break;
            case 1:
                if (x < MAZE_SIZE-2 && maze[x+2][y].type == BLOCK) {
                    maze[++x][y].type = EMPTY;
                    maze[++x][y].type = EMPTY;
                    last_direction = next_direction;
                    count++;
                }
                break;
            case 2:
                if (y < MAZE_SIZE-2 && maze[x][y+2].type == BLOCK) {
                    maze[x][++y].type = EMPTY;
                    maze[x][++y].type = EMPTY;
                    last_direction = next_direction;
                    count++;
                }
                break;
            case 3:
                if (x > 1 && maze[x-2][y].type == BLOCK) {
                    maze[--x][y].type = EMPTY;
                    maze[--x][y].type = EMPTY;
                    last_direction = next_direction;
                    count++;
                }
                break;
        }
    }
    maze[1][2].type = EMPTY;
    maze[MAZE_SIZE-2][MAZE_SIZE-3].type = EMPTY;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    MAZE maze[MAZE_SIZE][MAZE_SIZE];
    init_maze(maze);
    generate_maze(maze);
    print_maze(maze);
    printf("\nTotal Number of Empty Spaces: %d\n", count);
    return 0;
}