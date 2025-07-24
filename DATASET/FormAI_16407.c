//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) { //function to check if a number is prime
    if(num <= 1) {
        return false;
    }
    for(int i=2; i*i<=num; i++) {
        if(num%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; // variable for user input
    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    printf("The prime numbers between 1 and %d are:\n", n);
    for(int i=2; i<=n; i++) {
        if(isPrime(i)) { //if the number is prime
            printf("%d ", i); //print the number
        }
    }
    return 0;
}