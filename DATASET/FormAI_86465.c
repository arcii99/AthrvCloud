//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

bool isPrime(const int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num, count = 0;

    printf("Enter the number of prime numbers you wish to generate: ");
    scanf("%d", &num);

    printf("The first %d prime numbers are: ", num);

    for (int i = 2; count < num; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }

    return 0;
}