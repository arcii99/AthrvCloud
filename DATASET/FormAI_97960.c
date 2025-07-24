//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    int mid = n/2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == mid || (i == 0 && j <= mid) || (i == n-1 && j >= mid) || (i == mid && j >= mid)) {
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