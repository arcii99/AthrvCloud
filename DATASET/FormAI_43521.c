//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
    int rows, cols, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    cols = rows;
    int array[rows][cols];
    int num = 1, count = 0, r = 0, c = 0, direction = 0;

    // Initializing array with 0
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            array[i][j] = 0;
        }
    }

    // Filling array with numbers in C pattern
    while(num <= rows*cols) {
        if(direction == 0) {
            for(i=c;i<cols;i++) {
                array[r][i] = num++;
            }
            r++;
            direction = 1;
        }
        else if(direction == 1) {
            for(i=r;i<rows;i++) {
                array[i][cols-1] = num++;
            }
            cols--;
            direction = 2;
        }
        else if(direction == 2) {
            for(i=cols-1;i>=c;i--) {
                array[rows-1][i] = num++;
            }
            rows--;
            direction = 3;
        }
        else if(direction == 3) {
            for(i=rows-1;i>=r;i--) {
                array[i][c] = num++;
            }
            c++;
            direction = 0;
        }
    }

    // Printing C pattern
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            if(array[i][j] < 10) {
                printf("00%d ", array[i][j]);
            }
            else if(array[i][j] < 100) {
                printf("0%d ", array[i][j]);
            }
            else {
                printf("%d ", array[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}