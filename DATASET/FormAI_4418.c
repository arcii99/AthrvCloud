//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number within a specified range
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int board[5][5] = {0}; //initialize the board with all zeros
    int numbers[75] = {0}; //to keep track of numbers already called
    int currentNumber = -1; //initialize to an invalid value
    
    srand(time(0)); //seed the random number generator with the current time
    
    printf("Welcome to Bingo Simulator!\n\n");
    
    //populate the numbers array with numbers between 1 and 75
    for(int i=0; i<75; i++) {
        numbers[i] = i+1;
    }
    
    //shuffle the numbers array using Fisher-Yates algorithm
    for(int i=74; i>=1; i--) {
        int j = generateRandom(0, i);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    //print the board
    printf("   B   I   N   G   O\n");
    for(int i=0; i<5; i++) {
        printf("--------------------\n");
        for(int j=0; j<5; j++) {
            if(i == 2 && j == 2) {
                printf("| X ");
            } else {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("--------------------\n");
    
    //start calling numbers
    for(int i=0; i<75; i++) {
        currentNumber = numbers[i];
        printf("Next number is: %d\n", currentNumber);
        
        //check if the number is on the board
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                if(board[j][k] == currentNumber) {
                    board[j][k] = -1; //mark the number as called
                }
            }
        }
        
        //print the updated board
        printf("   B   I   N   G   O\n");
        for(int j=0; j<5; j++) {
            printf("--------------------\n");
            for(int k=0; k<5; k++) {
                if(board[j][k] == -1) {
                    printf("| X ");
                } else {
                    printf("| %d ", board[j][k]);
                }
            }
            printf("|\n");
        }
        printf("--------------------\n");
        
        //check for a bingo
        int rowBingo = 0;
        int colBingo = 0;
        int diagBingo = 0;
        
        //check rows and columns for a bingo
        for(int j=0; j<5; j++) {
            rowBingo = 1;
            colBingo = 1;
            for(int k=0; k<5; k++) {
                if(board[j][k] != -1) {
                    rowBingo = 0;
                }
                if(board[k][j] != -1) {
                    colBingo = 0;
                }
            }
            if(rowBingo == 1 || colBingo == 1) {
                printf("We have a BINGO!\n");
                return 0;
            }
        }
        
        //check diagonals for a bingo
        diagBingo = 1;
        for(int j=0; j<5; j++) {
            if(board[j][j] != -1) {
                diagBingo = 0;
            }
        }
        if(diagBingo == 1) {
            printf("We have a BINGO!\n");
            return 0;
        }
        
        diagBingo = 1;
        for(int j=0; j<5; j++) {
            if(board[j][4-j] != -1) {
                diagBingo = 0;
            }
        }
        if(diagBingo == 1) {
            printf("We have a BINGO!\n");
            return 0;
        }
    }
    printf("Sorry, no one won this round of Bingo.\n");
    return 0;
}