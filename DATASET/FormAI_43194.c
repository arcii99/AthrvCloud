//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

enum direction {EMPTY, UP, RIGHT, DOWN, LEFT};

struct cell {
    int row;
    int col;
    int visited;
    int walls[4];
};

struct maze {
    struct cell cells[MAX_ROWS][MAX_COLS];
};

void initialize_maze(struct maze *maze);
void print_maze(struct maze maze);
void generate_maze(struct maze *maze, int start_row, int start_col);
int check_visited_neighbors(struct cell cell, struct maze maze);
void remove_wall(struct cell *cell1, struct cell *cell2);
int is_valid_move(struct cell cell, struct maze maze, int direction);
void move_cell(struct cell *cell, int direction);

int main() {
    struct maze maze;
    initialize_maze(&maze);
    generate_maze(&maze, 0, 0);
    print_maze(maze);
    return 0;
}

/*
 * Sets up walls and default values for each cell in the maze
 */
void initialize_maze(struct maze *maze) {
    for(int row=0; row<MAX_ROWS; row++) {
        for(int col=0; col<MAX_COLS; col++) {
            maze->cells[row][col].row = row;
            maze->cells[row][col].col = col;
            maze->cells[row][col].visited = 0;
            for(int i=0; i<4; i++) {
                maze->cells[row][col].walls[i] = 1;
            }
        }
    }
}

/*
 * Prints out the maze to the console
 */
void print_maze(struct maze maze) {
    for(int row=0; row<MAX_ROWS; row++) {
        for(int col=0; col<MAX_COLS; col++) {
            if(maze.cells[row][col].walls[UP]) {
                printf(" _");
            } else {
                printf("  ");
            }
        }
        printf("\n");
        for(int col=0; col<MAX_COLS; col++) {
            if(maze.cells[row][col].walls[LEFT]) {
                printf("|");
            } else {
                printf(" ");
            }
            if(maze.cells[row][col].visited) {
                printf(" ");
            } else {
                printf("_");
            }
            if(col == MAX_COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
    }
}

/*
 * Generates the maze starting from the given cell
 * Uses depth first search algorithm to generate the maze
 */
void generate_maze(struct maze *maze, int start_row, int start_col) {
    struct cell *current = &(maze->cells[start_row][start_col]);
    current->visited = 1;
    while(check_visited_neighbors(*current, *maze) != -1) {
        int next_index = check_visited_neighbors(*current, *maze);
        struct cell *next = &(maze->cells[current->row + (next_index == UP ? -1 : (next_index == DOWN ? 1 : 0))]
                                         [current->col + (next_index == LEFT ? -1 : (next_index == RIGHT ? 1 : 0))]);
        remove_wall(current, next);
        generate_maze(maze, next->row, next->col);
        current = next;
        current->visited = 1;
    }
}

/*
 * Checks for neighboring cells of a given cell that have been visited
 * Returns a direction code representing the direction of the visited cell, or -1 if no visited cell was found
 */
int check_visited_neighbors(struct cell cell, struct maze maze) {
    int directions[4] = {UP, RIGHT, DOWN, LEFT};
    srand(time(NULL)); // for random number generation
    while(1) {
        int rand_index = rand() % 4;
        if(is_valid_move(cell, maze, directions[rand_index])
                && maze.cells[cell.row + (directions[rand_index] == UP ? -1 : (directions[rand_index] == DOWN ? 1 : 0))]
                          [cell.col + (directions[rand_index] == LEFT ? -1 : (directions[rand_index] == RIGHT ? 1 : 0))].visited == 0) {
            return directions[rand_index];
        } else if(maze.cells[cell.row + (directions[rand_index] == UP ? -1 : (directions[rand_index] == DOWN ? 1 : 0))]
                                 [cell.col + (directions[rand_index] == LEFT ? -1 : (directions[rand_index] == RIGHT ? 1 : 0))].visited == 1
                  && rand_index == 3) { // if we have looped through all directions and found no unvisited neighbors
            return -1;
        }
    }
}

/*
 * Removes the wall between two adjacent cells
 */
void remove_wall(struct cell *cell1, struct cell *cell2) {
    int row_diff = cell1->row - cell2->row;
    int col_diff = cell1->col - cell2->col;
    if(row_diff == 1) { // cell1 is below cell2
        cell1->walls[UP] = 0;
        cell2->walls[DOWN] = 0;
    } else if(row_diff == -1) { // cell1 is above cell2
        cell1->walls[DOWN] = 0;
        cell2->walls[UP] = 0;
    } else if(col_diff == 1) { // cell1 is to the right of cell2
        cell1->walls[LEFT] = 0;
        cell2->walls[RIGHT] = 0;
    } else if(col_diff == -1) { // cell1 is to the left of cell2
        cell1->walls[RIGHT] = 0;
        cell2->walls[LEFT] = 0;
    }
}

/*
 * Checks if a given move in a direction is valid
 */
int is_valid_move(struct cell cell, struct maze maze, int direction) {
    if(direction == UP && cell.row > 0) {
        return 1;
    } else if(direction == RIGHT && cell.col < MAX_COLS - 1) {
        return 1;
    } else if(direction == DOWN && cell.row < MAX_ROWS - 1) {
        return 1;
    } else if(direction == LEFT && cell.col > 0) {
        return 1;
    }
    return 0;
}

/*
 * Moves a given cell in a direction
 * Does not perform any error checking
 */
void move_cell(struct cell *cell, int direction) {
    if(direction == UP) {
        cell->row -= 1;
    } else if(direction == RIGHT) {
        cell->col += 1;
    } else if(direction == DOWN) {
        cell->row += 1;
    } else if(direction == LEFT) {
        cell->col -= 1;
    }
}