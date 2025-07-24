//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 10     //define number of rows
#define COLS 10     //define number of columns

struct Cell {
    bool top_wall, bottom_wall, left_wall, right_wall;        //define walls for the cell
    bool visited;
};

typedef struct Cell Cell;

Cell create_cell() {
    Cell new_cell = {
        .top_wall=true,                       //initialize all walls to true
        .bottom_wall=true,
        .left_wall=true,
        .right_wall=true,
        .visited=false                        //initialize visited to false
    };
    return new_cell;
}

void print_maze(Cell maze[ROWS][COLS]) {      //function to print maze
    printf(" ");
    for (int i=0; i<COLS; ++i) {
        printf("_ ");
    }
    printf("\n");

    for (int i=0; i<ROWS; ++i) {
        printf("|");
        for (int j=0; j<COLS; ++j) {
            if (maze[i][j].bottom_wall) {
                printf("_");
            } else {
                printf(" ");
            }

            if (maze[i][j].right_wall) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void remove_wall(Cell* current_cell, Cell* next_cell) {       //function to remove wall between two cells
    if (current_cell->top_wall && current_cell->top_wall == next_cell->bottom_wall) {
        current_cell->top_wall = false;
        next_cell->bottom_wall = false;
    } else if (current_cell->right_wall && current_cell->right_wall == next_cell->left_wall) {
        current_cell->right_wall = false;
        next_cell->left_wall = false;
    } else if (current_cell->bottom_wall && current_cell->bottom_wall == next_cell->top_wall) {
        current_cell->bottom_wall = false;
        next_cell->top_wall = false;
    } else if (current_cell->left_wall && current_cell->left_wall == next_cell->right_wall) {
        current_cell->left_wall = false;
        next_cell->right_wall = false;
    }
}

bool check_neighbours_visited(Cell maze[ROWS][COLS], int row, int col) {   //function to check if all neighbors are visited
    if (row > 0 && !maze[row-1][col].visited) {
        return false;
    }
    if (row < ROWS-1 && !maze[row+1][col].visited) {
        return false;
    }
    if (col > 0 && !maze[row][col-1].visited) {
        return false;
    }
    if (col < COLS-1 && !maze[row][col+1].visited) {
        return false;
    }
    return true;
}

void generate_maze(Cell maze[ROWS][COLS], int start_row, int start_col) {   //function to generate maze recursively
    maze[start_row][start_col].visited = true;

    while(!check_neighbours_visited(maze, start_row, start_col)) {
        int rand_num = rand() % 4;
        int new_row = start_row;
        int new_col = start_col;

        if (rand_num == 0 && start_row > 0) {
            new_row=start_row-1;
        } else if (rand_num == 1 && start_row < ROWS-1) {
            new_row=start_row+1;
        } else if (rand_num == 2 && start_col > 0) {
            new_col=start_col-1;
        } else if (rand_num == 3 && start_col < COLS-1) {
            new_col=start_col+1;
        }

        if (!maze[new_row][new_col].visited) {
            remove_wall(&maze[start_row][start_col], &maze[new_row][new_col]);
            generate_maze(maze, new_row, new_col);
        }
    }
}

int main() {
    srand(0);      //set random seed
    Cell maze[ROWS][COLS];
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j) {
            maze[i][j] = create_cell();
        }
    }
    generate_maze(maze, 0, 0);   //start generating maze from top-left corner
    print_maze(maze);            //print generated maze
    return 0;
}