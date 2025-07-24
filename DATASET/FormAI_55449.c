//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>

/* Function to check if a number is prime or not */
bool isPrime(int num) {
    int i;

    /* Check from 2 to num-1 if there is any factor of a number */
    for(i = 2; i < num; i++) {
        if(num % i == 0) {
            return false;  // Not a prime number
        }
    }

    /* If no factors found, then it is a prime number */
    return true;
}

/* Function to print all prime numbers upto n */
void generatePrimes(int n) {
    int num, i;

    /* Print all the prime numbers upto n */
    printf("Prime numbers upto %d are:\n", n);
    for(num = 2; num <= n; num++) {
        if(isPrime(num)) {
            printf("%d ", num);
        }
    }
}

/* Driver code to test above functions */
int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    /* Call function to generate all prime numbers upto n */
    generatePrimes(n);

    return 0;
}