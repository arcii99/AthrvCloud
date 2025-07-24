//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i, n;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    printf("The first %d prime numbers are: \n", n);

    for (i = 2; n > 0; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            n--;
        }
    }

    return 0;
}