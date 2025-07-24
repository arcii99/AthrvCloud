//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    int n, i;
    printf("Enter the number up to which you want to generate prime numbers: ");
    scanf("%d", &n);
    printf("The prime numbers up to %d are: \n", n);

    for(i = 2; i <= n; i++) {
        if(isPrime(i)) {
            printf("%d, ", i);
        }
    }

    return 0;
}

bool isPrime(int n) {
    int i;
    if(n == 2 || n == 3) {
        return true;
    }
    else if(n % 2 == 0) {
        return false;
    }
    else {
        for(i = 3; i*i <= n; i += 2) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
}