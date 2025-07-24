//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function to print the bingo card
void printCard(int card[ROWS][COLS]) {
    printf("--------------------\n");
    printf("| B  | I  | N  | G  | O  |\n");
    for (int row = 0; row < ROWS; row++) {
        printf("--------------------\n");
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == -1) {
                printf("|    ");
            } else {
                printf("| %2d ", card[row][col]);
            }
        }
        printf("|\n");
    }
    printf("--------------------\n");
}

// Function to generate random numbers for the card
void generateCard(int card[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            card[row][col] = -1;
        }
    }

    // Fill first column with random numbers from 1 to 15
    for (int row = 0; row < ROWS; row++) {
        int num = rand() % 15 + 1;
        card[row][0] = num;

        // Make sure each number in the column is unique
        for (int search_row = 0; search_row < row; search_row++) {
            while (card[search_row][0] == num) {
                num = rand() % 15 + 1;
                card[row][0] = num;
            }
        }
    }

    // Fill second column with random numbers from 16 to 30
    for (int row = 0; row < ROWS; row++) {
        int num = rand() % 15 + 16;
        card[row][1] = num;

        // Make sure each number in the column is unique
        for (int search_row = 0; search_row < row; search_row++) {
            while (card[search_row][1] == num) {
                num = rand() % 15 + 16;
                card[row][1] = num;
            }
        }
    }

    // Fill third column with random numbers from 31 to 45
    for (int row = 0; row < ROWS; row++) {
        int num = rand() % 15 + 31;
        card[row][2] = num;

        // Make sure each number in the column is unique
        for (int search_row = 0; search_row < row; search_row++) {
            while (card[search_row][2] == num) {
                num = rand() % 15 + 31;
                card[row][2] = num;
            }
        }
    }

    // Fill fourth column with random numbers from 46 to 60
    for (int row = 0; row < ROWS; row++) {
        int num = rand() % 15 + 46;
        card[row][3] = num;

        // Make sure each number in the column is unique
        for (int search_row = 0; search_row < row; search_row++) {
            while (card[search_row][3] == num) {
                num = rand() % 15 + 46;
                card[row][3] = num;
            }
        }
    }

    // Fill fifth column with random numbers from 61 to 75
    for (int row = 0; row < ROWS; row++) {
        int num = rand() % 15 + 61;
        card[row][4] = num;

        // Make sure each number in the column is unique
        for (int search_row = 0; search_row < row; search_row++) {
            while (card[search_row][4] == num) {
                num = rand() % 15 + 61;
                card[row][4] = num;
            }
        }
    }
}

// Function to check if a number is on the card
int checkNumber(int card[ROWS][COLS], int num) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); // Seed random generator with current time

    int card[ROWS][COLS];

    generateCard(card);
    printCard(card);

    for (int i = 1; i <= MAX_NUM; i++) {
        int num = rand() % MAX_NUM + 1;
        
        if (checkNumber(card, num)) {
            printf("Number %d is on the card!\n", num);
            
            // Replace number with -1 on the card
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (card[row][col] == num) {
                        card[row][col] = -1;
                    }
                }
            }
            
            printCard(card);
            printf("\n");

            // Check if there is a bingo
            int bingo = 0;
            for (int row = 0; row < ROWS; row++) {
                int row_bingo = 1;
                for (int col = 0; col < COLS; col++) {
                    if (card[row][col] != -1) {
                        row_bingo = 0;
                        break;
                    }
                }
                if (row_bingo) {
                    printf("BINGO! Row %d is complete.\n", row+1);
                    bingo = 1;
                    break;
                }
            }
            for (int col = 0; col < COLS; col++) {
                int col_bingo = 1;
                for (int row = 0; row < ROWS; row++) {
                    if (card[row][col] != -1) {
                        col_bingo = 0;
                        break;
                    }
                }
                if (col_bingo) {
                    printf("BINGO! Column %d is complete.\n", col+1);
                    bingo = 1;
                    break;
                }
            }
            int diagonal_bingo = 1;
            for (int i = 0; i < ROWS; i++) {
                if (card[i][i] != -1) {
                    diagonal_bingo = 0;
                    break;
                }
            }
            if (diagonal_bingo) {
                printf("BINGO! Left diagonal is complete.\n");
                bingo = 1;
            }
            diagonal_bingo = 1;
            for (int i = 0; i < ROWS; i++) {
                if (card[i][COLS-1-i] != -1) {
                    diagonal_bingo = 0;
                    break;
                }
            }
            if (diagonal_bingo) {
                printf("BINGO! Right diagonal is complete.\n");
                bingo = 1;
            }
            if (bingo) {
                printf("Congratulations! You have won.\n");
                break;
            }
        } else {
            printf("Number %d is not on the card.\n", num);
        }
    }

    return 0;
}