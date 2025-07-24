//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Surprise! Let's play a unique table game!\n\n");

    srand(time(NULL)); // set random seed based on current time 

    int row = (rand() % 8) + 3; // randomly generate number of rows between 3-10
    int col = (rand() % 8) + 3; // randomly generate number of columns between 3-10

    printf("The table has %d rows and %d columns.\n\n", row, col);

    int table[row][col]; // create empty table array

    // generate random numbers for each cell and print the table
    printf("Here are the random numbers in each cell:\n\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            table[i][j] = rand() % 100; // generate a random number between 0-99
            printf("%d\t", table[i][j]); // print the number with a tab separator
        }
        printf("\n"); // move to next row after printing all columns in current row
    }

    // find the largest number in each row and highlight it by adding an asterisk
    printf("\nHere are the largest numbers in each row (marked by asterisks):\n\n");
    for(int i=0; i<row; i++) {
        int max = table[i][0]; // assume the first cell of current row has the largest number
        int max_col = 0; // keep track of the column index with the largest number
        for(int j=1; j<col; j++) {
            if(table[i][j] > max) {
                max = table[i][j]; // update the largest number
                max_col = j; // update the column index with the largest number
            }
        }
        table[i][max_col] = -1; // mark the cell with the largest number as -1 (to avoid confusion with asterisk)
        printf("| ");
        for(int j=0; j<col; j++) {
            printf("%d", table[i][j]); // print the number
            if(j == max_col) printf("*"); // add an asterisk if it's the largest number
            printf("\t"); // add a tab separator
        }
        printf("|\n"); // move to next row after printing all columns in current row
    }

    printf("\nThat was fun! Hope you enjoyed this unique table game.\n");

    return 0;
}