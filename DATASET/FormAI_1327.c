//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("\nPrinting the pattern:\n");

    for (int i = 0; i < n; i++) {
        // Print space for the left side of the triangle
        for (int j = n - 1; j > i; j--) {
            printf(" ");
        }

        // Print the stars for the left side of the triangle
        for (int j = 0; j <= i; j++) {
            printf("*");
        }

        // Print space in the middle of the triangle
        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        // Print the stars for the right side of the triangle
        for (int j = i; j < n-1; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}