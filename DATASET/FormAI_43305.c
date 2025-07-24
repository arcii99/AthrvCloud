//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: brave
#include <stdio.h>

int check_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, count = 0;
    
    printf("This program generates prime numbers\n");
    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &n);
    
    printf("\nThe first %d prime numbers are:\n", n);
    
    for (int i = 2; count < n; i++) {
        if (check_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\n\nPress any key to exit...");
    getchar();  // Wait for user input before exit
    return 0;
}