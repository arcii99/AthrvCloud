//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 // size of grid
#define p 0.6 // probability of site being open
#define CLOSED 0
#define OPEN 1
#define PERCOLATED 2

int arr[N][N]; //grid 
int state;     //percolation state

//to check if a site is open
int isOpen(int i, int j){
    if(arr[i][j]==OPEN) return 1;
    return 0;
}

//to check if a site percolates
void percolate(int i, int j){
    if(i==N-1) state=PERCOLATED;  //bottom row reached
    if(j-1>=0){                   //check left site
        if(isOpen(i,j-1)) percolate(i,j-1);
    }
    if(j+1<N){                    //check right site
        if(isOpen(i,j+1)) percolate(i,j+1);
    }
    if(i-1>=0){                   //check top site
        if(isOpen(i-1,j)) percolate(i-1,j);
    }
    if(i+1<N){                    //check bottom site
        if(isOpen(i+1,j)) percolate(i+1,j);
    }
}

int main(){
    srand(time(NULL));   //seed for random function
    int i,j;
    float x;
    //initialize grid
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            x=(float)rand()/(float)(RAND_MAX); //generate random number
            if(x>p) arr[i][j]=CLOSED;         //assign CLOSED state
            else arr[i][j]=OPEN;              //assign OPEN state
        }
    }
    //print initial grid
    printf("Initial Grid:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    //percolate grid
    for(j=0;j<N;j++){
        if(isOpen(0,j)) percolate(0,j);
    }
    //print percolation state and grid
    if(state==PERCOLATED) printf("\nGrid percolates!\n");
    else printf("\nGrid does not percolate.\n");
    printf("\nFinal Grid:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}