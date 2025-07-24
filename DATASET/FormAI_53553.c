//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int path[MAX][MAX];
void printPath(int m,int n);

int main(){
    int maze[MAX][MAX], path[MAX][MAX];
    int i,j,m,n;
    printf("Enter size of maze (MxN): ");
    scanf("%d%d",&m,&n);
    printf("\nEnter maze:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d",&maze[i][j]);
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(maze[i][j] == 1)
                path[i][j] = 0;
            else
                path[i][j] = -1;
        }
    }
    if(maze[0][0] == 1 || maze[m-1][n-1] == 1){
        printf("No Path Exist!!!\n");
        return 0;
    }
    else{
        printf("\nMaze Input:\n");
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                printf("%d ",maze[i][j]);
            }
            printf("\n");
        }
        if(findPath(maze,0,0,path,m-1,n-1) == 1){
            printf("\nOutput Path:\n");
            for(i=0; i<m; i++){
                for(j=0; j<n; j++){
                    printf("%d ",path[i][j]);
                }
                printf("\n");
            }
            printPath(m-1,n-1);
        }
        else{
            printf("No Path Exist!!!\n");
            return 0;
        }
    }
    return 0;
}

int findPath(int maze[][MAX], int i, int j, int path[][MAX], int x, int y){
    if(i == x && j == y){
        path[i][j] = 1;
        return 1;
    }
    if(i<0 || j<0 || maze[i][j] == 1 || path[i][j] == 1)
        return 0;
    path[i][j] = 1;
    if(findPath(maze,i+1,j,path,x,y) || findPath(maze,i,j+1,path,x,y) || findPath(maze,i-1,j,path,x,y) || findPath(maze,i,j-1,path,x,y))
        return 1;
    path[i][j] = 0;
    return 0;
}

void printPath(int m,int n){
    printf("\nShortest Path:\n");
    int i=m,j=n;
    while(i>=0 && j>=0){
        printf("(%d,%d)\n",i,j);
        if(i==0)
            j--;
        else if(j==0)
            i--;
        else if(path[i-1][j] == 1)
            i--;
        else if(path[i][j-1] == 1)
            j--;
    }
}