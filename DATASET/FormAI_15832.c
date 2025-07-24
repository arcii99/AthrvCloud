//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
#include <stdio.h>

#define SIZE 1000000

int main() {
    int i, j;
    int primes[SIZE] = {2};
    int num_primes = 1;
    
    for(i = 3; i <= SIZE; i += 2) {
        for(j = 0; j < num_primes; j++) {
            if(i % primes[j] == 0) {
                break;
            }
        }
        if(j == num_primes) {
            primes[num_primes++] = i;
        }
    }
    
    for(i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\nTotal number of primes: %d\n", num_primes);
    
    return 0;
}