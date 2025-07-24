//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int prime_check(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, count = 0;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);
    printf("The first %d prime numbers are: ", num);
    for (int i = 2; count < num; i++) {
        if (prime_check(i)) {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}