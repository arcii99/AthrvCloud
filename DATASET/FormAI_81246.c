//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>

int isPrime(int num) {
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int start, end;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d: ", start, end);

    for(int i = start; i <= end; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}