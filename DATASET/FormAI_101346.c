//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;
    printf("Enter the max limit to generate prime numbers: ");
    scanf("%d", &num);
    printf("Prime numbers up to %d are: ", num);
    for (int i = 2; i <= num; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}