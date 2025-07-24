//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define MAX_COLS 15

int main() {
    srand(time(NULL));
    int numbers[75] = {0}; // array to hold all possible numbers
    int card[ROWS][MAX_COLS] = {0}; // array to hold the bingo card
    int currentNumber = 0;
    int cols[MAX_COLS] = {0}; // array to hold the number of used columns
    int numCols = 0; // number of current used columns
    
    // initialize numbers array with possible values (1-75)
    for(int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }
    
    // shuffle the numbers array
    for(int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    // generate bingo card
    for(int i = 0; i < ROWS; i++) {
        while(numCols < MAX_COLS) {
            int j = rand() % 15;
            if(cols[j] == 0) { // if column is not used yet
                cols[j] = 1;
                numCols++;
                for(int k = 0; k < ROWS; k++) {
                    card[k][j] = numbers[currentNumber++];
                }
            }
        }
        numCols = 0;
    }
    
    // print bingo card
    printf("B   I   N   G   O\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < MAX_COLS; j++) {
            if(j == 2) {
                printf("  ");
            }
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}