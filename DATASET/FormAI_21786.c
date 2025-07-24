//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int is_prime(int n) {
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
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid number of prime numbers to generate\n");
        return 1;
    }
    int i = 2;
    int count = 0;
    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    printf("\n");
    return 0;
}