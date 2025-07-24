//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5
#define SIZE 25
#define MAXCALLS 75

void printBoard(int board[ROWS][COLS]) {
    printf("\n --------- BINGO BOARD --------- \n\n");
    printf("   B   I   N   G   O\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(j == 2 && i == 2) {
                printf("  FREE");
            } else {
                printf("%4d", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n -------------------------------- \n");
}

int callNumber(int calledNumbers[MAXCALLS], int numCalls) {
    int call;
    do {
        call = rand() % MAXCALLS + 1;
    } while(calledNumbers[call] != 0); // ensure the number hasn't been called
    calledNumbers[call] = 1; // mark the number as called
    numCalls++; // increment number of calls
    return call;
}

int checkWinner(int board[ROWS][COLS]) {
    int winner = 0;
    for(int i=0; i<ROWS; i++) { // check rows
        int count = 0;
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == -1) { // check if the number has been called
                count++;
            }
        }
        if(count == COLS) { // if all numbers have been called in a row, we have a winner
            winner = 1;
            break;
        }
    }
    if(!winner) {
        for(int j=0; j<COLS; j++) { // check columns
            int count = 0;
            for(int i=0; i<ROWS; i++) {
                if(board[i][j] == -1) {
                    count++;
                }
            }
            if(count == ROWS) {
                winner = 1;
                break;
            }
        }
    }
    if(!winner) { // check diagonals
        int count = 0;
        for(int i=0; i<ROWS; i++) {
            if(board[i][i] == -1) {
                count++;
            }
        }
        if(count == ROWS) {
            winner = 1;
        }
    }
    if(!winner) {
        int count = 0;
        for(int i=0; i<ROWS; i++) {
            if(board[i][COLS-1-i] == -1) {
                count++;
            }
        }
        if(count == ROWS) {
            winner = 1;
        }
    }
    return winner;
}

int main() {
    srand(time(NULL)); // seed random number generator
    int board[ROWS][COLS];
    int calledNumbers[MAXCALLS] = {0}; // array to keep track of called numbers
    int numCalls = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = i*5 + j + 1; // assign values to the board
        }
    }
    printBoard(board); // print the initial board
    while(1) { // main game loop
        int call = callNumber(calledNumbers, numCalls);
        printf("\n\n The number called is: %d", call);
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == call) {
                    board[i][j] = -1; // mark the number as called
                    printBoard(board); // print the updated board
                    if(checkWinner(board)) { // check if we have a winner
                        printf("\n\n BINGO! You have won!\n\n");
                        return 0;
                    }
                }
            }
        }
        if(numCalls == MAXCALLS) { // if we've called all numbers, it's a draw
            printf("\n\n It's a draw!\n\n");
            return 0;
        }
    }
    return 0;
}