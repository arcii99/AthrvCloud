//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>

// function to check if a number is prime
int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &n);

    int arr[n], index = 0;

    // loop through numbers 1 to n and check if they are prime
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            arr[index++] = i;
        }
    }

    printf("Prime numbers generated: \n");
    for (int i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}