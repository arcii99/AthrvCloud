//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                printf("*");
            }
            else if (j == 1 || j == n) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}