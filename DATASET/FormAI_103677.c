//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateBingoBoard(int board[][COLS]);
void printBingoBoard(int board[][COLS]);
void callNumber(int *numCalled, int calledList[]);
int checkBingo(int board[][COLS], int calledList[]);

int main() {
    int board[ROWS][COLS];
    int calledList[ROWS * COLS] = {0};
    int numCalled = 0;
    srand(time(NULL));
    
    generateBingoBoard(board);
    printBingoBoard(board);
    
    while (!checkBingo(board, calledList)) {
        callNumber(&numCalled, calledList);
    }
    
    printf("\nBingo!\nNumbers called: ");
    for (int i = 0; i < numCalled; i++) {
        printf("%d ", calledList[i]);
    }
    
    return 0;
}

void generateBingoBoard(int board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        int min = row * 15 + 1;
        int max = min + 14;
        int usedNums[COLS];
        
        for (int col = 0; col < COLS; col++) {
            int num = rand() % (max - min + 1) + min;
            int alreadyUsed = 0;
            
            for (int i = 0; i < col; i++) {
                if (num == usedNums[i]) {
                    alreadyUsed = 1;
                    break;
                }
            }
            
            if (alreadyUsed) {
                col--;
                continue;
            }
            
            usedNums[col] = num;
            board[row][col] = num;
        }
    }
    
    board[2][2] = -1; // Free space
}

void printBingoBoard(int board[][COLS]) {
    printf("BINGO BOARD:\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == -1) {
                printf("[   ]\t");
            } else {
                printf("[%2d]\t", board[row][col]);
            }
        }
        printf("\n");
    }
}

void callNumber(int *numCalled, int calledList[]) {
    int number = rand() % 75 + 1;
    
    for (int i = 0; i < *numCalled; i++) {
        if (number == calledList[i]) {
            callNumber(numCalled, calledList);
            return;
        }
    }
    
    calledList[*numCalled] = number;
    (*numCalled)++;
}

int checkBingo(int board[][COLS], int calledList[]) {
    int rowSum[ROWS] = {0};
    int colSum[COLS] = {0};
    int diagSum1 = 0;
    int diagSum2 = 0;
    
    // Check rows and columns
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == -1 || !numCalled(board[row][col], calledList)) {
                break;
            }
            
            rowSum[row] += board[row][col];
            colSum[col] += board[row][col];
        }
    }
    
    // Check diagonal from top-left to bottom-right
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] == -1 || !numCalled(board[i][i], calledList)) {
            break;
        }
        
        diagSum1 += board[i][i];
    }
    
    // Check diagonal from top-right to bottom-left
    for (int i = 0; i < ROWS; i++) {
        if (board[i][COLS - i - 1] == -1 || !numCalled(board[i][COLS - i - 1], calledList)) {
            break;
        }
        
        diagSum2 += board[i][COLS - i - 1];
    }
    
    // Check for bingo
    for (int i = 0; i < ROWS; i++) {
        if (rowSum[i] == 5 * ROWS || colSum[i] == 5 * COLS || diagSum1 == 5 * ROWS || diagSum2 == 5 * ROWS) {
            return 1;
        }
    }
    
    return 0;
}

int numCalled(int number, int calledList[]) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (number == calledList[i]) {
            return 1;
        }
    }
    
    return 0;
}