//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cryptic
#include <stdio.h>
int main() {
    int n = 5, i, j;
    for (i = 1; i <= n; i++) {
        for (j = n; j >= i; j--)
            printf("%c", 'A' + j - 1);
        printf("\n");
    }
    return 0;
}