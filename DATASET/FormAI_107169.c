//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include <stdio.h>

int main() {
    int n = 7, i, j;
    char bold[] = "\033[1m";
    char reset[] = "\033[0m";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0 || j == n - i - 1 || i == n - 1) {
                printf("%s*%s", bold, reset);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            if (j == 0 || j == n - i - 1 || i == n - 1) {
                printf("%s*%s", bold, reset);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}