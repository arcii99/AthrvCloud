//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int board[ROWS][COLS]; // initialize the board

    // randomize the board by generating unique numbers between 1 and 25
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % 25 + 1; // generates a number between 1 and 25
            } while (isUnique(board, i, j, num) == 0); // checks if num is not already in the board
            board[i][j] = num; // assign the unique number to the board
        }
    }

    // print the board
    printBoard(board);

    // play the game
    int numCalls = 0;
    int called[25] = {0}; // initialize the called numbers as all uncalled
    int running = 1; // game is running until someone gets a bingo
    while (running) {
        int num = chooseNumber(called); // choose a number that has not been called yet
        called[num - 1] = 1; // mark the number as called
        numCalls++;
        printf("Number called: %d\n", num);
        updateBoard(board, num); // update the board if necessary
        printBoard(board);
        if (checkBingo(board)) { // check if someone has a bingo
            int winner = (numCalls % 2) + 1; // determine the winner based on the number of calls
            printf("Player %d gets a bingo in %d calls!\n", winner, numCalls);
            running = 0; // game is over
        }
    }

    return 0;
}

int isUnique(int board[][COLS], int row, int col, int num) {
    // checks if num is not already in the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i != row || j != col) && board[i][j] == num) {
                return 0; // num is not unique
            }
        }
    }
    return 1; // num is unique
}

void printBoard(int board[][COLS]) {
    // prints the board in a 5x5 format
    printf("BINGO BOARD\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int chooseNumber(int called[]) {
    // chooses a number that has not been called yet
    int num;
    do {
        num = rand() % 25 + 1; // generates a number between 1 and 25
    } while (called[num - 1] == 1); // checks if the number has already been called
    return num;
}

void updateBoard(int board[][COLS], int num) {
    // updates the board if num is found
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                board[i][j] = 0; // mark the number as found
                break;
            }
        }
    }
}

int checkBingo(int board[][COLS]) {
    // checks if someone has a bingo
    // checks horizontal lines
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                count++;
            } else {
                break;
            }
        }
        if (count == COLS) {
            return 1; // bingo found
        }
    }
    // checks vertical lines
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] == 0) {
                count++;
            } else {
                break;
            }
        }
        if (count == ROWS) {
            return 1; // bingo found
        }
    }
    // checks diagonals
    if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
        return 1; // bingo found in diagonal
    }
    if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
        return 1; // bingo found in diagonal
    }
    return 0; // no bingo found
}