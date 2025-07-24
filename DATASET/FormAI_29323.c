//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>

#define ROWS 6
#define COLUMNS 8

char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#'},
    {'#', '.', '#', '#', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#'}
};

struct Position {
    int x;
    int y;
};

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

void printMaze(char maze[ROWS][COLUMNS], struct Position current) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            if(current.x == row && current.y == col) {
                printf("*");
            } else {
                printf("%c", maze[row][col]);
            }
        }
        printf("\n");
    }
}

int canMove(char maze[ROWS][COLUMNS], struct Position current, Direction direction) {
    switch(direction) {
        case NORTH:
            if(current.x == 0 || maze[current.x - 1][current.y] == '#') {
                return 0;
            }
            return 1;
        case EAST:
            if(current.y == COLUMNS - 1 || maze[current.x][current.y + 1] == '#') {
                return 0;
            }
            return 1;
        case SOUTH:
            if(current.x == ROWS - 1 || maze[current.x + 1][current.y] == '#') {
                return 0;
            }
            return 1;
        case WEST:
            if(current.y == 0 || maze[current.x][current.y - 1] == '#') {
                return 0;
            }
            return 1;
        default:
            return 0;
    }
}

struct Position move(char maze[ROWS][COLUMNS], struct Position current, Direction direction) {
    switch(direction) {
        case NORTH:
            current.x--;
            break;
        case EAST:
            current.y++;
            break;
        case SOUTH:
            current.x++;
            break;
        case WEST:
            current.y--;
            break;
    }
    return current;
}

void findRoute(char maze[ROWS][COLUMNS], struct Position current) {
    if(current.x == ROWS - 1 && current.y == COLUMNS - 1) {
        printf("\nCongratulations! You found the exit!\n\n");
        printMaze(maze, current);
        return;
    }
    
    if(canMove(maze, current, NORTH)) {
        struct Position next = move(maze, current, NORTH);
        printMaze(maze, next);
        findRoute(maze, next);
    }
    if(canMove(maze, current, EAST)) {
        struct Position next = move(maze, current, EAST);
        printMaze(maze, next);
        findRoute(maze, next);
    }
    if(canMove(maze, current, SOUTH)) {
        struct Position next = move(maze, current, SOUTH);
        printMaze(maze, next);
        findRoute(maze, next);
    }
    if(canMove(maze, current, WEST)) {
        struct Position next = move(maze, current, WEST);
        printMaze(maze, next);
        findRoute(maze, next);
    }
}

int main() {
    printf("Welcome to the Maze Route Finder. You are currently at the entrance of the maze and you need to find your way to the exit. Good luck!\n");
    struct Position start = {1, 0};
    printMaze(maze, start);
    findRoute(maze, start);
    return 0;
}