//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void prime_generator(int limit) {
    bool prime[limit+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=limit; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=limit; i+=p) {
                prime[i] = false;
            }
        }
    }
    for (int p=2; p<=limit; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("The prime numbers less than or equal to %d are:\n", limit);
    prime_generator(limit);
    return 0;
}