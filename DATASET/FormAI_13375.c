//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL];
int visited[ROW][COL];

void generateMaze(int row, int col);
void printMaze();
int checkAdjacentCells(int row, int col);

int main() 
{
    srand(time(NULL));
    generateMaze(0,0);
    printMaze();
    return 0;
}

void generateMaze(int row, int col) 
{
    visited[row][col] = 1;
    
    int randDir[4] = {0,1,2,3};
    for(int i=0; i<4; i++) {
        int random = rand() % 4;
        int temp = randDir[random];
        randDir[random] = randDir[i];
        randDir[i] = temp;
    }
    
    for(int i=0; i<4; i++) {
        int newRow = row;
        int newCol = col;
        
        switch(randDir[i]) {
            case 0: // Going up
                newRow--;
                break;
            case 1: // Going down
                newRow++;
                break;
            case 2: // Going left
                newCol--;
                break;
            case 3: // Going right
                newCol++;
                break;
        }
        
        if(newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL || visited[newRow][newCol]) {
            continue;
        }
        
        maze[row][col] |= 1 << randDir[i];
        maze[newRow][newCol] |= 1 << (randDir[i]^1);
        generateMaze(newRow, newCol);
    }
}

void printMaze() 
{
    printf(" ");
    for(int i=0;i<COL;i++){
        printf("_ ");
    }
    printf("\n");
    
    for(int i=0;i<ROW;i++) {
        printf("|");
        
        for(int j=0;j<COL;j++) {
            if(maze[i][j] & 2){
                printf(" ");
            }else{
                printf("_");
            }
            if(maze[i][j] & 4) {
                if((maze[i][j] | maze[i][j+1]) & 2){
                    printf(" ");
                }else{
                    printf("|");
                }
            }else{
                printf("|");
            }
        }
        printf("\n");
    }
}

int checkAdjacentCells(int row, int col) 
{
    int count = 0;
    if (row > 0 && visited[row-1][col]) {
        count++;
    }
    if (row < ROW - 1 && visited[row+1][col]) {
        count++;
    }
    if (col > 0 && visited[row][col-1]) {
        count++;
    }
    if (col < COL - 1 && visited[row][col+1]) {
        count++;
    }
    return count;
}