//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){  //function to check if number is prime
    if (n == 2 || n == 3)
        return true;
    if (n == 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int n, i = 2, count = 0;

    printf("Enter n to generate first n prime numbers: ");
    scanf("%d", &n);

    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }

    return 0;
}