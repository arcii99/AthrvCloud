//FormAI DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

void pattern(int n, int i, int isDecreasing) {
    if (i <= n) {
        if (isDecreasing) {
            printf("%d ", i);
            pattern(n, i - 1, 1);
        }
        else {
            pattern(n, i - 1, 0);
            printf("%d ", i);
        }
    }
    else {
        if (isDecreasing) {
            pattern(n, 2, 0);
        }
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    pattern(n, 1, 0);
    return 0;
}