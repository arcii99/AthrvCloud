//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random number from 1 to 75 */
int generateRandomNumber(int usedNumbers[], int usedCount) {
    int random = 0;
    do {
        /* Generate a random number */
        random = (rand() % 75) + 1;
        /* Check if the random number has already been used */
        int found = 0;
        for(int i = 0; i < usedCount; i++) {
            if(usedNumbers[i] == random) {
                found = 1;
                break;
            }
        }
        /* If the random number hasn't been used before, exit the loop */
        if(!found) break;
    } while(1);
    return random;
}

/* Function to print the bingo card */
void printCard(int card[5][5], int marks[5][5]) {
    /* Print the column headers */
    printf(" B  I  N  G  O\n");
    /* Print the card */
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%2d ", card[i][j]);
            if(marks[i][j]) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    /* Initialize the card */
    int card[5][5] = {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };
    /* Initialize the marks */
    int marks[5][5] = {0};
    /* Initialize the used numbers */
    int usedNumbers[75] = {0};
    int usedCount = 0;
    /* Print the card */
    printCard(card, marks);
    /* Play the game */
    while(1) {
        /* Generate a random number */
        int randomNumber = generateRandomNumber(usedNumbers, usedCount);
        /* Print the number */
        printf("Next number: %d\n", randomNumber);
        /* Mark the number on the card */
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(card[i][j] == randomNumber) {
                    marks[i][j] = 1;
                }
            }
        }
        /* Print the updated card */
        printCard(card, marks);
        /* Check for winners */
        int rowWinner = 0;
        int columnWinner = 0;
        int diagonalWinner = 0;
        /* Check for row winners */
        for(int i = 0; i < 5; i++) {
            int rowMarks = 0;
            for(int j = 0; j < 5; j++) {
                rowMarks += marks[i][j];
            }
            if(rowMarks == 5) {
                rowWinner = 1;
                break;
            }
        }
        /* Check for column winners */
        for(int i = 0; i < 5; i++) {
            int columnMarks = 0;
            for(int j = 0; j < 5; j++) {
                columnMarks += marks[j][i];
            }
            if(columnMarks == 5) {
                columnWinner = 1;
                break;
            }
        }
        /* Check for diagonal winners */
        int diagonal1Marks = marks[0][0] + marks[1][1] + marks[2][2] + marks[3][3] + marks[4][4];
        int diagonal2Marks = marks[0][4] + marks[1][3] + marks[2][2] + marks[3][1] + marks[4][0];
        if(diagonal1Marks == 5 || diagonal2Marks == 5) {
            diagonalWinner = 1;
        }
        /* If there is a winner, end the game */
        if(rowWinner || columnWinner || diagonalWinner) {
            printf("Bingo! You Win!\n");
            break;
        }
        /* Add the used number to the list */
        usedNumbers[usedCount++] = randomNumber;
        /* Wait for the user to press enter */
        printf("Press Enter for the next number...\n");
        getchar();
    }
    return 0;
}