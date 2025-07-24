//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>

int isPrime(int num);

int main() {
    int i, n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("\nThe first %d prime numbers are:\n", n);
    
    for(i = 2; n > 0; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            n--;
        }
    }
    
    return 0;
}

int isPrime(int num) {
    int i;
    for(i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}