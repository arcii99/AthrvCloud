//FormAI DATASET v1.0 Category: Pattern printing ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    k = 1;
    for (i = 1; i <= n; i++) {
        // print spaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // print numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", k);
            k++;
        }

        printf("\n");
    }

    return 0;
}