//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isParanoidPrime(int num) {
    if (!isPrime(num)) {
        return false;
    }

    int temp = num;
    while (temp > 0) {
        if (!isPrime(temp)) {
            return false;
        }
        temp /= 10;
    }
    return true;
}

int main() {
    int num;
    printf("Enter a number to generate paranoid primes : ");
    scanf("%d", &num);

    printf("Paranoid primes from 1 to %d:\n", num);
    for (int i = 2; i <= num; i++) {
        if (isParanoidPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}