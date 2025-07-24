//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5 //Number of rows in the maze
#define COL 5 //Number of columns in the maze

void printMaze(char maze[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int x, int y, char maze[][COL], bool visited[][COL]) {
    if(x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==' ' && !visited[x][y]) {
        return true;
    }
    return false;
}

bool findRoute(int x, int y, char maze[][COL], bool visited[][COL]) {
    if(x == ROW-1 && y == COL-1) {
        visited[x][y] = true;
        return true;
    }
    if(isValid(x,y,maze,visited)) {
        visited[x][y] = true;
        if(findRoute(x+1, y, maze, visited)) {
            return true;
        }
        if(findRoute(x-1, y, maze, visited)) {
            return true;
        }
        if(findRoute(x, y+1, maze, visited)) {
            return true;
        }
        if(findRoute(x, y-1, maze, visited)) {
            return true;
        }
        visited[x][y] = false; // Backtrack
    }
    return false;
}

int main() {
    char maze[ROW][COL] = {
        {' ','*','*','*',' '},
        {' ',' ','*',' ',' '},
        {'*',' ','*',' ','*'},
        {'*',' ',' ','*','*'},
        {' ','*','*','*',' '},
    };

    bool visited[ROW][COL] = {false};

    printMaze(maze);

    if(findRoute(0, 0, maze, visited)) {
        printf("\nRoute found:\n");
        printMaze(maze);
    }
    else {
        printf("\nNo path found.\n");
    }
    return 0;
}