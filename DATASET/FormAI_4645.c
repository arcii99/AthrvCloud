//FormAI DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include <stdio.h>

int main() {
    int n, i, j;

    // Get the value of n from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print the pattern
    for (i = 1; i <= n; i++) {
        // Print the numbers from 1 to i in ascending order
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Print the numbers from i-1 to 1 in descending order
        for (j = i-1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // End of program
    return 0;
}