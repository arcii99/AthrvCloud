//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);                 // taking user input for size of pattern
    for(i = n; i >= 1; i--) {        // outer loop for printing decreasing pattern
        for(j = i - 1; j >= 0; j--) {    // loop for printing spaces before *
            printf(" ");
        }
        for(k = n - i + 1; k >= 1; k--) {    // loop for printing * after spaces
            printf("* ");
        }
        printf("\n");   // move to next line for next row
    }
    for(i = 1; i <= n; i++) {   // outer loop for printing increasing pattern
        for(j = i - 1; j >= 0; j--) {    // loop for printing spaces before *
            printf(" ");
        }
        for(k = n - i + 1; k >= 1; k--) {    // loop for printing * after spaces
            printf("* ");
        }
        printf("\n");   // move to next line for next row
    }
    return 0;
}