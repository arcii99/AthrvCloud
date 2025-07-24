//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int main()
{
    int i, n, j, flag;
    printf("Enter the number of prime numbers required:\n");
    scanf("%d", &n);
    printf("\nThe first %d prime numbers are: \n", n);
    for (i = 2; n > 0; i++) {
        flag = 1;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("%d ", i);
            n--;
        }
    }
    return 0;
}