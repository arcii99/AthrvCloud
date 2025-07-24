//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

typedef struct {
    int x;
    int y;
} Position;

int maze[ROWS][COLS] = {
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[ROWS][COLS] = {0};

Position start = {1, 0};
Position end = {8, 9};

Position getNext(Position pos) {
    Position next;
    next.x = pos.x;
    next.y = pos.y;
    
    if(pos.y+1 < COLS && maze[pos.x][pos.y+1] && !visited[pos.x][pos.y+1]) {
        next.y = pos.y+1;
        return next;
    }
    
    if(pos.x+1 < ROWS && maze[pos.x+1][pos.y] && !visited[pos.x+1][pos.y]) {
        next.x = pos.x+1;
        return next;
    }
    
    if(pos.y-1 >= 0 && maze[pos.x][pos.y-1] && !visited[pos.x][pos.y-1]) {
        next.y = pos.y-1;
        return next;
    }
    
    if(pos.x-1 >= 0 && maze[pos.x-1][pos.y] && !visited[pos.x-1][pos.y]) {
        next.x = pos.x-1;
        return next;
    }
    
    next.x = -1;
    next.y = -1;
    
    return next;
}

void solveMaze(Position pos) {
    visited[pos.x][pos.y] = 1;
    
    if(pos.x == end.x && pos.y == end.y) {
        printf("\nHooray, I found the exit!\n");
        return;
    }
    
    Position next = getNext(pos);
    while(next.x != -1 && next.y != -1) {
        solveMaze(next);
        next = getNext(pos);
    }
}

int main() {
    printf("Hello, I am Sherlock Holmes and I am going to help you find your way through the maze!\n");
    
    solveMaze(start);
    
    return 0;
}