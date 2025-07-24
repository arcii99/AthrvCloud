//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAXIMUM_VALUE 25

int main()
{
    int board[ROWS][COLS], i, j, number, count = 0;
    int bingo[ROWS + COLS + 2] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Loop through the board and fill it with random numbers
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            do {
                number = rand() % MAXIMUM_VALUE + 1;
            } while(numberExists(number, board));
            board[i][j] = number;
            count++;
        }
    }

    // Print the board
    printf("Bingo Board:\n");
    printBoard(board);

    // Loop through the board and mark matching numbers
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            markBingo(board[i][j], bingo, i, j);
            if(checkBingo(bingo)) {
                printf("Bingo!\n");
                return 0;
            }
        }
    }

    printf("No bingo found.\n");

    return 0;
}

// Function to check if a number already exists in the board
int numberExists(int number, int board[ROWS][COLS])
{
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to mark the appropriate bingo row or column
void markBingo(int number, int bingo[], int row, int col)
{
    bingo[row]++;
    bingo[ROWS+col]++;
    if(row == col) {
        bingo[ROWS+COLS]++;
    }
    if(row == COLS-col-1) {
        bingo[ROWS+COLS+1]++;
    }
}

// Function to check if a bingo has been achieved
int checkBingo(int bingo[])
{
    int i;
    for(i=0; i<ROWS+COLS+2; i++) {
        if(bingo[i] == ROWS) {
            return 1;
        }
    }
    return 0;
}

// Function to print the board
void printBoard(int board[ROWS][COLS])
{
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}