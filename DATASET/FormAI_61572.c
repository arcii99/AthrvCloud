//FormAI DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, mid, i, j, count = 0;
    printf("Enter number of rows (must be odd): ");
    scanf("%d", &rows);

    cols = rows;

    if(rows % 2 == 0) {
        printf("Please enter an odd number of rows!\n");
        exit(0);
    }

    mid = (rows / 2) + 1;
    printf("\n");

    for(i = 1; i <= rows; i++) {
        for(j = 1; j <= cols; j++) {
            if(j <= mid + count && j >= mid - count) {
                if(i == mid) {
                    printf("C");
                } else {
                    printf("*");
                }
            } else {
                printf(" ");
            }
        }

        if(i >= mid) {
            count--;
        } else {
            count++;
        }

        printf("\n");
    }

    return 0;
}