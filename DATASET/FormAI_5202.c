//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    int left = (n / 2), right = (n / 2);
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == left + 1 || j == right + 1 || (i == n / 2 + 1 && j > 1 && j < n))
                printf("*");
            else
                printf(" ");
        }
        if (i == n / 2 + 1)
            printf(" C Pattern"); // Displaying the pattern name
        printf("\n");
        if (i % 2 != 0) { // Adjusting the left and right variables
            left--;
            right++;
        }
    }

    return 0;
}