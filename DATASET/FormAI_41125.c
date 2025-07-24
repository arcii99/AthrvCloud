//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    char shape = '*'; // default shape
    int board[ROWS][COLS];
    int row, col, count = 0;

    srand(time(NULL)); // seed the random generator

    // initialize the board
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            board[row][col] = 0;
        }
    }

    // randomly generate the values on the board
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            int value = rand() % 75 + 1;
            board[row][col] = value;
        }
    }

    // randomly select the shape
    int shapeNum = rand() % 3 + 1;
    if(shapeNum == 1) {
        shape = '@'; // shape 1
    }
    else if(shapeNum == 2) {
        shape = '#'; // shape 2
    }
    else {
        shape = '*'; // shape 3
    }

    // print the board with the selected shape
    printf("\n\nBINGO BOARD WITH SHAPE '%c':\n\n", shape);
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            if(row == 2 && col == 2) {
                printf("%c ", shape);
            }
            else {
                printf("%d ", board[row][col]);
            }
        }
        printf("\n");
    }

    // count the number of values on the board
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            if(board[row][col] != 0) {
                count++;
            }
        }
    }

    printf("\n");
    printf("---------------------------------------------\n");
    printf("|                 BINGO STATS                |\n");
    printf("---------------------------------------------\n");
    printf("| Total Board Size  : %d                      |\n", ROWS * COLS);
    printf("| Number of Values  : %d                      |\n", count);
    printf("| Shape Selected    : %c                      |\n", shape);
    printf("---------------------------------------------\n");
    printf("\n");
    
    return 0;
}