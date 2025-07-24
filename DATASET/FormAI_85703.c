//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateRandomNumbers(int bingoCard[ROWS][COLS]);
void printBingoCard(int bingoCard[ROWS][COLS]);

int main(){
    int bingoCard[ROWS][COLS];

    generateRandomNumbers(bingoCard);
    printBingoCard(bingoCard);

    return 0;
}

void generateRandomNumbers(int bingoCard[ROWS][COLS]){
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(j == 2 && i == 2){ // Center of the card is a FREE space
                bingoCard[i][j] = 0;
            } else {
                bingoCard[i][j] = rand() % 15 + (15 * j) + 1; // Generates a random number based on the column
            }
        }
    }
}

void printBingoCard(int bingoCard[ROWS][COLS]){
    printf("=========================\n");
    printf("| B  | I  | N  | G  | O  |\n");
    printf("=========================\n");

    for(int i = 0; i < ROWS; i++){
        printf("|");
        for(int j = 0; j < COLS; j++){
            if(bingoCard[i][j] < 10){ // Adding an extra space for better display
                printf(" %d |", bingoCard[i][j]);
            } else {
                printf(" %d|", bingoCard[i][j]);
            }
        }
        printf("\n");
    }

    printf("=========================\n");
}