//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

int main()
{
    int n, i, flag, count = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The prime numbers between 1 and %d are:\n", n);

    // loop through all numbers from 2 to n
    for (i = 2; i <= n; i++) {
        flag = 0;
        // check if i is a prime number
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of prime numbers between 1 and %d is %d\n", n, count);

    return 0;
}