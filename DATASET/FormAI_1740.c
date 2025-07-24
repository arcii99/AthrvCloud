//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
    int rows, cols, i, j, k, l;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    cols = rows; 
    
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        for (l = 1; l <= i - 1; l++) {
            printf("*");
        }
        printf("\n");
    }
    
    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        for (l = 1; l <= i - 1; l++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}