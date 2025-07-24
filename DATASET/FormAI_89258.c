//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 

#define ROWS 10
#define COLUMNS 20

char maze[ROWS][COLUMNS+1] = {
    "+----------------------+",
    "|                      |",
    "| +--+  +-----+  +--+  |",
    "| |     |     |  |  |  |",
    "| |     |     |  +--+  |",
    "| |     |     |         |",
    "| +--+  +-----+  +--+  |",
    "|     |  |        |  |  |",
    "|     |  |        |  |  |",
    "+-----+  +--------+  +--+"
};

struct Vector2 {

    int x;
    int y;

} start, end;

int visited[ROWS][COLUMNS] = { 0 };

int search(int x, int y) {

    if (visited[x][y] == 1) {
        return 0;
    }

    visited[x][y] = 1;

    if (maze[x][y] == '+') { 
        return 0; 
    }

    if (maze[x][y] == '|') {
        return 0; 
    }

    if (maze[x][y] == '-') {
        return 0; 
    }

    if (x == end.x && y == end.y) {
        return 1; 
    }

    if (search(x+1, y) == 1) {
        printf("[%d,%d]\n", x, y);
        return 1;
    }

    if (search(x, y+1) == 1) {
        printf("[%d,%d]\n", x, y);
        return 1; 
    }

    if (search(x-1, y) == 1) {
        printf("[%d,%d]\n", x, y);
        return 1; 
    }

    if (search(x, y-1) == 1) {
        printf("[%d,%d]\n", x, y);
        return 1; 
    }

    return 0; 
}

int main() {

    start.x = 2;
    start.y = 2;

    end.x = 8;
    end.y = 18;

    search(start.x, start.y);

    return 0;
}