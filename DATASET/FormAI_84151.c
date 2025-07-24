//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define ROWS 10
#define COLS 10

bool isOpen[ROWS][COLS];
bool isFull[ROWS][COLS];

void initialize(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            isOpen[i][j] = false;
            isFull[i][j] = false;
        }
    }
}

void printGrid(){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(isFull[i][j])
                printf(" X ");
            else if(isOpen[i][j])
                printf(" 0 ");
            else
                printf(" 1 ");
        }
        printf("\n");
    }
}

bool isPercolating(){
    for(int j = 0; j < COLS; j++){
        if(isFull[ROWS - 1][j])
            return true;
    }
    return false;
}

void percolate(int i, int j){
    if(i < 0 || i >= ROWS || j < 0 || j >= COLS || !isOpen[i][j] || isFull[i][j])
        return;
    isFull[i][j] = true;
    percolate(i-1,j); // up
    percolate(i+1,j); // down
    percolate(i,j-1); // left  
    percolate(i,j+1); // right   
}

void simulate(float p){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            // random site is open with probability p
            isOpen[i][j] = ((double)rand() / (RAND_MAX)) <= p;
        }
    }
    for(int j = 0; j < COLS; j++){
        if(isOpen[0][j])
            percolate(0,j);
    }
}

int main(){
    srand(time(NULL));
    initialize();
    float p = 0.6;
    simulate(p);
    printGrid();
    if(isPercolating())
        printf("The system is percolating\n");
    else
        printf("The system is not percolating\n");
    return 0;
}