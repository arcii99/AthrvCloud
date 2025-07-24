//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: active
#include <stdio.h>

int isPrime(int num) {
    if(num < 2) return 0;

    int i;
    for(i = 2; i * i <= num; i++) {
        if(num % i == 0) return 0;
    }

    return 1;
}

int main() {
    int num, i;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    printf("The first %d prime numbers are:\n", num);

    for(i = 2; num > 0; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            num--;
        }
    }

    return 0;
}