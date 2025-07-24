//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void printRecursively(int current, int target, int direction) {
    // The base case is when we reach the maximum or minimum number in the pattern
    if (current == target) {
        printf("%d ", current);
        return;
    }
    // Print the current number
    printf("%d ", current);
    // When direction is positive, add 1 to the current number
    if (direction == 1) {
        printRecursively(current+1, target, direction);
    }
    // When direction is negative, subtract 1 from the current number
    else {
        printRecursively(current-1, target, direction);
    }
}

void printCPattern(int n) {
    // Print the upper half of the pattern
    for (int i = n; i >= 1; i--) {
        printRecursively(n, i, -1);
        printf("\n");
    }
    // Print the lower half of the pattern
    for (int i = 2; i <= n; i++) {
        printRecursively(n, i, -1);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows in the pattern: ");
    scanf("%d", &n);
    printf("\nC Pattern:\n\n");
    printCPattern(n);
    return 0;
}