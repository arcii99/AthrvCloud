//FormAI DATASET v1.0 Category: Pattern printing ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Declaration of variables
    int n, i, j, k = 1;

    // Getting the number of rows from user input
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Looping through each row
    for (i = 1; i <= n; i++) {
        // Printing the numbers in ascending order
        for (j = 1; j <= i; j++) {
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }

    // Looping through each row in reverse order
    for (i = n; i > 1; i--) {
        // Printing the numbers in descending order
        k = (i * (i - 1)) / 2 + 1;
        for (j = 1; j < i; j++) {
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }

    return 0;
}