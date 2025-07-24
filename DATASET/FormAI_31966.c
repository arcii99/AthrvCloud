//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define START 'S'
#define GOAL 'E'
#define BLOCKED '#'
#define PATH '.'

// Function to print the maze
void printMaze(char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to find starting position in the maze
void findStart(char maze[HEIGHT][WIDTH], int *x, int *y) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == START) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Function to check if given position is a valid move
bool isValid(char maze[HEIGHT][WIDTH], int x, int y) {
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && maze[x][y] != BLOCKED) {
        return true;
    }
    return false;
}

// Function to find path to goal in the maze
bool findPath(char maze[HEIGHT][WIDTH], int x, int y) {
    if (maze[x][y] == GOAL) {
        return true;
    }
    
    if (!isValid(maze, x, y)) {
        return false;
    }
    
    if (maze[x][y] == PATH) {
        return false;
    }
    
    maze[x][y] = PATH;
    
    if (findPath(maze, x+1, y)) {
        return true;
    }
    
    if (findPath(maze, x, y+1)) {
        return true;
    }
    
    if (findPath(maze, x-1, y)) {
        return true;
    }
    
    if (findPath(maze, x, y-1)) {
        return true;
    }
    
    maze[x][y] = ' ';
    return false;
}

// Main function
int main() {
    char maze[HEIGHT][WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'S', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', 'E', '#'}
    };
    
    printMaze(maze);
    
    int startX, startY;
    findStart(maze, &startX, &startY);
    
    if (findPath(maze, startX, startY)) {
        printf("\nPath to goal found:\n");
        printMaze(maze);
    } else {
        printf("\nNo path to goal found.\n");
    }
    
    return 0;
}