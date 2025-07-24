//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter the maximum number to generate primes up to: ");
    scanf("%d", &num);
    int primes[num];
    int count = 0;
    for (i = 2; i <= num; i++) {
        int isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            primes[count] = i;
            count++;
        }
    }
    printf("Primes up to %d: ", num);
    for (i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    return 0;
}