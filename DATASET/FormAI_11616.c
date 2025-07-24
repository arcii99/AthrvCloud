//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit){
    int count = 0;
    printf("List of prime numbers below %d:\n", limit);
    for(int num = 2; num <= limit; num++){
        if(isPrime(num)){
            printf("%d ", num);
            count++;
        }
    }
    printf("\nThere are %d prime numbers below %d.\n", count, limit);
}

int main(){
    int limit;
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d", &limit);
    generatePrimes(limit);
    return 0;
}