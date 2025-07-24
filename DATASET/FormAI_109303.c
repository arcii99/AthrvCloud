//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to check if a given number is prime
// Returns true if the number is prime, false otherwise.
bool isPrime(int n){
    // If n is less than 2, then it is not a prime number
    if(n < 2) return false;
    // Check if n is divisible by any number from 2 to n/2
    for(int i=2; i<=(n/2); i++){
        if(n%i == 0){
            return false;
        }
    }
    // If n is not divisible by any of the numbers from 2 to n/2, then it is a prime number
    return true;
}

// Function to generate all prime numbers from 1 to n
void generatePrime(int n){
    printf("Generating all prime numbers from 1 to %d\n", n);
    // Check for each number from 1 to n if it is a prime number
    for(int i=1; i<=n; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the maximum limit for prime numbers: ");
    // Read input from the user
    scanf("%d", &n);
    // Call the function to generate prime numbers
    generatePrime(n);
    return 0;
}