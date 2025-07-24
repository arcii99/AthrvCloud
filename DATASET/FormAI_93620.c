//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {
    int i, j, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Upper Half
    for (i = 1; i <= rows/2+1; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (j = i*2; j < rows*2-i; j++) {
            printf(" ");
        }
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Lower Half
    for (i = rows/2; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (j = i*2; j < rows*2-i; j++) {
            printf(" ");
        }
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}