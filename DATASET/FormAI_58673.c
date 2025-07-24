//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>

// function to check if a number is prime
int isPrime(int n){
    if(n <= 1)
        return 0;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

// main function
int main(){
    int count = 0;
    int num = 2;
    while(count < 100){   // generate first 100 prime numbers
        if(isPrime(num)){
            printf("%d ", num);
            count++;
        }
        num++;
    }
    return 0;
}