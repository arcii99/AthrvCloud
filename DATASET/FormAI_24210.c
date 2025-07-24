//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    int divisor;
    for (divisor = 2; divisor * divisor <= num; divisor++) {
        if (num % divisor == 0)
            return false;
    }
    return true;
}

void generatePrimes(int range) {
    printf("The prime numbers within the range of 1 to %d are: ", range);
    int i;
    for (i = 2; i <= range; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int range;
    printf("Enter the range to generate prime numbers: ");
    scanf("%d", &range);
    generatePrimes(range);
    printf("\n");
    return 0;
}