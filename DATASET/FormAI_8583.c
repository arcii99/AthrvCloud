//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>

int isPrime(int num) {
    // check if num is prime
    int i;
    for (i=2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0; // not a prime
        }
    }
    return 1; // is a prime
}

int main() {
    int count, num = 0, i = 1;
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d",&count);
    while (i <= count){
        if (isPrime(num)) {
            printf("%d ", num);
            i++;
        }
        num++;
    }
    return 0;
}