//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int grid[ROW][COL] = {
    {1,1,1,1,1,1,0,1,1,1},
    {1,0,1,0,0,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1},
    {0,0,1,1,1,1,0,1,1,1},
    {1,1,1,0,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,1},
    {1,1,0,1,0,0,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
};

bool visited[ROW][COL];
int path[ROW*COL];
int n = 0;

void printPath(){
    for (int i = 0; i < n; i++){
        printf("(%d,%d) -> ", path[i]/COL, path[i]%COL);
    }
    printf("(%d,%d)\n", path[n-1]/COL, path[n-1]%COL);
}

bool isValid(int row, int col){
    return row >= 0 && col >= 0 && row < ROW && col < COL && grid[row][col] == 1 && !visited[row][col];
}

bool dfs(int row, int col, int destRow, int destCol){
    if (row == destRow && col == destCol){
        path[n++] = row*COL + col;
        return true;
    }

    if (isValid(row, col)){
        visited[row][col] = true;
        path[n++] = row*COL + col;

        if (dfs(row-1, col, destRow, destCol)){
            return true;
        }

        if (dfs(row+1, col, destRow, destCol)){
            return true;
        }

        if (dfs(row, col-1, destRow, destCol)){
            return true;
        }

        if (dfs(row, col+1, destRow, destCol)){
            return true;
        }

        path[--n] = -1; // backtracking
    }

    return false;
}

int main(){
    int srcRow = 0, srcCol = 0;
    int destRow = 7, destCol = 8;

    printf("The grid is: \n\n");
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    if (dfs(srcRow, srcCol, destRow, destCol)){
        printf("The path from (%d,%d) to (%d,%d) is: \n", srcRow, srcCol, destRow, destCol);
        printPath();
    }
    else{
        printf("No path from (%d,%d) to (%d,%d) exists.\n", srcRow, srcCol, destRow, destCol);
    }

    return 0;
}