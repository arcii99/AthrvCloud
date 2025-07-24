//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

typedef struct Cell {
    int row;
    int col;
    int visited;
    int walls[4];
} Cell;

void init_cell(Cell *cell, int row, int col) {
    cell->row = row;
    cell->col = col;
    cell->visited = 0;
    cell->walls[0] = 1;
    cell->walls[1] = 1;
    cell->walls[2] = 1;
    cell->walls[3] = 1;
}

void print_maze(Cell maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("+");
            if (maze[i][j].walls[0])
                printf("--");
            else
                printf("  ");
        }
        printf("+\n");

        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].walls[3])
                printf("|  ");
            else
                printf("   ");
        }
        if (maze[i][COLS-1].walls[1])
            printf("|\n");
        else
            printf(" \n");
    }

    for (int j = 0; j < COLS; j++) {
        printf("+-");
    }
    printf("+\n");
}

void generate_maze(Cell maze[ROWS][COLS], int start_row, int start_col) {
    Cell *current = &maze[start_row][start_col];
    current->visited = 1;

    int num_visited = 1;
    int i, j, next_row, next_col;

    while (num_visited < ROWS * COLS) {
        i = current->row;
        j = current->col;

        int neighbors[4][2] = {{i-1,j},{i,j+1},{i+1,j},{i,j-1}};
        int num_neighbors = 4;

        while (num_neighbors > 0) {
            int r = rand() % num_neighbors;
            next_row = neighbors[r][0];
            next_col = neighbors[r][1];

            if (next_row < 0 || next_col < 0 ||
                next_row >= ROWS || next_col >= COLS ||
                maze[next_row][next_col].visited) {
                neighbors[r][0] = neighbors[num_neighbors-1][0];
                neighbors[r][1] = neighbors[num_neighbors-1][1];
                num_neighbors--;
                continue;
            } else {
                break;
            }
        }

        if (num_neighbors > 0) {
            if (next_row < i)
                current->walls[0] = 0;
            else if (next_col > j)
                current->walls[1] = 0;
            else if (next_row > i)
                current->walls[2] = 0;
            else
                current->walls[3] = 0;

            current = &maze[next_row][next_col];
            current->visited = 1;
            num_visited++;
        }
    }
}

int main() {
    Cell maze[ROWS][COLS];

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            init_cell(&maze[i][j], i, j);
        }
    }

    generate_maze(maze, 0, 0);

    printf("Generated Maze:\n");
    print_maze(maze);

    return 0;
}