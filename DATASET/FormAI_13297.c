//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

int main(){

    bool isPrime[MAX + 1];

    // Initializing the array to true
    for(int i = 2;i<=MAX;i++){
        isPrime[i] = true;
    }

    // Sieve of Eratosthenes algorithm
    for(int i = 2;i * i <= MAX;i++){
        if(isPrime[i]){
            for(int j = i * i;j<=MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }

    // Printing prime numbers from 1 to 1000
    printf("Prime numbers from 1 to 1000 are: ");
    for(int i=2;i<=MAX;i++){
        if(isPrime[i]){
            printf("%d ", i);
        }
    }

    return 0;
}