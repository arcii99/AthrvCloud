//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

void initialize_maze(int maze[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            maze[i][j] = 1;
        }
    }
}

void generate_maze(int maze[ROWS][COLUMNS]) {
    srand(time(NULL));
    int row, column;
    row = rand() % ROWS;
    column = rand() % COLUMNS;
    maze[row][column] = 0;
    
    while (maze[ROWS-1][COLUMNS-1] == 1) {
        if (row == 0 && column == 0) {
            int direction = rand() % 2;
            if (direction == 0 && column != COLUMNS-1) {
                column++;
            } else if (direction == 1 && row != ROWS-1) {
                row++;
            }
        } else if (row == ROWS-1 && column == COLUMNS-1) {
            int direction = rand() % 2;
            if (direction == 0 && column != 0) {
                column--;
            } else if (direction == 1 && row != 0) {
                row--;
            }
        } else if (row == 0) {
            int direction = rand() % 3;
            if (direction == 0 && column != COLUMNS-1) {
                column++;
            } else if (direction == 1) {
                row++;
            } else if (direction == 2 && column != 0) {
                column--;
            }
        } else if (column == 0) {
            int direction = rand() % 3;
            if (direction == 0) {
                column++;
            } else if (direction == 1 && row != ROWS-1) {
                row++;
            } else if (direction == 2 && row != 0) {
                row--;
            }
        } else if (row == ROWS-1) {
            int direction = rand() % 3;
            if (direction == 0 && column != COLUMNS-1) {
                column++;
            } else if (direction == 1 && column != 0) {
                column--;
            } else if (direction == 2) {
                row--;
            }
        } else if (column == COLUMNS-1) {
            int direction = rand() % 3;
            if (direction == 0 && row != ROWS-1) {
                row++;
            } else if (direction == 1 && row != 0) {
                row--;
            } else if (direction == 2) {
                column--;
            }
        } else {
            int direction = rand() % 4;
            if (direction == 0 && column != COLUMNS-1) {
                column++;
            } else if (direction == 1 && row != ROWS-1) {
                row++;
            } else if (direction == 2 && column != 0) {
                column--;
            } else if (direction == 3 && row != 0) {
                row--;
            }
        }
        maze[row][column] = 0;
    }
    
    maze[0][0] = 0;
    maze[ROWS-1][COLUMNS-1] = 0;
}

void print_maze(int maze[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("%c", 219);
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLUMNS];
    initialize_maze(maze);
    generate_maze(maze);
    print_maze(maze);
    
    return 0;
}