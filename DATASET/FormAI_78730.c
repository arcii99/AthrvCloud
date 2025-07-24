//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>

int isPrime(int num); 

int main() {
    int n, i, count = 0, limit;
    
    printf("Enter the limit: ");
    scanf("%d", &limit);
    
    printf("The prime numbers between 1 and %d are: \n", limit);
    
    for(n=2; n<=limit; n++) {
        if(isPrime(n)) {
            count++;
            printf("%d ", n);
        }
    }
    
    printf("\n\nTotal %d prime numbers found between 1 and %d.\n", count, limit);
    
    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    int i;
    for(i=2; i<=num/2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}