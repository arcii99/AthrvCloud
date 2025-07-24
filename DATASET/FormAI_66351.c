//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
// Welcome to the C Table Game!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int table[10][10]; // the 10x10 table
    int i, j, sum1, sum2, row, col; // some useful variables

    srand(time(NULL)); // to initialize the random seed

    // Let's fill the table with random numbers from 1 to 100
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            table[i][j] = rand()%100 + 1;
        }
    }

    // Let's print the table
    printf("Welcome to the C Table Game!\n\n");
    printf("Here is the table:\n\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%3d ", table[i][j]);
        }
        printf("\n");
    }

    // Let's calculate the sum of each row and column
    for(i=0; i<10; i++) {
        sum1 = 0; // the sum of row i
        sum2 = 0; // the sum of column i
        for(j=0; j<10; j++) {
            sum1 += table[i][j];
            sum2 += table[j][i];
        }
        table[i][10] = sum1; // store the sum of row i in the last column of row i
        table[10][i] = sum2; // store the sum of column i in the last row of column i
    }

    // Let's print the table with the sums
    printf("\nHere is the table with the sums:\n\n");
    for(i=0; i<11; i++) {
        for(j=0; j<11; j++) {
            if(i<10 && j<10) {
                printf("%3d ", table[i][j]);
            } else if(i<10 && j==10) {
                printf("%3d ", table[i][j]);
            } else if(i==10 && j<10) {
                printf("%3d ", table[i][j]);
            } else if(i==10 && j==10) {
                printf("    ");
            }
        }
        printf("\n");
    }

    // Let's ask the user for a row and a column
    printf("\nNow it is your turn!\n");
    printf("Please choose a row between 1 and 10: ");
    scanf("%d", &row);
    printf("Please choose a column between 1 and 10: ");
    scanf("%d", &col);

    // Let's check if the user won or lost
    if(table[row-1][10] > table[10][col-1]) {
        printf("\nCongratulations! You won!\n");
    } else {
        printf("\nSorry, you lost. Better luck next time!\n");
    }

    return 0;
}