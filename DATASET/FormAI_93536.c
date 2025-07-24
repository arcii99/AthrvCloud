//FormAI DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = -n; i <= n; i++) {
        int max = (i < 0) ? -i : i;
        int spaces = n - max;
        for (int j = 0; j < spaces; j++) {
            printf("  ");
        }
        for (int j = max; j >= -max; j--) {
            printf("%c ", (char)(max - abs(j) + 65));
        }
        printf("\n");
    }
    return 0;
}