//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int count = 0, currentNumber = 2, maxNumber, numPerRow;
    
    printf("Enter the maximum number to generate primes: ");
    scanf("%d", &maxNumber);
    printf("Enter the number of primes to display per row: ");
    scanf("%d", &numPerRow);
    
    printf("The prime numbers between 2 and %d are:\n", maxNumber);
    
    while (currentNumber <= maxNumber) {
        if (isPrime(currentNumber)) {
            printf("%d ", currentNumber);
            count++;
            if (count % numPerRow == 0)
                printf("\n");
        }
        currentNumber++;
    }
    
    return 0;
}