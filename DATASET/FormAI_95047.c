//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include<stdio.h>

int main() {
    int rows = 9;

    // Top Half of C
    for (int i = 0; i < rows / 2; i++) {
        printf("*");
        for (int j = 0; j < rows - 1; j++) {
            if (i == 0 || j == (rows - 1) / 2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    // Bottom Half of C
    for (int i = rows / 2; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (j == 0 || i == rows - 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}