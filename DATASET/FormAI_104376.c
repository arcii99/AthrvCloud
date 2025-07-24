//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000

void calculatePrimes(int *primes, int *size) {
    int nums[MAX];
    for (int i = 0; i < MAX; i++) {
        nums[i] = 1;
    }
    nums[0] = 0;
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (nums[i - 1] == 1) {
            for (int j = i * i; j <= MAX; j += i) {
                nums[j - 1] = 0;
            }
        }
    }
    int idx = 0;
    for (int i = 0; i < MAX && idx < 10; i++) {
        if (nums[i] == 1) {
            primes[idx] = i + 1;
            idx++;
        }
    }
    *size = idx;
}

int main() {
    int primes[10];
    int size;
    calculatePrimes(primes, &size);
    printf("The first %d prime numbers are:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
    }
    return 0;
}