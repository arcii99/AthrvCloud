//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    if(num < 2) {
        return false;
    }
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit;
    printf("Enter the maximum number to check for prime numbers: ");
    scanf("%d", &limit);

    for(int i = 2; i <= limit; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}