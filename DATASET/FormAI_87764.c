//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>

int main() {

    int i, j, flag, n, count = 0;
    printf("Enter the range of numbers to check for prime numbers: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are:\n", n);

    for (i = 2; i <= n; i++) {
        flag = 0;

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            count++;
            printf("%d ", i);
        }
    }

    printf("\nTotal number of prime numbers between 1 and %d are: %d", n, count);

    return 0;
}