//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#define WIN 1
#define LOSE 0
#define N 5

int maze[N][N] = {   {1,1,1,0,0},
                     {0,0,1,1,0},
                     {0,0,1,0,0},
                     {0,1,1,1,1},
                     {0,0,1,0,1}};

int visited_nodes[N][N];
int solution[N][N];

//Function to check whether the current cell lies inside the maze or not
int isValid(int i,int j){  
    if(i<0 || i>=N ||j<0 || j>=N){  
        return 0;  
    }
    return 1; 
}  

//recursive function to find path in the maze
int findPath(int i,int j){
    if(i==N-1 && j==N-1){
        solution[i][j]=1;
        return WIN;
    }
    if(isValid(i,j)==1 && maze[i][j]==1 && visited_nodes[i][j]==0){
        visited_nodes[i][j] = 1;
        solution[i][j]=1;
        if(findPath(i-1,j)==WIN || findPath(i,j+1)==WIN || findPath(i+1,j)==WIN || findPath(i,j-1)==WIN){
            return WIN;
        }
        solution[i][j]=0;
        return LOSE;
    }
    return LOSE;
}

//function to print solution matrix
void printSolution(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf(" %d ",solution[i][j]);
        }
        printf("\n");
    }
}

int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited_nodes[i][j] = 0;
            solution[i][j] = 0;
        }
    }
    
    if(findPath(0,0)==WIN){
        printf("Path found in the Maze!\n");
        printSolution();
    }
    else{
         printf("No Path Found in the Maze!\n");
    }

    return 0;
}