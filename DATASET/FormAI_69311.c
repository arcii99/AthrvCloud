//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter the value of n: ");
    scanf("%d", &num);
    printf("Prime numbers are: \n");
    
    // start loop from 2 to n
    for (i = 2; i <= num; i++) {
        // check if i is prime
        for (j = 2; j <= i; j++) {
            if (i % j == 0) {
                // i is not prime, break inner loop
                break;
            }
        }
        // j <= i for prime numbers, print them
        if (j <= i) {
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}