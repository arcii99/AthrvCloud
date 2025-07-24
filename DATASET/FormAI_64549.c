//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int limit, i;

    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers between 1 and %d are: ", limit);

    for(i = 2; i <= limit; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

bool is_prime(int num) {
    int i;

    if(num <= 1) {
        return false;
    }

    for(i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}