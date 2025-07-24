//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
int isVisited[ROWS][COLS];
int stack[ROWS*COLS][2];
int top = -1;

void generateMaze() {
    int i, j;
    //initialize all cell as 1 and not visited
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            maze[i][j] = 1;
            isVisited[i][j] = 0;
        }
    }
    srand(time(NULL));
    //set starting point
    int currentRow = rand()%ROWS;
    int currentCol = rand()%COLS;
    maze[currentRow][currentCol] = 0;
    stack[++top][0] = currentRow;
    stack[top][1] = currentCol;
    isVisited[currentRow][currentCol] = 1;
    while(top != -1) {
        int neighbours[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//up, down, left, right
        int neighbourCount = 0;
        for(i=0; i<4; i++) {
            int row = currentRow + neighbours[i][0];
            int col = currentCol + neighbours[i][1];
            if(row>=0 && row<ROWS && col>=0 && col<COLS && isVisited[row][col]==0) {
                int neighbourWall = 2*i + 1; //(1,1), (1,3), (3,1), (3,3)
                int currentWall;
                if(i==0) //up
                    currentWall = 0;
                else if(i==1) //down
                    currentWall = 2;
                else if(i==2) //left
                    currentWall = 3;
                else //right
                    currentWall = 1;
                maze[currentRow + neighbours[i][0]][currentCol + neighbours[i][1]] = 0;
                maze[currentRow][currentCol] &= ~(1<<currentWall);
                maze[currentRow + neighbours[i][0]][currentCol + neighbours[i][1]] &= ~(1<<neighbourWall);
                stack[++top][0] = row;
                stack[top][1] = col;
                isVisited[row][col] = 1;
            }
        }
        if(neighbourCount == 0) {
            top--;
        }
        else {
            int randomNeighbour = rand()%neighbourCount;
            currentRow = stack[top][0] + neighbours[randomNeighbour][0];
            currentCol = stack[top][1] + neighbours[randomNeighbour][1];
        }
    }
}

void printMaze() {
    int i, j;
    printf("\n");
    for(i=0; i<=COLS*2; i++)
        printf("_");
    printf("\n");
    for(i=0; i<ROWS; i++) {
        printf("|");
        for(j=0; j<COLS; j++) {
            if(maze[i][j] & 1<<0)
                printf("_");
            else
                printf(" ");
            if(maze[i][j] & 1<<3)
                printf("|");
            else
                printf(" ");
                
        }
        printf("\n");
    }
}

int main() {
    memset(maze, 0, sizeof(maze));
    memset(isVisited, 0, sizeof(isVisited));
    memset(stack, -1, sizeof(stack));
    generateMaze();
    printMaze();
    return 0;
}