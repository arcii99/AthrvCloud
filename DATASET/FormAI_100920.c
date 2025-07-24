//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int isPrime(int num);

int main() {
    int limit, i, count = 0;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Prime numbers between 1 and %d are:\n", limit);

    for(i=2; i<=limit; i++) {
        if(isPrime(i)) {
            count++;
            printf("%d ", i);
        }
    }

    printf("\nTotal prime numbers between 1 and %d are: %d\n", limit, count);

    return 0;
}

int isPrime(int num) {
    int i;

    for(i=2; i<num; i++) {
        if(num%i == 0)
            return 0;
    }

    return 1;
}