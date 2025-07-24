//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1)
        return false;
        
    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: \n", n);
    
    int count = 0;
    int i = 2;
    
    while (count < n) {
        if (isPrime(i)) {
            count++;
            printf("%d ", i);
        }
        i++;
    }
    return 0;
}