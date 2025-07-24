//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct coord {
    int row;
    int col;
} coord;

void create_maze(int maze[ROWS][COLS]);
void print_maze(int maze[ROWS][COLS]);
coord get_starting_point(int maze[ROWS][COLS]);
int is_dead_end(int row, int col, int maze[ROWS][COLS]);
int get_random_direction(int row, int col, int maze[ROWS][COLS]);
void carve_path(int row, int col, int direction, int maze[ROWS][COLS]);

int main() {
    srand(time(0));
    
    int maze[ROWS][COLS];
    create_maze(maze);
    print_maze(maze);
    
    return 0;
}

void create_maze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maze[i][j] = 1;
        }
    }
    
    coord starting_point = get_starting_point(maze);
    maze[starting_point.row][starting_point.col] = 0;
    
    int row = starting_point.row;
    int col = starting_point.col;
    int direction;
    
    while (!is_dead_end(row, col, maze)) {
        direction = get_random_direction(row, col, maze);
        carve_path(row, col, direction, maze);
        row += (direction == 1) ? -1 : (direction == 2) ? 1 : 0;
        col += (direction == 3) ? -1 : (direction == 4) ? 1 : 0;
    }
}

void print_maze(int maze[ROWS][COLS]) {
    printf(" ");
    for (int i = 0; i < COLS; ++i) {
        printf("__ ");
    }
    printf("\n");
    
    for (int i = 0; i < ROWS; ++i) {
        printf("|");
        for (int j = 0; j < COLS; ++j) {
            if (maze[i][j] == 0) {
                printf("  |");
            } else {
                printf("__|");
            }
        }
        printf("\n");
    }
}

coord get_starting_point(int maze[ROWS][COLS]) {
    coord starting_point;
    starting_point.row = rand() % ROWS;
    starting_point.col = rand() % COLS;
    
    while (is_dead_end(starting_point.row, starting_point.col, maze)) {
        starting_point.row = rand() % ROWS;
        starting_point.col = rand() % COLS;
    }
    
    return starting_point;
}

int is_dead_end(int row, int col, int maze[ROWS][COLS]) {
    int dead_ends = 0;
    if (row > 0 && maze[row-1][col] == 1) {
        ++dead_ends;
    }
    if (row < ROWS-1 && maze[row+1][col] == 1) {
        ++dead_ends;
    }
    if (col > 0 && maze[row][col-1] == 1) {
        ++dead_ends;
    }
    if (col < COLS-1 && maze[row][col+1] == 1) {
        ++dead_ends;
    }
    return (dead_ends <= 1) ? 1 : 0;
}

int get_random_direction(int row, int col, int maze[ROWS][COLS]) {
    int direction;
    do {
        direction = rand() % 4 + 1;
    } while ((direction == 1 && (row == 0 || maze[row-1][col] == 0)) || 
            (direction == 2 && (row == ROWS-1 || maze[row+1][col] == 0)) ||
            (direction == 3 && (col == 0 || maze[row][col-1] == 0)) ||
            (direction == 4 && (col == COLS-1 || maze[row][col+1] == 0)));
    return direction;
}

void carve_path(int row, int col, int direction, int maze[ROWS][COLS]) {
    if (direction == 1) {
        maze[row-1][col] = 0;
    } else if (direction == 2) {
        maze[row+1][col] = 0;
    } else if (direction == 3) {
        maze[row][col-1] = 0;
    } else if (direction == 4) {
        maze[row][col+1] = 0;
    }
}