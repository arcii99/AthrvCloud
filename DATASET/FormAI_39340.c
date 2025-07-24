//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>

int isPrime(int num) {
    int i;
    if (num < 2) {
        return 0;
    }
    for (i = 2; i <= num/2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: ", num);

    for (i = 2; i <= num; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}