//FormAI DATASET v1.0 Category: Pattern printing ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, k, n;

    // Getting input from user
    printf("Enter the number of lines to print: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++) {

        // Printing spaces in the beginning of the line
        for(j=1; j<=n-i; j++)
            printf(" ");

        // Printing asterisks
        for(k=1; k<=i*2-1; k++)
            printf("*");

        // Moving to the next line
        printf("\n");
    }

    // Printing the inverted pyramid
    for(i=n-1; i>=1; i--) {

        // Printing spaces in the beginning of the line
        for(j=1; j<=n-i; j++)
            printf(" ");

        // Printing asterisks
        for(k=1; k<=i*2-1; k++)
            printf("*");

        // Moving to the next line
        printf("\n");
    }

    return 0;
}