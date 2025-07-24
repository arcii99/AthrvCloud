//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: active
#include <stdio.h>

int main() {
    int n, i, j, flag;

    printf("Enter the value of n:");
    scanf("%d", &n);

    if (n >= 2) {
        printf("Prime numbers are:\n2\n");
    }

    for (i = 3; i <= n; i++) {
        flag = 1;

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}