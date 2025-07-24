//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Surprise! Today we will be implementing a unique pathfinding algorithm!\n");
    int rows=5,cols=5,start_row=1,start_col=1,end_row=4,end_col=4;
    int grid[5][5]={
                    {0,1,0,0,0},
                    {0,1,0,1,0},
                    {0,0,0,0,0},
                    {0,1,1,1,0},
                    {0,0,0,1,0}
                    };
    printf("Here is your defined grid:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    
    int visited[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            visited[i][j]=0;
        }
    }
    
    int path[rows*cols][2];
    for(int i=0;i<rows*cols;i++){
        path[i][0]=-1;
        path[i][1]=-1;
    }
    
    int front=-1,rear=-1;
    int x=start_row,y=start_col;
    visited[x][y]=1;
    path[++rear][0]=x;
    path[rear][1]=y;
    
    while(front!=rear){
        x=path[++front][0];
        y=path[front][1];
        
        if(x==end_row && y==end_col){
            printf("Hurray! Path found from (%d,%d) to (%d,%d)\n",start_row,start_col,end_row,end_col);
            printf("And the path is:\n");
            int path_track[rows][cols];
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    path_track[i][j]=0;
                }
            }
            int px=x,py=y;
            path_track[px][py]=1;
            while(px!=start_row || py!=start_col){
                int dir=grid[px][py];
                if(dir==2){
                    px--;
                }
                else if(dir==4){
                    px++;
                }
                else if(dir==6){
                    py--;
                }
                else if(dir==8){
                    py++;
                }
                path_track[px][py]=1;
            }
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(path_track[i][j]==1){
                        printf("-> (%d,%d)",i,j);
                    }
                }
            }
            printf("\n");
            break;
        }
        
        if(x-1>=0 && grid[x-1][y]!=1 && visited[x-1][y]==0){
            visited[x-1][y]=1;
            path[++rear][0]=x-1;
            path[rear][1]=y;
            grid[x-1][y]=2;
        }
        if(x+1<rows && grid[x+1][y]!=1 && visited[x+1][y]==0){
            visited[x+1][y]=1;
            path[++rear][0]=x+1;
            path[rear][1]=y;
            grid[x+1][y]=4;
        }
        if(y-1>=0 && grid[x][y-1]!=1 && visited[x][y-1]==0){
            visited[x][y-1]=1;
            path[++rear][0]=x;
            path[rear][1]=y-1;
            grid[x][y-1]=6;
        }
        if(y+1<cols && grid[x][y+1]!=1 && visited[x][y+1]==0){
            visited[x][y+1]=1;
            path[++rear][0]=x;
            path[rear][1]=y+1;
            grid[x][y+1]=8;
        }
    }
    if(front==rear){
        printf("Oops, no path found from (%d,%d) to (%d,%d) in the given grid!",start_row,start_col,end_row,end_col);
    }
    return 0;
}