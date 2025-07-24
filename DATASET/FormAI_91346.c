//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include<stdio.h>
#include<stdlib.h>

/* Function for checking if a number is prime or not */
int isPrime(int n) {
    if(n<=1)
        return 0;
    for(int i=2; i<n; i++)
        if(n%i == 0)
            return 0;
    return 1;
}

int main() {
    int numOfPrimes, count = 0, num = 2;
    
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d", &numOfPrimes);
    
    while(count < numOfPrimes) {
        if(isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}