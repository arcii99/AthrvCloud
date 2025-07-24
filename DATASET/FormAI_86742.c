//FormAI DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

int main() {
    int num = 5;
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    for (int i = num - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}