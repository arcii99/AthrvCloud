//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>

int main() {
    int n, i, flag, count = 0;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are:\n", n);

    for (i = 2; count < n; i++) {
        flag = 1;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("%d ", i);
            count++;
        }
    }

    return 0;
}