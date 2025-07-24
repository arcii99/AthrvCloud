//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 10

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','S','#','.','.','.','#','.','.','#'},
    {'#','.','#','.','#','.','#','#','.','#'},
    {'#','.','#','.','#','.','.','.','.','#'},
    {'#','.','.','.','.','#','#','#','.','#'},
    {'#','#','#','#','#','#','.','#','.','#'},
    {'#','.','.','.','.','.','.','#','F','#'},
};

typedef struct {
    int row, col;
} Point;

void print_maze(Point cursor) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cursor.row == i && cursor.col == j) {
                printf("P");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

bool valid_pos(Point pos) {
    if (pos.row < 0 || pos.row >= ROWS || pos.col < 0 || pos.col >= COLS) {
        return false;
    }
    
    if (maze[pos.row][pos.col] == '#') {
        return false;
    }
    
    return true;
}

bool solve_maze(Point cursor) {
    if (maze[cursor.row][cursor.col] == 'F') {
        print_maze(cursor);
        return true;
    }
    
    Point right = {cursor.row, cursor.col + 1};
    if (valid_pos(right)) {
        maze[cursor.row][cursor.col] = '#';
        if (solve_maze(right)) {
            return true;
        }
        maze[cursor.row][cursor.col] = '.';
    }
    
    Point down = {cursor.row + 1, cursor.col};
    if (valid_pos(down)) {
        maze[cursor.row][cursor.col] = '#';
        if (solve_maze(down)) {
            return true;
        }
        maze[cursor.row][cursor.col] = '.';
    }
    
    Point left = {cursor.row, cursor.col - 1};
    if (valid_pos(left)) {
        maze[cursor.row][cursor.col] = '#';
        if (solve_maze(left)) {
            return true;
        }
        maze[cursor.row][cursor.col] = '.';
    }
    
    Point up = {cursor.row - 1, cursor.col};
    if (valid_pos(up)) {
        maze[cursor.row][cursor.col] = '#';
        if (solve_maze(up)) {
            return true;
        }
        maze[cursor.row][cursor.col] = '.';
    }
    
    return false;
}

int main() {
    Point start = {1, 1};
    solve_maze(start);
}