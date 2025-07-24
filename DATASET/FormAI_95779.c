//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>

int isPrime(int num) {
    if(num <= 1) return 0;
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num, i = 2;
    printf("Enter the number of primes you want to generate: ");
    scanf("%d", &num);

    printf("The first %d prime numbers are:\n", num);
    while(num > 0) {
        if(isPrime(i)) {
            printf("%d ", i);
            num--;
        }
        i++;
    }
    return 0;
}