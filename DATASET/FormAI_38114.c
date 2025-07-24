//FormAI DATASET v1.0 Category: Pattern printing ; Style: multiplayer
#include <stdio.h>

int main() {
    int rows, cols, mid;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    mid = rows / 2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == mid || j == mid || (i == 0 && j >= mid) || (i == rows - 1 && j <= mid)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}