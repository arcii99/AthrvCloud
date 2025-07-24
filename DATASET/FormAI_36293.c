//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                printf("\\");
            } else if (i + j == rows - 1) {
                printf("/");
            } else if (i == 0 || i == rows - 1) {
                printf("-");
            } else if (j == 0 || j == cols - 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}