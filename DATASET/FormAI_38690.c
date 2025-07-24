//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include<stdio.h>

//Function to check if a cell can be visited or not
int canVisit(int maze[10][10], int visited[10][10], int row, int col){
    if(maze[row][col] == 0 || visited[row][col] == 1)
        return 0;
    return 1;
}

//Function to check if current cell is destination or not
int isDestination(int row, int col, int endRow, int endCol){
    if(row == endRow && col == endCol)
        return 1;
    return 0;
}

//Function to print the path
void printPath(int path[1000][2], int pathLen){
    printf("The path is: ");
    for(int i=0;i<pathLen;i++)
        printf("(%d,%d)->", path[i][0], path[i][1]);
    printf("END");
}

//Function to find the route
void findRoute(int maze[10][10], int visited[10][10], int row, int col, int endRow, int endCol, int path[1000][2], int* pathLen){
    //If reached the destination
    if(isDestination(row, col, endRow, endCol)){
        path[*pathLen][0] = row;
        path[*pathLen][1] = col;
        (*pathLen)++;
        printPath(path, *pathLen);
        return;
    }
    
    //Mark current cell as visited
    visited[row][col] = 1;
    
    //Path exists in the down direction
    if(row+1<10 && canVisit(maze, visited, row+1, col)){
        path[*pathLen][0] = row;
        path[*pathLen][1] = col;
        (*pathLen)++;
        findRoute(maze, visited, row+1, col, endRow, endCol, path, pathLen);
        (*pathLen)--;
    }
    
    //If path does not exist in the down direction, check in the right direction
    if(col+1<10 && canVisit(maze, visited, row, col+1)){
        path[*pathLen][0] = row;
        path[*pathLen][1] = col;
        (*pathLen)++;
        findRoute(maze, visited, row, col+1, endRow, endCol,path, pathLen);
        (*pathLen)--;
    }
    
    //If path does not exist in the right and down direction, check in the left direction
    if(col-1>=0 && canVisit(maze, visited, row, col-1)){
        path[*pathLen][0] = row;
        path[*pathLen][1] = col;
        (*pathLen)++;
        findRoute(maze, visited, row, col-1, endRow, endCol, path, pathLen);
        (*pathLen)--;
    }
    
    //If path does not exist in the left and down direction, check in the up direction
    if(row-1>=0 && canVisit(maze, visited, row-1, col)){
        path[*pathLen][0] = row;
        path[*pathLen][1] = col;
        (*pathLen)++;
        findRoute(maze, visited, row-1, col, endRow, endCol, path, pathLen);
        (*pathLen)--;
    }
    
    //Mark current cell as unvisited
    visited[row][col] = 0;
}

int main(){
    
    int maze[10][10] = { {1,1,1,1,1,1,1,1,1,1},
                         {0,1,0,0,1,0,1,0,0,1},
                         {1,1,1,1,1,0,1,0,1,1},
                         {1,0,0,0,0,0,0,0,0,1},
                         {1,0,1,1,1,1,0,1,1,1},
                         {1,0,0,0,0,0,0,0,0,0},
                         {1,1,1,1,1,0,1,1,1,1},
                         {0,0,0,0,1,0,0,0,0,1},
                         {1,1,1,1,1,0,1,1,1,1},
                         {0,0,0,0,1,0,0,0,0,1} };
                         
    int visited[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0} };
                           
    int path[1000][2], pathLen=0;
    
    printf("The maze is: \n");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
    
    printf("\nEnter the start and end points of the maze: \n");
    int startRow, startCol, endRow, endCol;
    scanf("%d%d%d%d", &startRow, &startCol, &endRow, &endCol);
    
    //Find the route
    findRoute(maze, visited, startRow, startCol, endRow, endCol, path, &pathLen);
    
    if(pathLen == 0)
        printf("The path does not exist.");
    
    return 0;
}