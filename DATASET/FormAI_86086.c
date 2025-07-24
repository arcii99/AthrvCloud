//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 6
#define COLUMN 7

//Maze matrix
char Maze[ROW][COLUMN] = {
    {'#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
};

//Function to print the maze
void printMaze(char Maze[][COLUMN]) {
    int i, j;
    printf("Maze: \n");
    for(i=0;i<ROW;i++) {
        for(j=0;j<COLUMN;j++) {
            printf("%c ", Maze[i][j]);
        }
        printf("\n");
    }
}

//Function to check if a point is a valid point
bool isValidPoint(int x, int y) {
    if(x < 0 || x >= ROW || y < 0 || y >= COLUMN) 
        return false;
    if(Maze[x][y] == '#')
        return false;
    return true;
}

//Function to find the path through the maze
bool findPath(int x, int y, int path[][COLUMN]) {
    if(x == ROW-1 && y == COLUMN-1) {
        path[x][y] = 1;
        return true;
    }
    if(isValidPoint(x, y)) {
        path[x][y] = 1; //Mark as part of the current path
        if(findPath(x+1, y, path)) //Move Down
            return true;
        if(findPath(x, y+1, path)) //Move Right
            return true;
        path[x][y] = 0; //If none of the above directions work, backtrack and unmark as part of the current path
    }
    return false;
}

int main() {
    int i, j;
    int path[ROW][COLUMN];
    for(i=0;i<ROW;i++) {
        for(j=0;j<COLUMN;j++) {
            path[i][j] = 0; //Initialise all path elements to 0 as not part of the path
        }
    }
    printf("Welcome to the Maze Route Finder!\n");
    printf("The maze is as follows:\n\n");
    printMaze(Maze);
    printf("\nFinding the path...\n\n");
    bool pathFound = findPath(1, 1, path);
    if(pathFound) {
        printf("The path was found!\n\n");
        printf("The path is as follows:\n");
        for(i=0;i<ROW;i++) {
            for(j=0;j<COLUMN;j++) {
                if(path[i][j] == 1)
                    printf("(%d,%d) -> ", i, j);
            }
        }
        printf("(%d,%d)\n", ROW-1, COLUMN-1); //The end point is always in the path
    }
    else {
        printf("There was no path found.\n");
    }
    return 0;
}