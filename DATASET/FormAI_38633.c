//FormAI DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main(){
    int board[ROWS][COLS];
    int i, j, k, l, temp, count = 0;
    char input[50];
    srand(time(NULL));
    
    // Initialize board with random numbers from 0-9
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
    
    // Shuffle board by swapping random elements
    for(k = 0; k < ROWS; k++) {
        for(l = 0; l < COLS; l++) {
            i = rand() % ROWS;
            j = rand() % COLS;
            temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
    
    // Prompt user to input each element
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("Enter element (%d,%d): ", i+1, j+1);
            scanf("%s", input); // read input as string
            if(atoi(input) == board[i][j]) {
                count++; // increment count if input matches board element
            }
        }
    }
    
    // Print final score
    printf("You scored %d out of %d.\n", count, ROWS*COLS);
    
    return 0;
}