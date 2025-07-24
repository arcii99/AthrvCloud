//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Function to print the matrix
void printMatrix(int arr[][COL]) {
    printf("Matrix:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to find the shortest path using BFS Algorithm
int bfsSearch(int arr[][COL], int rowStart, int colStart, int rowEnd, int colEnd) {
    int visited[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            visited[i][j]=0;
        }
    }

    int queue[100], front=-1, rear=-1;
    
    // Mark the starting cell as visited
    queue[++rear] = rowStart*COL + colStart;
    visited[rowStart][colStart]=1;

    int distance=0;
    while(front!=rear) {
        int size = rear-front;
        distance++;
        for(int i=0; i<size; i++) {
            int vertex = queue[++front];
            int row = vertex / COL;
            int col = vertex % COL;

            // Check if this cell is the destination
            if(row==rowEnd && col==colEnd) {
                return distance;
            }

            // Check for adjacent cells
            if(row-1>=0 && arr[row-1][col]==1 && visited[row-1][col]==0) {  // Up
                visited[row-1][col]=1;
                queue[++rear] = (row-1)*COL + col;
            }
            if(row+1<ROW && arr[row+1][col]==1 && visited[row+1][col]==0) { // Down
                visited[row+1][col]=1;
                queue[++rear] = (row+1)*COL + col;
            }
            if(col-1>=0 && arr[row][col-1]==1 && visited[row][col-1]==0) {  // Left
                visited[row][col-1]=1;
                queue[++rear] = row*COL + col-1;
            }
            if(col+1<COL && arr[row][col+1]==1 && visited[row][col+1]==0) {  // Right
                visited[row][col+1]=1;
                queue[++rear] = row*COL + col+1;
            }
        }
    }

    return -1;  // If a path is not found
}

int main() {
    int arr[ROW][COL] = {{1,0,1,1,1},
                         {1,0,1,0,1},
                         {1,1,1,0,1},
                         {0,0,0,0,1},
                         {1,1,1,1,1}};

    printMatrix(arr);

    int rowStart=0, colStart=0, rowEnd=ROW-1, colEnd=COL-1;
    int distance = bfsSearch(arr, rowStart, colStart, rowEnd, colEnd);

    if(distance==-1) {
        printf("\nNo path found!\n");
    }
    else {
        printf("\nShortest distance: %d\n", distance);
    }

    return 0;
}