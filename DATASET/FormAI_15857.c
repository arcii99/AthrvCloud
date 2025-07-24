//FormAI DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

int nextGen[ROWS][COLUMNS]; //Array to hold next generation

//Function to print the current generation
void printGen(int currGen[ROWS][COLUMNS]){
    printf("\nCurrent Generation:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            printf("%d ", currGen[i][j]);
        }
        printf("\n");
    }
}

//Function to calculate the next generation
void calcNextGen(int currGen[ROWS][COLUMNS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            //Calculate the sum of the surrounding cells
            int sum = 0;
            for(int m=-1; m<=1; m++){
                for(int n=-1; n<=1; n++){
                    sum += currGen[(i+m+ROWS)%ROWS][(j+n+COLUMNS)%COLUMNS];
                }
            }
            sum -= currGen[i][j];
            
            //Apply Game of Life rules
            if(currGen[i][j] == 1 && (sum < 2 || sum > 3)){
                nextGen[i][j] = 0;
            }
            else if(currGen[i][j] == 0 && sum == 3){
                nextGen[i][j] = 1;
            }
            else{
                nextGen[i][j] = currGen[i][j];
            }
        }
    }
    
    //Copy next generation to current generation
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            currGen[i][j] = nextGen[i][j];
        }
    }
}

int main(){
    //Initialize current generation randomly
    int currGen[ROWS][COLUMNS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            currGen[i][j] = rand() % 2;
        }
    }
    
    //Print the current generation and calculate the next generation
    printGen(currGen);
    calcNextGen(currGen);
    
    return 0;
}