//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

char* csv[1000][100];

void print_csv(int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%s, ", csv[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize csv with some values
    csv[0][0] = "Name";
    csv[0][1] = "Age";
    csv[0][2] = "City";
    csv[1][0] = "John";
    csv[1][1] = "25";
    csv[1][2] = "New York";
    csv[2][0] = "David";
    csv[2][1] = "32";
    csv[2][2] = "Los Angeles";
    csv[3][0] = "Emily";
    csv[3][1] = "28";
    csv[3][2] = "Seattle";
    csv[4][0] = "Sarah";
    csv[4][1] = "19";
    csv[4][2] = "Chicago";
    csv[5][0] = "Michael";
    csv[5][1] = "37";
    csv[5][2] = "Boston";

    int rows = 6, cols = 3; // actual rows and cols in csv
    int row, col;

    // read csv row by row
    for(row=1; row<rows; row++) {
        printf("Row %d: ", row);
        for(col=0; col<cols; col++) {
            printf("%s, ", csv[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // read csv column by column
    for(col=0; col<cols; col++) {
        printf("Column %d: ", col);
        for(row=1; row<rows; row++) {
            printf("%s, ", csv[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    print_csv(rows, cols);

    return 0;
}