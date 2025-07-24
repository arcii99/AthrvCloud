//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

void recursivePrint(int n, int i);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    recursivePrint(n, 1);
    printf("\n");
    return 0;
}

void recursivePrint(int n, int i) {
    if (i <= n) {
        int j;
        for (j = 0; j < (n - i); j++) {
            printf("   ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for (j = i - 1; j > 0; j--) {
            printf("%d ", j);
        }
        printf("\n");
        recursivePrint(n, i+1);
        for (j = 0; j < (n - i); j++) {
            printf("   ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for (j = i - 1; j > 0; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}