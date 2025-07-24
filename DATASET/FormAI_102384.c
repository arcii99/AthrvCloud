//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    printf("The world crumbled into dust and ash,\n");
    printf("Survivors huddled in ruins, their hearts full of fear and terror.\n\n");
    
    int rows, i, j, k, temp = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\nThe C Pattern:\n\n");

    for (i = 1; i <= rows; i++) {
        if (i == 1 || i == rows) {
            for (j = 1; j <= rows; j++) {
                printf(" *");
            }
        }
        else {
            temp++;

            for (j = 1; j <= rows; j++) {
                if (j == 1) {
                    printf(" *");
                }
                else if (j == rows) {
                    printf(" *");
                }
                else {
                    if (temp == j - 1) {
                        printf(" *");
                    }
                    else {
                        printf("  ");
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}