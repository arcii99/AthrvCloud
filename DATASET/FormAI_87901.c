//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main() {
    int n, i, j, space, star;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {

        // Calculate number of spaces to be printed on this row
        space = n - i;

        // Print spaces on this row
        for (j = 1; j <= space; j++) {
            printf(" ");
        }

        // Calculate number of stars to be printed on this row
        if (i == 1 || i == n) {
            star = n;
        } else {
            star = 2 * i - 1;
        }

        // Print stars on this row
        for (j = 1; j <= star; j++) {
            if (j == 1 || j == star || i == ((n+1)/2)) {
                printf("*");
            } else {
                printf(" ");
            }
        }

        // Move to next row
        printf("\n");
    }

    return 0;
}