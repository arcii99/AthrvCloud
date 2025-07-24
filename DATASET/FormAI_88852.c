//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// define a macro for minimum prime
#define MIN_PRIME 2

// function to check whether a number is prime or not
int isPrime(int num){
    int i;
    for(i=2; i<=sqrt(num); i++){
        if(num%i == 0)
            return 0;
    }
    return 1;
}

// function to generate prime numbers
void primeGenerator(int count){
    int i=MIN_PRIME, num_primes=0;
    while(num_primes < count){
        if(isPrime(i)){
            printf("%d ", i);
            num_primes++;
        }
        i++;
    }
}

// driver function
int main(){
    int count;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &count);
    printf("The first %d prime numbers are:\n", count);
    primeGenerator(count);
    return 0;
}