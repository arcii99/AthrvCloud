//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int rows = 10, cols = 15;
    int i, j;

    for(i = 1; i <= rows; i++) {
        for(j = i; j < cols; j++) {
            printf(" ");
        }
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    for(i = rows - 1; i >= 1; i--) {
        for(j = cols; j > i; j--) {
            printf(" ");
        }
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}