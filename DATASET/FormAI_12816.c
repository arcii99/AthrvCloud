//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    int count, num = 2;
    printf("Enter the number of prime numbers you want to generate:\n");
    scanf("%d", &count);
    printf("The first %d prime numbers are:\n", count);
    while (count > 0) {
        if (isPrime(num)) {
            printf("%d ", num);
            count--;
        }
        num++;
    }
    printf("\n");
    return 0;
}