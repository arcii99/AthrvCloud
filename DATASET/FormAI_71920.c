//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS], int* numbers) {
    printf("B     I     N     G     O\n");
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            if(board[i][j]) {
                printf("%-3d   ",board[i][j]);
            }
            else {
                printf("%-3d   ",*(numbers+i*COLS+j));
            }
        }
        printf("\n");
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleArray(int *array, int size) {
    srand(time(NULL));
    for(int i=size-1;i>0;i--) {
        int j = rand()%(i+1);
        swap(array+i,array+j);
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    int numbers[ROWS*COLS] = {0};
    for(int i=0;i<ROWS*COLS;i++) {
        *(numbers+i) = i+1;
    }
    shuffleArray(numbers,ROWS*COLS);
    printBoard(board,numbers);
    int bingo = 0, turnNumber = 1, numSelected = 0, num;
    while(!bingo && turnNumber <= ROWS*COLS) {
        printf("\nTurn %d: Enter a number: ",turnNumber);
        scanf("%d",&num);
        int flag = 0;
        for(int i=0;i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {
                if(board[i][j] == num) {
                    printf("Number already selected! Try again.\n");
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) continue; // Invalid input. Number already on the board.
        numSelected = -1; // Flag to check if the entered number exists in the list of random numbers.
        for(int i=0;i<ROWS*COLS;i++) {
            if(*(numbers+i) == num) {
                int row = i/COLS;
                int col = i%COLS;
                board[row][col] = num;
                numSelected = i;
                break;
            }
        }
        if(numSelected == -1) {
            printf("Invalid entry!\n");
            continue;
        }
        printf("\n");
        printBoard(board,numbers);
        int flagRow = 0, flagCol = 0, flagLeftDiag = 0, flagRightDiag = 0;
        for(int i=0;i<ROWS;i++) {
            int flagR = 0, flagC = 0;
            // Checking for row
            for(int j=0;j<COLS;j++) {
                if(board[i][j] == 0) {
                    flagR = 1;
                    break;
                }
            }
            if(!flagR) {
                flagRow = 1;
                break;
            }
            // Checking for column
            for(int j=0;j<ROWS;j++) {
                if(board[j][i] == 0) {
                    flagC = 1;
                    break;
                }
            }
            if(!flagC) {
                flagCol = 1;
                break;
            }
        }
        // Checking left diagonal
        int flag1 = 0, flag2 = 0;
        for(int i=0;i<ROWS;i++) {
            if(board[i][i] == 0) {
                flag1 = 1;
                break;
            }
        }
        if(!flag1) {
            flagLeftDiag = 1;
        }
        // Checking right diagonal
        for(int i=0, j=COLS-1;i<ROWS && j>=0;i++,j--) {
            if(board[i][j] == 0) {
                flag2 = 1;
                break;
            }
        }
        if(!flag2) {
            flagRightDiag = 1;
        }
        if(flagRow || flagCol || flagLeftDiag || flagRightDiag) {
            bingo = 1;
            printf("\nCongratulations! You got BINGO!\n");
        }
        turnNumber++;
    }
    if(!bingo) {
        printf("\nSorry! Better luck next time!\n");
    }
    return 0;
}