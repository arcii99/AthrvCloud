//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int main() {
    int n, i, j, flag;
    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &n);
    printf("Prime numbers are:\n");
    for (i = 2; i <= n; i++) {
        flag = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}