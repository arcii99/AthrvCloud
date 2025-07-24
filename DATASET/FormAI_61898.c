//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {

    // Initialize the Bingo card with random values
    int bingoCard[ROWS][COLUMNS];
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(j == 2 && i == 2) { // Center of the card is a free space by convention
                bingoCard[i][j] = 0;
            } else {
                bingoCard[i][j] = (rand() % 15) + (j * 15 + 1);
            }
        }
    }

    // Print the Bingo card
    printf("Welcome to the Bingo Simulator!\n\n");
    printf("Here is your Bingo card:\n");
    printf("_______________\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(j == 2 && i == 2) {
                printf("|  FREE  ");
            } else {
                printf("|  %2d   ", bingoCard[i][j]);
            }
        }
        printf("|\n");
        printf("_______________\n");
    }
    printf("\n");

    // Generate a random set of numbers and mark them on the Bingo card
    int numbers[75];
    for(int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }
    for(int i = 0; i < 75; i++) {
        int randomIndex = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;
    }
    printf("Time to start calling numbers! Ready? Go!\n\n");
    int bingo = 0;
    for(int i = 0; i < 75; i++) {
        printf("The next number is: %d\n", numbers[i]);
        for(int j = 0; j < ROWS; j++) {
            for(int k = 0; k < COLUMNS; k++) {
                if(bingoCard[j][k] == numbers[i]) {
                    bingoCard[j][k] = -1;
                    printf("We have a match for %d at row %d, column %d!\n", numbers[i], j + 1, k + 1);
                }
            }
        }
        printf("\n");
        // Check for a Bingo
        int rowBingo = 0;
        int columnBingo = 0;
        int diagonalBingo = 0;
        // Check rows
        for(int j = 0; j < ROWS; j++) {
            rowBingo = 1;
            for(int k = 0; k < COLUMNS; k++) {
                if(bingoCard[j][k] != -1) {
                    rowBingo = 0;
                    break;
                }
            }
            if(rowBingo == 1) {
                printf("BINGO! We have a winner in row %d!\n", j + 1);
                bingo = 1;
                break;
            }
        }
        if(bingo == 1) {
            break;
        }
        // Check columns
        for(int j = 0; j < COLUMNS; j++) {
            columnBingo = 1;
            for(int k = 0; k < ROWS; k++) {
                if(bingoCard[k][j] != -1) {
                    columnBingo = 0;
                    break;
                }
            }
            if(columnBingo == 1) {
                printf("BINGO! We have a winner in column %d!\n", j + 1);
                bingo = 1;
                break;
            }
        }
        if(bingo == 1) {
            break;
        }
        // Check diagonals
        diagonalBingo = 1;
        for(int j = 0; j < ROWS; j++) {
            if(bingoCard[j][j] != -1) {
                diagonalBingo = 0;
                break;
            }
        }
        if(diagonalBingo == 1) {
            printf("BINGO! We have a winner on the left diagonal!\n");
            bingo = 1;
        } else {
            diagonalBingo = 1;
            for(int j = 0; j < ROWS; j++) {
                if(bingoCard[j][COLUMNS - j - 1] != -1) {
                    diagonalBingo = 0;
                    break;
                }
            }
            if(diagonalBingo == 1) {
                printf("BINGO! We have a winner on the right diagonal!\n");
                bingo = 1;
            }
        }
        if(bingo == 1) {
            break;
        }
    }
    if(bingo == 0) {
        printf("Game over. No winner this time. Better luck next time!\n");
    }

    return 0;
}