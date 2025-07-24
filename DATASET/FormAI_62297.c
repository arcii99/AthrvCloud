//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 // grid size

void print_grid(int (*grid)[N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(int (*grid)[N]){
    int top[N],bottom[N],visited[N],stack[N],top_idx=0,bottom_idx=0,stack_idx=0;
  
    for(int i=0;i<N;i++){
        visited[i]=0;
        if(grid[0][i]==1){
            top[top_idx++]=i; // add to top row if open
        }
        if(grid[N-1][i]==1){
            bottom[bottom_idx++]=i; // add to bottom row if open
        }
    }

    for(int i=0;i<top_idx;i++){
        stack[stack_idx++]=top[i]; // add top row to stack
        visited[top[i]]=1;
    }
  
    while(stack_idx!=0){ // until stack is empty
        int current=stack[--stack_idx];
        int i=current%N; // get row and column number
        int j=current/N;
        if(i-1>=0 && visited[j*N+i-1]==0 && grid[j][i-1]==1){ // check left neighbor
            visited[j*N+i-1]=1;
            stack[stack_idx++]=current-1;
        }
        if(i+1<N && visited[j*N+i+1]==0 && grid[j][i+1]==1){ // check right neighbor
            visited[j*N+i+1]=1;
            stack[stack_idx++]=current+1;
        }
        if(j-1>=0 && visited[(j-1)*N+i]==0 && grid[j-1][i]==1){ // check top neighbor
            visited[(j-1)*N+i]=1;
            stack[stack_idx++]=current-N;
        }
        if(j+1<N && visited[(j+1)*N+i]==0 && grid[j+1][i]==1){ // check bottom neighbor
            visited[(j+1)*N+i]=1;
            stack[stack_idx++]=current+N;
        }
    }
  
    for(int i=0;i<bottom_idx;i++){
        if(visited[N*(N-1)+bottom[i]]==1){ // bottom row is connected to top row
            return 1;
        }
    }
  
    return 0; // bottom row is not connected to top row
}

int main(){
    srand(time(NULL));
    int grid[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j]=rand()%2; // randomly fill in 0s and 1s
        }
    }
    printf("Initial grid:\n");
    print_grid(grid);
    if(percolates(grid)){
        printf("The grid percolates!\n");
    }
    else{
        printf("The grid does not percolate.\n");
    }
    return 0;
}