//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

typedef struct {
    int row;
    int col;
} point_t;

point_t start = {1, 1};
point_t end = {7, 8};

void print_maze() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int find_route(point_t p) {
    if(p.row == end.row && p.col == end.col) {
        return 1;
    }
    
    if(maze[p.row][p.col] == '*') {
        return 0;
    }
    
    maze[p.row][p.col] = 'x';
    
    point_t north = {p.row - 1, p.col};
    point_t east = {p.row, p.col + 1};
    point_t south = {p.row + 1, p.col};
    point_t west = {p.row, p.col - 1};
    
    if(find_route(north)) {
        return 1;
    }
    if(find_route(east)) {
        return 1;
    }
    if(find_route(south)) {
        return 1;
    }
    if(find_route(west)) {
        return 1;
    }
    
    maze[p.row][p.col] = ' ';
    return 0;
}

int main() {
    printf("Starting maze:\n");
    print_maze();
    
    if(find_route(start)) {
        printf("Solution found!\n");
    } else {
        printf("No solution!\n");
    }
    
    printf("Final maze:\n");
    print_maze();
    
    return 0;
}