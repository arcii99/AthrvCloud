//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ROWS 100
#define COLS 10

// function to generate random data
void generateData(int data[ROWS][COLS]){
    srand(time(NULL));  // initialize random seed
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            data[i][j] = rand() % 100;  // generate random number between 0 and 99
        }
    }
}

// function to calculate mean of a column
float mean(int col, int data[ROWS][COLS]){
    float sum = 0.0;
    for(int i=0; i<ROWS; i++){
        sum += data[i][col];
    }
    return sum/ROWS;
}

// function to calculate standard deviation of a column
float stdDev(int col, int data[ROWS][COLS]){
    float sum = 0.0;
    float average = mean(col, data);

    for(int i=0; i<ROWS; i++){
        sum += (data[i][col] - average) * (data[i][col] - average);
    }
    return sqrt(sum/(ROWS-1));
}

int main(){
    int data[ROWS][COLS];
    generateData(data);

    printf("Data mining example program\n\n");

    // print header
    printf("%-10s", "Column");
    for(int i=0; i<COLS; i++){
        printf("%-5d", i+1);
    }
    printf("\n");

    // print mean
    printf("%-10s", "Mean");
    for(int i=0; i<COLS; i++){
        printf("%-5.1f", mean(i, data));
    }
    printf("\n");

    // print standard deviation
    printf("%-10s", "Std Dev");
    for(int i=0; i<COLS; i++){
        printf("%-5.1f", stdDev(i, data));
    }
    printf("\n");

    return 0;
}