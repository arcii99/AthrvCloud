//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 6

int maze[ROW][COL] = {
    {0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0}
};

int solution[ROW][COL] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

int findPath(int x, int y) {
    if(x < 0 || x >= ROW || y < 0 || y >= COL) { //checking if the current co-ordinates are within the bounds of the given maze
        return 0;
    }

    if(maze[x][y] == 0) { //if the current co-ordinate is a wall or already explored return 0
        return 0;
    }

    if(solution[x][y] == 1) { //if the current co-ordinate is already part of the solution path, return 0
        return 0;
    }

    //mark the current co-ordinate as part of the solution path
    solution[x][y] = 1; 

    if(x == ROW-1 && y == COL-1) { //if we have reached the end co-ordinate of the maze, return 1
        return 1;
    }

    //recursive calls to check all possible directions i.e. Up, Right, Down and Left
    if(findPath(x-1, y) == 1) { 
        return 1;
    }

    if(findPath(x, y+1) == 1) { 
        return 1;
    }

    if(findPath(x+1, y) == 1) { 
        return 1;
    }

    if(findPath(x, y-1) == 1) { 
        return 1;
    }

    //if we have reached here, that means we haven't found a solution path
    //so we remove this co-ordinate from the solution path and mark it as explored
    solution[x][y] = 0; 
    return 0;
}

void printMaze() {
    printf("MAZE:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printSolution() {
    printf("SOLUTION:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Recursive Pathfinding Algorithm Demo!\n");
    printMaze();

    if(findPath(0, 0)) { //starting from the top-left of the maze
        printf("\nA path has been found!\n");
        printSolution();
    } else {
        printf("\nThere doesn't seem to be a path to the end.\n");
    }

    return 0;
}