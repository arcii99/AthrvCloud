//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime or not
bool isPrime(int n)
{
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;

    // prompt user to enter the limit
    printf("Enter the limit: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are:\n", n);

    // loop through all the numbers from 1 to n
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}