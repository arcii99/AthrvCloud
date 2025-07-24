//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include<stdio.h>
int main() {
    int n, i, j, noOfSpaces, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    noOfSpaces = n-1;

    // Loop for upper part
    for(rows=1; rows<=n; rows++) {
        // Print required number of spaces
        for(i=1; i<=noOfSpaces; i++) {
            printf(" ");
        }
        // Decrease noOfSpaces by 1 for next row
        noOfSpaces--;

        // Print * equal to row number
        for(j=1; j<=(2*rows-1); j++) {
            printf("*");
        }
        printf("\n");
    }

    noOfSpaces = 1;

    // Loop for lower part
    for(rows=1; rows<=(n-1); rows++) {
        for(i=1; i<=noOfSpaces; i++) {
            printf(" ");
        }
        noOfSpaces++;

        for(j=1; j<=(2*(n-rows)-1); j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}