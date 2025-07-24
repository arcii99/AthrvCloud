//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>

int main() {
    int n, i, flag;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    // loop through all the numbers between 1 and n
    for (i = 2; i <= n; i++) {
        // flag variable to indicate if i is a prime number
        flag = 1;

        // loop through all the numbers between 2 and i-1
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                // i is not a prime number
                flag = 0;
                break;
            }
        }

        // flag is still set to 1, meaning i is a prime number
        if (flag == 1) {
            printf("%d, ", i);
        }
    }

    return 0;
}