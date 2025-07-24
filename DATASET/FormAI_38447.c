//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number) {
    if (number == 2) {
        return true;
    }
    if (number < 2 || number % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input!\n");
        return 0;
    }
    int i = 2;
    int count = 0;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    printf("\n");
    return 0;
}