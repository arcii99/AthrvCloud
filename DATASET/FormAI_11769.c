//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate maze
void generateMaze(int row, int col, char maze[row][col]) {
    // Set random seed
    srand(time(NULL));
    
    // Initialize maze with walls
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            if(i==0 || j==0 || i==row-1 || j==col-1) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = ' ';
            }
        }
    }
    
    // Set starting and ending points
    maze[1][1] = 'S';
    maze[row-2][col-2] = 'E';

    // Generate maze paths using DFS
    int stackRow[row*col], stackCol[row*col], top=0;
    int visited[row][col];
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            visited[i][j] = 0;
        }
    }
    int dirRow[] = {-1, 0, 1, 0};
    int dirCol[] = {0, 1, 0, -1};
    stackRow[top] = 1;
    stackCol[top] = 1;
    visited[1][1] = 1;
    while(top!=-1) {
        int currRow = stackRow[top];
        int currCol = stackCol[top];
        top--;
        if(rand()%4) {
            continue;
        }
        int order[4] = {0, 1, 2, 3};
        for(i=0; i<4; i++) {
            int r = rand()%4;
            int temp = order[i];
            order[i] = order[r];
            order[r] = temp;
        }
        for(i=0; i<4; i++) {
            int nextRow = currRow + dirRow[order[i]];
            int nextCol = currCol + dirCol[order[i]];
            if(nextRow<1 || nextRow>=row-1 || nextCol<1 || nextCol>=col-1 || visited[nextRow][nextCol]) {
                continue;
            }
            int count = 0;
            for(j=0; j<4; j++) {
                int adjRow = nextRow + dirRow[j];
                int adjCol = nextCol + dirCol[j];
                if(maze[adjRow][adjCol]=='#') {
                    count++;
                }
            }
            if(count==3) {
                maze[nextRow][nextCol] = ' ';
                visited[nextRow][nextCol] = 1;
                top++;
                stackRow[top] = nextRow;
                stackCol[top] = nextCol;
            }
        }
    }
}

// Function to print maze
void printMaze(int row, int col, char maze[row][col]) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int row = 15;
    int col = 15;
    char maze[row][col];
    
    // Generate and print maze
    generateMaze(row, col, maze);
    printMaze(row, col, maze);
    
    return 0;
}