//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
//Asynchronous Game of Life Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

//Function to initialize the grid randomly
void initialize(int grid[][50]){
    int i,j;
    srand(time(NULL));
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            grid[i][j]=rand()%2;
        }
    }
}

//Function to print the grid
void printGrid(int grid[][50]){
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            if(grid[i][j]==0){
                printf(".");
            }
            else if(grid[i][j]==1){
                printf("*");
            }
        }
        printf("\n");
    }
}

//Function to count the number of living neighbors
int countNeighbors(int grid[][50],int x,int y){
    int count=0,i,j;

    for(i=x-1;i<=x+1;i++){
        for(j=y-1;j<=y+1;j++){
            if(i==x && j==y){
                continue;
            }
            if(i>=0 && j>=0 && i<50 && j<50){
                count+=grid[i][j];
            }
        }
    }

    return count;
}

//Function to update the grid
void updateGrid(int grid[][50]){
    int newGrid[50][50];
    int i,j,neighbors;

    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            neighbors=countNeighbors(grid,i,j);
            if(grid[i][j]==1){
                if(neighbors<2){
                    newGrid[i][j]=0;
                }
                else if(neighbors>3){
                    newGrid[i][j]=0;
                }
                else{
                    newGrid[i][j]=1;
                }
            }
            else if(grid[i][j]==0){
                if(neighbors==3){
                    newGrid[i][j]=1;
                }
                else{
                    newGrid[i][j]=0;
                }
            }
        }
    }

    memcpy(grid,newGrid,sizeof(grid));
}

//Signal handler function to interrupt the infinite loop
void signalHandler(int signum){
    printf("Interrupted\n");
    exit(signum);
}

int main(){
    int grid[50][50];
    sigset_t sigset;

    signal(SIGINT,signalHandler);

    //Initializing the grid
    initialize(grid);

    //Printing the initial grid
    printGrid(grid);

    //Waiting for 2 seconds
    sleep(2);

    //Clearing the screen
    system("clear");

    //Updating the grid in a loop
    while(1){
        //Updating the grid
        updateGrid(grid);

        //Printing the updated grid
        printGrid(grid);

        //Waiting for 0.1 second
        usleep(100000);

        //Clearing the screen
        system("clear");

        //Checking for signal interruption
        sigemptyset(&sigset);
        sigaddset(&sigset,SIGINT);
        sigprocmask(SIG_BLOCK,&sigset,NULL);
        sigsuspend(&sigset);
        sigprocmask(SIG_UNBLOCK,&sigset,NULL);
    }

    return 0;
}