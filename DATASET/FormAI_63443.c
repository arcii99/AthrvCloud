//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

int isPrime(int n) {
    int i;
    if(n<2) {
        return 0;
    }
    for(i=2; i<=n/2; i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i;
    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);
    int count = 0;
    for(i=2; count<n; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}