//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num){
    int i;
    for(i = 2; i < num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void primeGenerator(int n){
    int primeCount = 0;
    int currentNum = 2;
    while(primeCount < n){
        if(isPrime(currentNum)){
            printf("%d ", currentNum);
            primeCount++;
        }
        currentNum++;
    }
}

int main(){
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are: ", n);
    primeGenerator(n);
    printf("\n");

    return 0;
}