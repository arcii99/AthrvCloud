//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int count = 0;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &count);
    
    printf("The first %d prime numbers are:\n", count);
    int num = 2;
    int prime_count = 0;
    while (prime_count < count) {
        if (is_prime(num)) {
            printf("%d\n", num);
            prime_count++;
        }
        num++;
    }
    return 0;
}