//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
    int rows = 7;
    int spaces = rows - 1;
    int counts = 1;

    printf("\n\n\t\t\tHappy C Pattern Printing!\n\n");

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf("  ");
        }

        for (int k = 1; k <= counts; k++) {
            printf(" * ");
        }

        printf("\n");

        spaces--;
        counts += 2;
    }

    spaces = 3;
    counts = 5;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf("  ");
        }

        for (int k = 1; k <= counts; k++) {
            printf(" * ");
        }

        printf("\n");

        spaces++;
        counts -= 2;
    }

    printf("\n\n\t\t\tThe C Pattern is so much fun!");
    return 0;
}