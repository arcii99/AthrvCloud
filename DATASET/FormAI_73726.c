//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

void printgrid(int arr[][N]){
    for(int i =0; i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolation(int arr[][N]){
    int top[N][N] = {0}; //array to check if a site is connected to the top
    int bottom[N][N] = {0}; //array to check if a site is connected to the bottom
    int is_percolating = 0; //flag to check if the system is percolating
    for(int j=0;j<N;j++){ //checking the top row of the grid
        if(arr[0][j]==1){
            top[0][j]=1;
        }
    }
    for(int i=1;i<N;i++){
        for(int j=0; j<N ;j++){
            if(arr[i][j]==1){
                if(j-1>=0 && top[i-1][j-1]==1){ //checking northwest site
                    top[i][j] = 1;
                }
                if(top[i-1][j]==1){ //checking north site
                    top[i][j] = 1;
                }
                if(j+1<N && top[i-1][j+1]==1){ //checking northeast site
                    top[i][j] = 1;
                }
                if(i==N-1){ //if the current site is on the bottom row
                    if(top[i][j]==1){
                        is_percolating = 1;
                    }
                }
            }
        }
    }
    for(int j=0;j<N;j++){ //checking the bottom row of the grid
        if(top[N-1][j]==1){
            bottom[N-1][j]=1;
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=0; j<N ;j++){
            if(arr[i][j]==1){
                if(j-1>=0 && bottom[i+1][j-1]==1){ //checking southwest site
                    bottom[i][j] = 1;
                }
                if(bottom[i+1][j]==1){ //checking south site
                    bottom[i][j] = 1;
                }
                if(j+1<N && bottom[i+1][j+1]==1){ //checking southeast site
                    bottom[i][j] = 1;
                }
                if(i==0){ //if the current site is on the top row
                    if(bottom[i][j]==1){
                        is_percolating = 1;
                    }
                }
            }
        }
    }
    printgrid(top); //printing the top array
    printgrid(bottom); //printing the bottom array
    return is_percolating; //returning the flag
}

int main(){
    srand(time(NULL)); //seeding the random number generator with current time
    int arr[N][N] = {0}; //initializing the grid with all sites closed
    int open_sites = 0; //count of open sites
    while(1){
        int i = rand() % N; //generating random row index
        int j = rand() % N; //generating random column index
        if(arr[i][j]==0){ //if the site is closed
            arr[i][j] = 1; //open the site
            open_sites++;
        }
        if(percolation(arr)==1){ //if the system is percolating
            break; //stop the loop
        }
    }
    printgrid(arr); //printing the final grid
    printf("Number of open sites: %d",open_sites);
    return 0;
}