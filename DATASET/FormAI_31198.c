//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 10

void printMaze(char maze[][COLUMN], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char maze[][COLUMN], int visited[][COLUMN], int x, int y, int rows, int cols) {
    if(x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == ' ' && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}

void findRoute(char maze[][COLUMN], int visited[][COLUMN], int x, int y, int rows, int cols) {
    if(x == rows - 1 && y == cols - 1) {
        visited[x][y] = 1;
        printMaze(maze, rows, cols);
        return;
    }
    
    if(isValidMove(maze, visited, x, y, rows, cols)) {
        visited[x][y] = 1;
        
        maze[x][y] = '*';
        
        findRoute(maze, visited, x + 1, y, rows, cols);
        findRoute(maze, visited, x, y + 1, rows, cols);
        findRoute(maze, visited, x - 1, y, rows, cols);
        findRoute(maze, visited, x, y - 1, rows, cols);
        
        visited[x][y] = 0;
        maze[x][y] = ' ';
    }
}

int main() {
    char maze[ROW][COLUMN] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                              {' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
                              {'#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
                              {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
                              {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                              {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
                              {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                              {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
                              {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
                              {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
                              
    int visited[ROW][COLUMN] = {0};
    
    printMaze(maze, ROW, COLUMN);
    
    printf("\n\nThe route to the exit is:\n");
    findRoute(maze, visited, 0, 0, ROW, COLUMN);
    
    return 0;
}