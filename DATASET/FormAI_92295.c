//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {
    int bingoBoard[ROWS][COLUMNS];
    srand(time(NULL));

    // Generate Bingo Board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(i == 2 && j == 2) {
                // Center square is a free space
                bingoBoard[i][j] = 0;
            } else {
                int number = rand() % 15 + 1 + (j * 15);
                bingoBoard[i][j] = number;
            }
        }
    }

    // Print Bingo Board
    printf("------------------------\n");
    printf("| B  | I  | N  | G  | O  |\n");
    printf("------------------------\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(bingoBoard[i][j] == 0) {
                printf("|FREE");
            } else {
                printf("|%2d ", bingoBoard[i][j]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("------------------------\n");

    // Play Bingo
    int numbersCalled[ROWS * COLUMNS];
    int numCalledIndex = 0;
    int rowBingo = 0;
    int columnBingo = 0;
    int diagonalBingo = 0;
    int numBingo = 0;
    int numberCalled;

    printf("Playing Bingo...\n");
    do {
        int numberAlreadyCalled = 0;
        do {
            numberCalled = rand() % 75 + 1;
            for(int i = 0; i < numCalledIndex; i++) {
                if(numbersCalled[i] == numberCalled) {
                    numberAlreadyCalled = 1;
                    break;
                }
            }
        } while(numberAlreadyCalled);

        numbersCalled[numCalledIndex] = numberCalled;
        numCalledIndex++;

        printf("Number Called: %d\n", numberCalled);

        // Check for Bingo
        for(int i = 0; i < ROWS; i++) {
            rowBingo = 1;
            for(int j = 0; j < COLUMNS; j++) {
                if((bingoBoard[i][j] == numberCalled || bingoBoard[i][j] == 0) && rowBingo) {
                    rowBingo = 1;
                } else {
                    rowBingo = 0;
                    break;
                }
            }
            if(rowBingo) {
                printf("BINGO! Row %d.\n", i + 1);
                numBingo++;
            }
        }
        for(int i = 0; i < COLUMNS; i++) {
            columnBingo = 1;
            for(int j = 0; j < ROWS; j++) {
                if((bingoBoard[j][i] == numberCalled || bingoBoard[j][i] == 0) && columnBingo) {
                    columnBingo = 1;
                } else {
                    columnBingo = 0;
                    break;
                }
            }
            if(columnBingo) {
                printf("BINGO! Column %d.\n", i + 1);
                numBingo++;
            }
        }
        diagonalBingo = 1;
        for(int i = 0; i < ROWS; i++) {
            if((bingoBoard[i][i] == numberCalled || bingoBoard[i][i] == 0) && diagonalBingo) {
                diagonalBingo = 1;
            } else {
                diagonalBingo = 0;
                break;
            }
        }
        if(diagonalBingo) {
            printf("BINGO! Diagonal.\n");
            numBingo++;
        }
        diagonalBingo = 1;
        for(int i = 0; i < ROWS; i++) {
            if((bingoBoard[i][COLUMNS - i - 1] == numberCalled || bingoBoard[i][COLUMNS - i - 1] == 0) && diagonalBingo) {
                diagonalBingo = 1;
            } else {
                diagonalBingo = 0;
                break;
            }
        }
        if(diagonalBingo) {
            printf("BINGO! Diagonal.\n");
            numBingo++;
        }
    } while(numBingo < 5);

    printf("You win!\n");

    return 0;
}