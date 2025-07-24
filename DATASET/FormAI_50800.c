//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

void generateMaze(int maze[][20], int row, int col);
void printMaze(int maze[][20], int row, int col);
void createPath(int maze[][20], int x, int y);
int isValid(int x, int y);
int hasUnvisitedNeighbour(int maze[][20], int x, int y);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze, ROWS, COLS);
    printMaze(maze, ROWS, COLS);
    return 0;
}

void generateMaze(int maze[][20], int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            maze[i][j] = 1; //fill the maze with walls
        }
    }
    createPath(maze, 1, 1); //start creating the path from (1, 1)
}

void createPath(int maze[][20], int x, int y) {
    int dx, dy, random;
    maze[x][y] = 0; //mark current cell as visited
    while(hasUnvisitedNeighbour(maze, x, y)) {
        random = rand() % 4; 
        switch(random) { //randomly select a neighbour
            case 0: dx = -1; dy = 0; break; //move up
            case 1: dx = 1; dy = 0; break; //move down
            case 2: dx = 0; dy = -1; break; //move left
            case 3: dx = 0; dy = 1; break; //move right
        }
        if(isValid(x + dx, y + dy) && maze[x+dx][y+dy] == 1) { 
            //if the neighbour is valid and unvisited
            maze[x+dx/2][y+dy/2] = 0; //make the wall between them a path
            createPath(maze, x + dx, y + dy); //recurse on the new cell
        }
    }
}

int isValid(int x, int y) { //check if the cell is within the boundaries of the maze
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

int hasUnvisitedNeighbour(int maze[][20], int x, int y) {
    int i, j;
    int neighbours[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //all possible neighbours
    for(i = 0; i < 4; i++) {
        if(isValid(x + neighbours[i][0], y + neighbours[i][1]) && maze[x + neighbours[i][0]][y + neighbours[i][1]] == 1) {
            //if the neighbour is valid and unvisited
            return 1; //has unvisited neighbour
        }
    }
    return 0; //no unvisited neighbour
}

void printMaze(int maze[][20], int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            if(maze[i][j] == 0) printf("  "); // path
            else printf("%c%c", 178, 178); // wall
        }
        printf("\n");
    }
}