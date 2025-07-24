//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

enum Directions {NORTH, EAST, SOUTH, WEST};

typedef struct cell {
    int north, east, south, west;
    int visited;
} cell;

void init_maze(cell maze[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j].north = 1;
            maze[i][j].east = 1;
            maze[i][j].south = 1;
            maze[i][j].west = 1;
            maze[i][j].visited = 0;
        }
    }
}

int check_neighbors(cell maze[MAZE_SIZE][MAZE_SIZE], int row, int col) {
    int neighbors[4];
    int count = 0;

    if (row > 0 && !maze[row - 1][col].visited) {
        neighbors[count++] = NORTH;
    }

    if (col < MAZE_SIZE - 1 && !maze[row][col + 1].visited) {
        neighbors[count++] = EAST;
    }

    if (row < MAZE_SIZE - 1 && !maze[row + 1][col].visited) {
        neighbors[count++] = SOUTH;
    }

    if (col > 0 && !maze[row][col - 1].visited) {
        neighbors[count++] = WEST;
    }

    if (count == 0) {
        return -1;
    }

    return neighbors[rand() % count];
}

void remove_wall(cell maze[MAZE_SIZE][MAZE_SIZE], int row, int col, int direction) {
    switch (direction) {
        case NORTH:
            maze[row][col].north = 0;
            maze[row - 1][col].south = 0;
            break;
        case EAST:
            maze[row][col].east = 0;
            maze[row][col + 1].west = 0;
            break;
        case SOUTH:
            maze[row][col].south = 0;
            maze[row + 1][col].north = 0;
            break;
        case WEST:
            maze[row][col].west = 0;
            maze[row][col - 1].east = 0;
            break;
    }
}

void generate_maze(cell maze[MAZE_SIZE][MAZE_SIZE]) {
    int current_row = rand() % MAZE_SIZE;
    int current_col = rand() % MAZE_SIZE;
    maze[current_row][current_col].visited = 1;

    int unvisited_cells = MAZE_SIZE * MAZE_SIZE - 1;

    while (unvisited_cells > 0) {
        int direction = check_neighbors(maze, current_row, current_col);
        if (direction < 0) {
            int i, j;
            do {
                i = rand() % MAZE_SIZE;
                j = rand() % MAZE_SIZE;
            } while (maze[i][j].visited);

            current_row = i;
            current_col = j;
            maze[current_row][current_col].visited = 1;
            unvisited_cells--;
        } else {
            remove_wall(maze, current_row, current_col, direction);

            switch (direction) {
                case NORTH:
                    current_row--;
                    break;
                case EAST:
                    current_col++;
                    break;
                case SOUTH:
                    current_row++;
                    break;
                case WEST:
                    current_col--;
                    break;
            }

            maze[current_row][current_col].visited = 1;
            unvisited_cells--;
        }
    }
}

void print_maze(cell maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("+");
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < MAZE_SIZE; i++) {
        printf("|");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j].south == 1) {
                printf("   |");
            } else {
                printf("    ");
            }
        }
        printf("\n+");
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j].east == 1) {
                printf("---+");
            } else {
                printf("   +");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    cell maze[MAZE_SIZE][MAZE_SIZE];
    init_maze(maze);
    generate_maze(maze);
    print_maze(maze);

    return 0;
}