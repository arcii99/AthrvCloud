//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    if(n < 2) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num, i=3, count, c;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);
   
    if(num >= 1) {
        printf("\nFirst %d prime numbers are: ", num);
        printf("%d ", 2);
    }

    for(count = 2; count <= num;) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }        
    return 0;
}