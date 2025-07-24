//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void welcomeMessage(){
    printf("Let's play Bingo!\n\n");
}

void printBoard(int board[ROWS][COLS], int numCalls){
    int i, j;
    printf("Current Bingo Board (with %d numbers called):\n", numCalls);
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(board[i][j] == -1){
                printf("    ");
            } else {
                printf("%2d  ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void generateRandomNumbers(int *nums, int count){
    int i, j, duplicate;
    srand(time(NULL));
    for(i = 0; i < count; i++){
        do {
            duplicate = 0;
            nums[i] = rand() % 75 + 1;
            for(j = 0; j < i; j++){
                if(nums[j] == nums[i]){
                    duplicate = 1;
                    break;
                }
            }
        } while(duplicate);
    }
}

int markBoard(int board[ROWS][COLS], int num){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(board[i][j] == num){
                board[i][j] = -1;
                return 1;
            }
        }
    }
    return 0;
}

int checkRow(int board[ROWS][COLS], int row){
    int i;
    for(i = 0; i < COLS; i++){
        if(board[row][i] != -1){
            return 0;
        }
    }
    return 1;
}

int checkCol(int board[ROWS][COLS], int col){
    int i;
    for(i = 0; i < ROWS; i++){
        if(board[i][col] != -1){
            return 0;
        }
    }
    return 1;
}

int checkDiags(int board[ROWS][COLS]){
    int i;
    // Check top-left to bottom-right diagonal
    for(i = 0; i < ROWS; i++){
        if(board[i][i] != -1){
            break;
        }
    }
    if(i == ROWS){
        return 1;
    }
    // Check top-right to bottom-left diagonal
    for(i = 0; i < ROWS; i++){
        if(board[i][COLS-1-i] != -1){
            break;
        }
    }
    if(i == ROWS){
        return 1;
    }
    return 0;
}

int checkBingo(int board[ROWS][COLS]){
    int i;
    for(i = 0; i < ROWS; i++){
        if(checkRow(board, i)){
            return 1;
        }
    }
    for(i = 0; i < COLS; i++){
        if(checkCol(board, i)){
            return 1;
        }
    }
    if(checkDiags(board)){
        return 1;
    }
    return 0;
}

int main(){
    int board[ROWS][COLS];
    int calledNums[75];
    int numCalls = 0;
    int i, j;
    // Initialize board to all zeros
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = 0;
        }
    }

    // Start game
    welcomeMessage();
    while(1){
        generateRandomNumbers(calledNums, 1);
        numCalls++;
        if(markBoard(board, calledNums[0])){
            printf("Number called: %d\n", calledNums[0]);
            printBoard(board, numCalls);
            if(checkBingo(board)){
                printf("BINGO!!\n");
                break;
            }
        }
    }

    return 0;
}