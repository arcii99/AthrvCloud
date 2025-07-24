//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>

int main() {

    int n, t1 = 0, t2 = 1, nextTerm;
    
    printf("Enter the number of terms you want to display in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("\n\nThe first %d terms of the Fibonacci sequence:\n", n);
    
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("\n\nFibonacci Series Visualized:\n");

    int length = 2 * n - 1; // Length of each row
    
    int row[length];
    for (int i = 0; i < length; ++i) {
        row[i] = 0;
    }
    
    int mid = (length + 1) / 2; // Midpoint of each row
    row[mid - 1] = 1; // Initialize first cell with 1
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < length; ++j) {
            if (j == 0 || j == length - 1) {
                row[j] = 1;
            } else {
                row[j] = row[j - 1] + row[j + 1];
            }
            if (row[j] == 0) {
                printf(" ");
            } else {
                printf("%d", row[j]);
            }
        }
        printf("\n");
    }

    return 0;
}