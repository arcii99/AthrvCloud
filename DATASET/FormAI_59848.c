//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5 // size of the bingo board
#define MAX_NUMBERS 75 // maximum possible numbers in the game
#define NUM_PLAYERS 2 // number of players in the game

// function signature
void initializeBoard(int board[][BOARD_SIZE]);
int drawNumber(int numbersDrawn[], int counter);
void printBoard(int board[][BOARD_SIZE]);
void markNumber(int board[][BOARD_SIZE], int number);
int checkForBingo(int board[][BOARD_SIZE]);

// main function
int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    int numbersDrawn[MAX_NUMBERS]; // store the numbers drawn so far
    int counter = 0; // keep track of how many numbers have been drawn
    int currentPlayer = 0; // alternating between two players

    // initialize random seed
    srand(time(NULL));

    // initialize the board and print it out
    initializeBoard(board);
    printBoard(board);

    // main game loop
    while(1) {
        int number = drawNumber(numbersDrawn, counter);
        printf("Number drawn: %d\n", number);
        markNumber(board, number);
        printBoard(board);

        // check for bingo
        if(checkForBingo(board)) {
            printf("Bingo! Player %d wins!\n", currentPlayer + 1);
            break;
        }

        // switch to the other player
        currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;

        // increment the counter
        counter++;
    }

    return 0;
}

// function definitions

// initializeBoard: initializes the board with random numbers
void initializeBoard(int board[][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            // generate a random number that is not already on the board
            int randNum;
            do {
                randNum = rand() % 15 + 1 + 15*j;
            } while(board[i][j] == randNum);
            board[i][j] = randNum;
        }
    }
}

// drawNumber: randomly selects a number that has not already been drawn
int drawNumber(int numbersDrawn[], int counter) {
    int randNum;
    do {
        randNum = rand() % MAX_NUMBERS + 1;
    } while(numbersDrawn[randNum] == 1);
    numbersDrawn[randNum] = 1;
    return randNum;
}

// printBoard: prints out the current state of the board
void printBoard(int board[][BOARD_SIZE]) {
    int i, j;
    printf("-----------------\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == -1) {
                printf("   |");
            } else {
                printf(" %2d|", board[i][j]);
            }
        }
        printf("\n-----------------\n");
    }
    printf("\n");
}

// markNumber: marks the number on the board
void markNumber(int board[][BOARD_SIZE], int number) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == number) {
                board[i][j] = -1; // mark the number on the board
                return;
            }
        }
    }
}

// checkForBingo: checks if any player has bingo
int checkForBingo(int board[][BOARD_SIZE]) {
    int i, j;
    int rowCount = 0, colCount = 0, diagCount = 0;

    // check rows
    for(i = 0; i < BOARD_SIZE; i++) {
        int rowSum = 0;
        for(j = 0; j < BOARD_SIZE; j++) {
            rowSum += board[i][j];
        }
        if(rowSum == -5) {
            rowCount++;
        }
    }

    // check columns
    for(j = 0; j < BOARD_SIZE; j++) {
        int colSum = 0;
        for(i = 0; i < BOARD_SIZE; i++) {
            colSum += board[i][j];
        }
        if(colSum == -5) {
            colCount++;
        }
    }

    // check diagonals
    int diagSum1 = 0, diagSum2 = 0;
    for(i = 0; i < BOARD_SIZE; i++) {
        diagSum1 += board[i][i];
        diagSum2 += board[i][BOARD_SIZE-1-i];
    }
    if(diagSum1 == -5 || diagSum2 == -5) {
        diagCount++;
    }

    // check all possible bingos
    if(rowCount > 0 || colCount > 0 || diagCount > 0) {
        return 1;
    } else {
        return 0;
    }
}