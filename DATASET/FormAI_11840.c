//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
    int size, i, j, flag;
    printf("Enter the size: ");
    scanf("%d", &size);
    // Flag variable is used to represent whether we have printed the '*' or not in a row.
    flag = 0;
    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
                flag = 1;
            } else if (i == j) {
                printf("\\");
                flag = 1;
            } else if (i + j == size + 1) {
                printf("/");
                flag = 1;
            } else {
                // If we haven't printed anything in this row yet, print a space
                if (flag == 0) {
                    printf(" ");
                }
            }
        }
        // Reset flag for the next row
        flag = 0;
        printf("\n");
    }
    return 0;
}