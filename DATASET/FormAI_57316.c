//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_gen(int num) {
    int primes[num];
    int count = 0;
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }
    printf("Prime numbers up to %d are: ", num);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter a number to generate prime numbers up to: ");
    scanf("%d", &num);
    prime_gen(num);
    return 0;
}