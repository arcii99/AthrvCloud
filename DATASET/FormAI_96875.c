//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

int main() {

    printf("Welcome to Bingo Simulator!\n");

    // initialize the bingo card
    int card[ROWS][COLS];
    srand(time(0)); // seed the random number generator

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i != 2 || j != 2) {
                card[i][j] = rand() % 99 + 1; // fill the card with random values
            }
            else {
                card[i][j] = 0; // mark center spot as free space
            }
        }
    }

    // print the bingo card
    printf("\nYour bingo card:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%-3d ", card[i][j]);
        }
        printf("\n");
    }

    // play the game
    int numsCalled[100] = {0};
    int count = 0;
    int num;
    int row, col;
    printf("\nLet's play some bingo!\n");

    while(count < 25) {
        printf("\nEnter the number called (1-99): ");
        scanf("%d", &num);

        // check if number has already been called
        if(numsCalled[num]) {
            printf("Sorry, that number has already been called.\n");
            continue;
        }

        numsCalled[num] = 1; // mark number as called
        count++;
        printf("Calling number %d...\n", num);

        // check if number matches any on the bingo card
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(card[i][j] == num) {
                    row = i;
                    col = j;
                    card[i][j] = 0; // mark spot as filled

                    // check for bingo
                    if((row == 0 || row == 4 || col == 0 || col == 4) || (row == col) || (row == 4-col)) {
                        printf("\nBINGO!!!\n");
                        printf("Row: %d, Column: %d\n", row+1, col+1);

                        printf("\nFinal bingo card:\n");
                        for(int k=0; k<ROWS; k++) {
                            for(int l=0; l<COLS; l++) {
                                printf("%-3d ", card[k][l]);
                            }
                            printf("\n");
                        }

                        printf("\nThanks for playing!\n");
                        return 0;
                    }
                }
            }
        }

        printf("\nYour updated bingo card:\n");
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                printf("%-3d ", card[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nSorry, no bingo.\n");
    printf("\nFinal bingo card:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%-3d ", card[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for playing!\n");
    return 0;
}