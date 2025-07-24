//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

typedef struct {
    int x, y;
} Point;

char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '.', '#', '#'},
    {'#', '#', '#', '.', '.', '.', '#', '#', '#', '#'},
    {'#', '.', '.', '#', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '.', '#', '#', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

bool is_valid_move(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLUMNS && maze[x][y] != '#';
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void find_route(Point start, Point end, char moves[]) {
    if (start.x == end.x && start.y == end.y) {
        printf("Reached the end!\nMoves: %s\n", moves);
    } else {
        if (is_valid_move(start.x+1, start.y)) {
            moves[strlen(moves)] = 'D';
            Point next = {start.x+1, start.y};
            find_route(next, end, moves);
            moves[strlen(moves)-1] = '\0';
        }
        if (is_valid_move(start.x-1, start.y)) {
            moves[strlen(moves)] = 'U';
            Point next = {start.x-1, start.y};
            find_route(next, end, moves);
            moves[strlen(moves)-1] = '\0';
        }
        if (is_valid_move(start.x, start.y+1)) {
            moves[strlen(moves)] = 'R';
            Point next = {start.x, start.y+1};
            find_route(next, end, moves);
            moves[strlen(moves)-1] = '\0';
        }
        if (is_valid_move(start.x, start.y-1)) {
            moves[strlen(moves)] = 'L';
            Point next = {start.x, start.y-1};
            find_route(next, end, moves);
            moves[strlen(moves)-1] = '\0';
        }
    }
}

int main() {
    Point start = {1, 1};
    Point end = {8, 8};
    char moves[ROWS*COLUMNS];
    moves[0] = '\0';
    
    print_maze();
    
    printf("\nFinding route...\n");
    find_route(start, end, moves);
    
    return 0;
}