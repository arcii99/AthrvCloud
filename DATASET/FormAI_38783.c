//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num == 2 || num == 3) { // check if number is 2 or 3
        return true;
    }
    if (num % 2 == 0 || num == 1) { // check if number is even or 1
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) { // check if number is divisible by any odd number
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    printf("Enter the maximum number: ");
    scanf("%d", &n);
    
    printf("Prime numbers between 1 and %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal count: %d", count);
    
    return 0;
}