//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

int main() {
    int rows = 6, i, j, k, l, m, n;
    for (i = 1; i <= rows; i++) {
        if (i == 1) {
            printf("       ");
            for (j = 1; j <= 5; j++) {
                printf("*");
            }
            printf("\n");
        }
        else if (i == 2) {
            printf("     * ");
            for (j = 1; j <= 3; j++) {
                printf(" ");
            }
            printf("*\n");
        }
        else if (i == 3) {
            printf("    * ");
            for (j = 1; j <= 5; j++) {
                printf("*");
            }
            printf(" *\n");
        }
        else if (i == 4) {
            printf("   * ");
            for (j = 1; j <= 9; j++) {
                printf("*");
            }
            printf(" *\n");
        }
        else if (i == 5) {
            printf("  * ");
            for (j = 1; j <= 13; j++) {
                printf("*");
            }
            printf(" *\n");
        }
        else if (i == 6) {
            printf(" * ");
            for (j = 1; j <= 17; j++) {
                printf("*");
            }
            printf(" *\n");
        }
    }
    for (i = 1; i <= 3; i++) {
        if (i == 1) {
            for (j = 1; j <= 5; j++) {
                printf(" ");
            }
            for (k = 1; k <= 4; k++) {
                printf("*");
            }
            for (l = 1; l <= 9; l++) {
                printf(" ");
            }
            for (m = 1; m <= 4; m++) {
                printf("*");
            }
            for (n = 1; n <= 5; n++) {
                printf(" ");
            }
            printf("\n");
        }
        else if (i == 2) {
            for (j = 1; j <= 5; j++) {
                printf(" ");
            }
            for (k = 1; k <= 4; k++) {
                printf("*");
            }
            printf("            ");
            for (l = 1; l <= 4; l++) {
                printf("*");
            }
            for (m = 1; m <= 5; m++) {
                printf(" ");
            }
            printf("\n");
        }
        else if (i == 3) {
            for (j = 1; j <= 5; j++) {
                printf(" ");
            }
            for (k = 1; k <= 13; k++) {
                printf("*");
            }
            for (l = 1; l <= 5; l++) {
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}