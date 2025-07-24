//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = { // A 10x10 maze represented as a 2D array
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*'},
        {'*', '*', '*', '*', '*', ' ', '*', '*', '*', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*'},
        {'*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', '*'},
        {'*', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', '*'},
        {'*', '*', '*', '*', '*', ' ', '*', '*', ' ', '*'},
        {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'}
};

struct Point {
    int row, col; //coordinates of a point in the maze
};

typedef struct Point Point; //creating alias for struct Point

int isValid(Point p) {
    return p.row >= 0 && p.row < ROWS && p.col >= 0 && p.col < COLS &&
           maze[p.row][p.col] == ' ';
}

int isEnd(Point p) {
    return p.row == ROWS-1 && p.col == COLS-1;
}

int tracePath(Point path[], int pathLen) {
    printf("Solved! Path is: ");
    for(int i = 0; i < pathLen; ++i) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
    return 1;
}

int solveMazeRec(Point cur, Point path[], int pathLen) {
    if(!isValid(cur)) {
        return 0; //cur is not a valid point
    }
    if(isEnd(cur)) {
        path[pathLen] = cur;
        return tracePath(path, pathLen+1); //We found the end point!
    }
    maze[cur.row][cur.col] = '-'; //mark current point as visited
    path[pathLen] = cur; //add current point to the path
    if(solveMazeRec((Point){cur.row+1,cur.col},path,pathLen+1)) {
        return 1; //end point found in the current branch
    }
    if(solveMazeRec((Point){cur.row-1,cur.col},path,pathLen+1)) {
        return 1; //end point found in the current branch
    }
    if(solveMazeRec((Point){cur.row,cur.col+1},path,pathLen+1)) {
        return 1; //end point found in the current branch
    }
    if(solveMazeRec((Point){cur.row,cur.col-1},path,pathLen+1)) {
        return 1; //end point found in the current branch
    }
    maze[cur.row][cur.col] = ' '; //unmark current point as visited
    return 0; //end point not found in the current branch
}

void solveMaze() {
    Point path[ROWS*COLS];
    maze[0][0] = '-'; //mark starting point as visited
    solveMazeRec((Point){0,0}, path, 0); //start from (0,0)
    maze[0][0] = ' '; //unmark starting point as visited
}

int main() {
    printf("Maze before:\n");
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    solveMaze();
    printf("Maze after:\n");
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}