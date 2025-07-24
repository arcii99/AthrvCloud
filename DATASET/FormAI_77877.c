//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int bingoCard[ROWS][COLS];
    int bingoNums[75];
    int numCalled[75] = {0};
    int row, col, num, count = 0;
    char playAgain = 'y';

    // generate the list of possible bingo numbers
    for(int i = 0; i < 75; i++) {
        bingoNums[i] = i + 1;
    }

    // seed the random number generator
    srand(time(NULL));

    // start the game loop
    while(playAgain == 'y' || playAgain == 'Y') {
        count = 0;

        // clear the bingo card
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                bingoCard[i][j] = 0;
            }
        }

        // fill the bingo card with random numbers
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                // generate a random number between 1 and 75
                num = rand() % 75 + 1;

                // make sure the number hasn't already been added to the card
                while(1) {
                    int numFound = 0;
                    for(int k = 0; k < ROWS; k++) {
                        for(int l = 0; l < COLS; l++) {
                            if(bingoCard[k][l] == num) {
                                numFound = 1;
                            }
                        }
                    }
                    if(numFound == 1) {
                        // num is already on the card, generate a new number
                        num = rand() % 75 + 1;
                    } else {
                        // num is not on the card, add it to the card
                        bingoCard[i][j] = num;
                        break;
                    }
                }
            }
        }

        // print the bingo card
        printf("Your Bingo Card:\n");
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                printf("%2d ", bingoCard[i][j]);
            }
            printf("\n");
        }

        // start the number calling loop
        while(count < 75) {
            // generate a random number between 1 and 75
            num = rand() % 75 + 1;

            // check if the number has already been called
            if(numCalled[num - 1] == 0) {
                numCalled[num - 1] = 1;

                printf("Number called: %d\n", num);

                // check if the number appears on the bingo card
                for(int i = 0; i < ROWS; i++) {
                    for(int j = 0; j < COLS; j++) {
                        if(bingoCard[i][j] == num) {
                            // mark the number on the card
                            bingoCard[i][j] = -1;
                        }
                    }
                }

                // check if all numbers in a row have been marked
                for(int i = 0; i < ROWS; i++) {
                    int rowComplete = 1;
                    for(int j = 0; j < COLS; j++) {
                        if(bingoCard[i][j] != -1) {
                            rowComplete = 0;
                            break;
                        }
                    }

                    if(rowComplete == 1) {
                        printf("BINGO! Row %d has been completed.\n", i+1);
                        count += COLS;
                    }
                }

                // check if all numbers in a column have been marked
                for(int j = 0; j < COLS; j++) {
                    int colComplete = 1;
                    for(int i = 0; i < ROWS; i++) {
                        if(bingoCard[i][j] != -1) {
                            colComplete = 0;
                            break;
                        }
                    }

                    if(colComplete == 1) {
                        printf("BINGO! Column %d has been completed.\n", j+1);
                        count += ROWS;
                    }
                }

                // check if all numbers in a diagonal have been marked
                if(bingoCard[0][0] == -1 && bingoCard[1][1] == -1 && bingoCard[2][2] == -1 && bingoCard[3][3] == -1 && bingoCard[4][4] == -1) {
                    printf("BINGO! Diagonal from top-left to bottom-right has been completed.\n");
                    count += ROWS;
                }

                if(bingoCard[0][4] == -1 && bingoCard[1][3] == -1 && bingoCard[2][2] == -1 && bingoCard[3][1] == -1 && bingoCard[4][0] == -1) {
                    printf("BINGO! Diagonal from top-right to bottom-left has been completed.\n");
                    count += ROWS;
                }
            }
        }

        printf("Congratulations! You won the game!\n");

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    return 0;
}