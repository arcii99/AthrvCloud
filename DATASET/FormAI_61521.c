//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ',' ','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#','#','#','#'},
    {'#','#','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ',' ',' ','#','#','#',' ','#','#'},
    {'#','#',' ','#','#',' ',' ',' ',' ','#'},
    {'#','#',' ',' ',' ','#','#','#',' ','#'},
    {'#',' ','#','#',' ',' ',' ','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

int visited[ROW][COL];
int startingRow, startingCol, endingRow, endingCol;

void printMaze() {
    printf("\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void findStartingAndEndingPoint() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(maze[i][j] == 'S') {
                startingRow = i;
                startingCol = j;
            } else if(maze[i][j] == 'E') {
                endingRow = i;
                endingCol = j;
            }
        }
    }
}

void initializeVisitedArray() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            visited[i][j] = 0;
        }
    }
}

int isSafe(int row, int col) {
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] != '#' && visited[row][col] == 0){
        return 1;
    }
    return 0;
}

void findMazeRoute(int row, int col) {
    visited[row][col] = 1;
    if(row == endingRow && col == endingCol) {
        printMaze();
        printf("Route Found\n");
        return;
    }
    if(isSafe(row-1, col)) { //UP
        maze[row-1][col] = '^';
        findMazeRoute(row-1, col);
        maze[row-1][col] = ' ';
    }
    if(isSafe(row, col+1)) { //RIGHT
        maze[row][col+1] = '>';
        findMazeRoute(row, col+1);
        maze[row][col+1] = ' ';
    }
    if(isSafe(row+1, col)) { //DOWN
        maze[row+1][col] = 'v';
        findMazeRoute(row+1, col);
        maze[row+1][col] = ' ';
    }
    if(isSafe(row, col-1)) { //LEFT
        maze[row][col-1] = '<';
        findMazeRoute(row, col-1);
        maze[row][col-1] = ' ';
    }
    visited[row][col] = 0;
}

int main() {
    findStartingAndEndingPoint();
    initializeVisitedArray();
    findMazeRoute(startingRow, startingCol);
    printf("Route not found\n");
    return 0;
}