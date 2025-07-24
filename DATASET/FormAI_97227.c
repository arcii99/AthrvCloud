//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i <= n/2; i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

void primeGenerator(int N) {
    int i, count = 0;
    printf("List of prime numbers between 1 and %d: \n", N);
    for (i = 2; i <= N; i++) {
        if (prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal number of prime numbers in the list: %d\n", count);
}

int main() {
    int n;
    printf("Enter the upper limit of the range you want to generate prime numbers for: ");
    scanf("%d", &n);
    primeGenerator(n);
    return 0;
}