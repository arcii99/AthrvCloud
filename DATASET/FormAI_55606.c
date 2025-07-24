//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define ROWS 5
#define COLS 5

int main() 
{ 
    int i, j, k; 
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int bingo[ROWS][COLS];
    int numDrawn[ROWS*COLS];
    int numCount = 0;
    int bingoStatus = 0;
    srand(time(NULL)); 

    //initialize bingo card with random numbers
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            bingo[i][j] = rand() % 100 + 1;
        }
    }
    
    //print header
    printf("\n\t\t\tB I N G O\n\n");
    
    //print bingo card
    for(i = 0; i < ROWS; i++) {
        printf("\t\t");
        for(j = 0; j < COLS; j++) {
            printf("%d\t", bingo[i][j]);
        }
        printf("\n\n");
    }
    
    //draw numbers
    printf("\n\nDrawing numbers...\n\n");
    while(numCount < ROWS*COLS) {
        int num = rand() % 100 + 1;
        int found = 0;
        for(k = 0; k < numCount; k++) {
            if(numDrawn[k] == num) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            numDrawn[numCount] = num;
            numCount++;
            printf("%d\t", num);
            //check for bingo
            for(i = 0; i < ROWS; i++) {
                int rowMatch = 0;
                int colMatch = 0;
                for(j = 0; j < COLS; j++) {
                    if(num == bingo[i][j]) {
                        rowMatch++;
                    }
                    if(num == bingo[j][i]) {
                        colMatch++;
                    }
                }
                if(rowMatch == ROWS || colMatch == COLS) {
                    bingoStatus = 1;
                }
            }
            if(bingoStatus == 1) {
                printf("\n\nBINGO!\n\n");
                break;
            }
        }
    }
    if(bingoStatus == 0) {
        printf("\n\nNo bingo. Please play again.\n\n");
    }
    return 0; 
}