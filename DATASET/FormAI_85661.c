//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, i = 2;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    while (n > 0) {
        if (is_prime(i)) {
            printf("%d ", i);
            n--;
        }
        i++;
    }
    return 0;
}