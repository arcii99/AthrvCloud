//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int i, j, flag;
    printf("Prime numbers from 2 to %d are: \n", n);

    // Loop through numbers 2 to n
    for (i = 2; i <= n; i++) {
        flag = 0;

        // Check if i is prime
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        // If i is prime, print it
        if (flag == 0 && i != 1) {
            printf("%d ", i);
        }
    }

    return 0;
}