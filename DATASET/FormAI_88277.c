//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() {

    int n, i, flag, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: \n", n);

    for (i = 2; i <= n; i++) {

        flag = 1;

        for (int j = 2; j <= i/2; j++) {
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

    printf("\n\nTotal number of prime numbers between 1 and %d is %d\n", n, count);

    printf("\n\nWow! We did it! How exciting was that? We just generated all the prime numbers between 1 and %d!\n", n);

    return 0;
}