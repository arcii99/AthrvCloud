//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Defining Constants
#define MAX_ROW 30
#define MAX_COL 30
#define MAX_STEPS 50
#define BRANCH 4
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define TRUE 1
#define FALSE 0

//Struct to store coordinates
struct point{
    int x, y;
};

//Function to display the maze
void displayMaze(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end);

//Function to create the maze
void createMaze(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end);

//Recursive function to find the path
int findPath(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end, struct point path[MAX_STEPS], int index);

//Main function
void main() {
    //Initializing Variables
    int maze[MAX_ROW][MAX_COL], row = 0, col = 0;
    struct point start = {0, 0}, end = {0, 0};
    struct point path[MAX_STEPS];
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);
    printf("\n");

    //Calling Function to create maze
    createMaze(maze, row, col, start, end);

    //Calling Function to display maze
    displayMaze(maze, row, col, start, end);

    //Calling Function to find the path
    int pathFound = findPath(maze, row, col, start, end, path, 0);

    if(pathFound) {
        //Printing the path
        printf("Path Found: ");
        for(int i=0; i<pathFound; i++) {
            if(i > 0) printf(", ");
            printf("(%d,%d)", path[i].x, path[i].y);
        }
        printf("\n");
    }
    else {
        printf("No Path Found.\n");
    }
}

//Function to display the maze
void displayMaze(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end) {
    printf("Start: (%d,%d), End: (%d,%d)\n", start.x, start.y, end.x, end.y);
    printf("MAZE:\n");

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(i == start.x && j == start.y) {
                printf("S ");
            }
            else if(i == end.x && j == end.y) {
                printf("E ");
            }
            else if(maze[i][j] == TRUE) {
                printf("  ");
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Function to create the maze
void createMaze(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end) {
    //Initializing Random Number Generator
    srand(time(NULL));

    //Setting Start and End Points
    start.x = rand() % row;
    start.y = rand() % col;

    do {
        end.x = rand() % row;
        end.y = rand() % col;
    } while(end.x == start.x && end.y == start.y);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(i == start.x && j == start.y) {
                maze[i][j] = TRUE;
            }
            else if(i == end.x && j == end.y) {
                maze[i][j] = TRUE;
            }
            else {
                maze[i][j] = rand() % 2;
            }
        }
    }
}

//Recursive function to find the path
int findPath(int maze[MAX_ROW][MAX_COL], int row, int col, struct point start, struct point end, struct point path[MAX_STEPS], int index) {
    if(start.x == end.x && start.y == end.y) {
        path[index] = end;
        return index+1;
    }

    if(index >= MAX_STEPS) {
        return 0;
    }

    int branchOrder[BRANCH] = {UP, LEFT, DOWN, RIGHT};

    for(int i=0; i<BRANCH; i++) {
        int r = rand() % BRANCH;
        int temp = branchOrder[i];
        branchOrder[i] = branchOrder[r];
        branchOrder[r] = temp;
    }

    for(int i=0; i<BRANCH; i++) {
        struct point next = {start.x, start.y};

        switch(branchOrder[i]) {
            case UP:
                if(start.x > 0 && maze[start.x-1][start.y] == TRUE) {
                    next.x--;
                }
                break;
            case LEFT:
                if(start.y > 0 && maze[start.x][start.y-1] == TRUE) {
                    next.y--;
                }
                break;
            case DOWN:
                if(start.x < row-1 && maze[start.x+1][start.y] == TRUE) {
                    next.x++;
                }
                break;
            case RIGHT:
                if(start.y < col-1 && maze[start.x][start.y+1] == TRUE) {
                    next.y++;
                }
                break;
        }

        if(next.x != start.x || next.y != start.y) {
            int pathFound = findPath(maze, row, col, next, end, path, index+1);

            if(pathFound) {
                path[index] = start;
                return pathFound;
            }
        }
    }

    return 0;
}