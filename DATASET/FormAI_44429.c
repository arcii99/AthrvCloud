//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>

int is_prime(int num) {
    int i;
    if (num == 2 || num == 3) return 1;
    if (num == 1 || num % 2 == 0 || num % 3 == 0) return 0;
    for (i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void primeGen(int n) {
    int num = 2, count = 0;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    primeGen(n);
    return 0;
}