//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define WALL '#'
#define PASSAGE ' '

enum { UP, RIGHT, DOWN, LEFT };

typedef unsigned char byte;

// A cell in the maze
typedef struct {
    byte row, col;
    byte visited;
    byte walls[4];
} Cell;

// Initialize the maze
void initialize(Cell cells[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j].row = i;
            cells[i][j].col = j;
            cells[i][j].visited = 0;
            cells[i][j].walls[UP] = 1;
            cells[i][j].walls[RIGHT] = 1;
            cells[i][j].walls[DOWN] = 1;
            cells[i][j].walls[LEFT] = 1;
        }
    }
}

// Check if a cell is valid
int is_valid(Cell cells[][COLS], byte row, byte col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && !cells[row][col].visited;
}

// Get a random adjacent cell
void get_random_adjacent(Cell cells[][COLS], byte row, byte col, byte* adj_row, byte* adj_col) {
    int direction;
    do {
        direction = rand() % 4;
        switch (direction) {
        case UP:
            *adj_row = row - 1;
            *adj_col = col;
            break;
        case RIGHT:
            *adj_row = row;
            *adj_col = col + 1;
            break;
        case DOWN:
            *adj_row = row + 1;
            *adj_col = col;
            break;
        case LEFT:
            *adj_row = row;
            *adj_col = col - 1;
            break;
        }
    } while (!is_valid(cells, *adj_row, *adj_col));
}

// Remove wall between two cells
void remove_wall(Cell cells[][COLS], byte row1, byte col1, byte row2, byte col2) {
    if (row1 == row2) {
        if (col1 < col2) {
            cells[row1][col1].walls[RIGHT] = 0;
            cells[row2][col2].walls[LEFT] = 0;
        } else {
            cells[row1][col1].walls[LEFT] = 0;
            cells[row2][col2].walls[RIGHT] = 0;
        }
    } else {
        if (row1 < row2) {
            cells[row1][col1].walls[DOWN] = 0;
            cells[row2][col2].walls[UP] = 0;
        } else {
            cells[row1][col1].walls[UP] = 0;
            cells[row2][col2].walls[DOWN] = 0;
        }
    }
}

// Generate the maze using depth-first search algorithm
void generate_maze(Cell cells[][COLS], byte row, byte col) {
    cells[row][col].visited = 1;
    byte adj_row, adj_col;
    get_random_adjacent(cells, row, col, &adj_row, &adj_col);
    while (adj_row != row || adj_col != col) {
        remove_wall(cells, row, col, adj_row, adj_col);
        generate_maze(cells, adj_row, adj_col);
        get_random_adjacent(cells, row, col, &adj_row, &adj_col);
    }
}

// Print the maze
void print_maze(Cell cells[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", cells[i][j].walls[UP] ? WALL : PASSAGE);
            printf("%c", cells[i][j].walls[RIGHT] ? WALL : PASSAGE);
        }
        printf("%c\n", WALL);
        for (int j = 0; j < COLS; j++) {
            printf("%c%c", cells[i][j].walls[LEFT] ? WALL : PASSAGE, PASSAGE);
        }
        printf("%c\n", cells[i][COLS - 1].walls[RIGHT] ? WALL : PASSAGE);
    }
    for (int j = 0; j < COLS; j++) {
        printf("%c%c", WALL, WALL);
    }
    printf("%c\n", WALL);
}

int main() {
    srand(time(NULL));
    Cell cells[ROWS][COLS];
    initialize(cells);
    generate_maze(cells, 0, 0);
    print_maze(cells);
    return 0;
}