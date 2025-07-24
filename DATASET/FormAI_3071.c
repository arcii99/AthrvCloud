//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

int start[2] = {0, 0};
int end[2] = {ROWS-1, COLS-1};
int path[ROWS][COLS] = {0};

void print_maze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void find_route(int x, int y) {
    if(x == end[0] && y == end[1]) {
        path[x][y] = 1;
        printf("Success! Path found.\n");
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if(maze[x][y] == 0 && path[x][y] == 0) {
        path[x][y] = 1;
        if(x != 0) {
            find_route(x-1, y);
        }
        if(y != 0) {
            find_route(x, y-1);
        }
        if(x != ROWS-1) {
            find_route(x+1, y);
        }
        if(y != COLS-1) {
            find_route(x, y+1);
        }
        path[x][y] = 0;
    }
}

int main() {
    printf("Welcome to Maze Route Finder!\n");
    printf("Starting position is (%d,%d) and ending position is (%d,%d)\n", start[0], start[1], end[0], end[1]);
    print_maze();
    printf("Finding route...\n");
    find_route(start[0], start[1]);
    printf("Sorry, unable to find a path.\n");
    return 0;
}