//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 11
#define COLUMN 11

int maze[ROW][COLUMN];

void create_maze(int row, int column);
void print_maze();
void generate_maze(int row, int column);
int available_directions(int row, int column);
void visit(int row, int column, int direction);

int main() {
    srand(time(NULL));
    create_maze(ROW, COLUMN);
    generate_maze(1, 1);
    print_maze();
}

void create_maze(int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || j == 0 || i == row - 1 || j == column - 1) {
                maze[i][j] = -1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
}

void print_maze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (maze[i][j] == -1) {
                printf("█");
            } else if (maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void generate_maze(int row, int column) {
    maze[row][column] = 1;
    visit(row, column, -1);
}

int available_directions(int row, int column) {
    int directions = 0;
    
    if (maze[row - 1][column] == 0) {
        directions++;
    }
    
    if (maze[row + 1][column] == 0) {
        directions++;
    }
    
    if (maze[row][column - 1] == 0) {
        directions++;
    }
    
    if (maze[row][column + 1] == 0) {
        directions++;
    }
    
    return directions;
}

void visit(int row, int column, int direction) {
    int directions = available_directions(row, column);
    
    if (directions == 0) {
        return;
    }
    
    int random_direction = rand() % 4;
    
    while (random_direction == direction || maze[row + (random_direction == 1) - (random_direction == 0)][column + (random_direction == 3) - (random_direction == 2)] == 1) {
        random_direction = rand() % 4;
    }
    
    switch(random_direction) {
        case 0:
            maze[row - 1][column] = 1;
            visit(row - 1, column, 2);
            break;
        case 1:
            maze[row + 1][column] = 1;
            visit(row + 1, column, 3);
            break;
        case 2:
            maze[row][column - 1] = 1;
            visit(row, column - 1, 0);
            break;
        case 3:
            maze[row][column + 1] = 1;
            visit(row, column + 1, 1);
            break;
    }
}