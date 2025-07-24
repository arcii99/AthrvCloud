//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>

int main()
{
    int n, i, flag;
    printf("Enter the maximum number: ");
    scanf("%d", &n);
    printf("Prime numbers between 1 and %d are: ", n);

    // Traverse each number from 1 to n
    for (i = 1; i <= n; i++) {

        // Check if i is a prime number
        flag = 1;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        // Print the prime number
        if (flag == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}