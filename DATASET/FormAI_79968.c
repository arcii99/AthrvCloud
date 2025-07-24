//FormAI DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>

int main() {
    int n = 8;  // Number of rows in the pattern 
    int m;  // Number of columns in the pattern 
    int i, j, k;  // Loop variables 
    
    for (i = 1; i <= n; i++) {  // Loop through each row
        m = (i * 2) - 1;  // Calculate number of columns for this row 
        for (j = n; j >= i; j--) {  // Loop to print spaces before pattern
            printf(" ");
        }
        for (k = 1; k <= m; k++) {  // Loop to print pattern for row 
            if (k % 2 == 0) {  // If even column number, print 0 
                printf("0");
            } else {  // If odd column number, print 1 
                printf("1");
            }
        }
        printf("\n");  // Move to next row 
    }
    for (i = n - 1; i >= 1; i--) {  // Reverse loop to print remaining rows 
        m = (i * 2) - 1;
        for (j = n; j >= i; j--) {
            printf(" ");
        }
        for (k = 1; k <= m; k++) {
            if (k % 2 == 0) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }
    return 0;
}