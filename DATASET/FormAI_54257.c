//FormAI DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>

int main() {
    int i,j,rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i=1; i<=rows; i++) {
        // Print spaces
        for(j=i; j<rows; j++) {
            printf(" ");
        }

        // Print asterisks
        for(j=1; j<=(2*i-1); j++) {
            printf("*");
        }

        // Move to next line
        printf("\n");
    }

    return 0;
}