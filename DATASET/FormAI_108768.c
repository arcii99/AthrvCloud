//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

int open[ROWS][COLS];
int connected[ROWS*COLS];

//check if two sites are connected
int isConnected(int x1, int y1, int x2, int y2){
    int index1 = COLS*x1 + y1;
    int index2 = COLS*x2 + y2;
    return connected[index1] == connected[index2];
}

//update the connected array and check if any new site is opened
int update(int x, int y, int id){
    int count_new_open = 0;
    int index = COLS*x + y;
    int neighbors[4][2] = {{x-1,y},{x,y-1},{x+1,y},{x,y+1}};
    connected[index] = id;
    for(int i=0;i<4;i++){
        int x1 = neighbors[i][0];
        int y1 = neighbors[i][1];
        if(x1>=0 && x1<ROWS && y1>=0 && y1<COLS && open[x1][y1]){
            if(!isConnected(x,y,x1,y1)){
                count_new_open++;
                int index1 = COLS*x1 + y1;
                connected[index1] = id;
            }
        }
    }
    return count_new_open;
}

//perform percolation until the system percolates
void percolate(){
    int id = 1;
    int opened = 0;
    while(1){
        //randomly open a site
        int x = rand()%ROWS;
        int y = rand()%COLS;
        if(open[x][y]){
            continue;
        }
        open[x][y] = 1;
        opened++;
        //update the connected array and check if any new site is opened
        int count_new_open = update(x,y,id);
        if(opened==ROWS*COLS){
            printf("Percolation achieved!\n");
            break;
        }
        //if no new site is opened, increment the id
        if(count_new_open==0){
            id++;
        }
    }
}

//print the percolating system
void printSystem(){
    printf("\n");
    for(int i=0;i<COLS+2;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<ROWS;i++){
        printf("|");
        for(int j=0;j<COLS;j++){
            if(open[i][j]){
                printf(" ");
            }else{
                printf("#");
            }
        }
        printf("|\n");
    }
    for(int i=0;i<COLS+2;i++){
        printf("-");
    }
    printf("\n");
}

int main(){
    //set the random seed based on time
    srand(time(NULL));
    //initialize the open and connected arrays
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            open[i][j] = 0;
            connected[COLS*i+j] = -1;
        }
    }
    //perform percolation and print the percolating system
    percolate();
    printSystem();
    return 0;
}