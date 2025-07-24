//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }

    if (num == 2 || num == 3) {
        return 1;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= num) {
        if (num % (divisor - 1) == 0 || num % (divisor + 1) == 0) {
            return 0;
        }
        divisor += 6;
    }

    return 1;
}

void printPrimes(int start, int end) {
    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Enter the range to generate prime numbers (start end): ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    printPrimes(start, end);

    return 0;
}