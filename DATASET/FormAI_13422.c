//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    int count = 0, num = 2;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}