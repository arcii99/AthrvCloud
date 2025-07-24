//FormAI DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>

int main() {
    int rows, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++) {
        for(j = 0; j < rows-i-1; j++) {
            printf(" ");
        }
        for(k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    for(i = rows-1; i >= 0; i--) {
        for(j = rows-i-1; j >= 0; j--) {
            printf(" ");
        }
        for(k = 0; k <= i-1; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}