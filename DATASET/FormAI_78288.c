//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    int i;
    if(num == 1) return false;
    for (i=2; i<num; i++){
        if(num%i == 0){ 
            return false;
        }
    }
    return true;
}

void primeGenerator(int n){
    int i;
    printf("Prime numbers between 1 and %d are:\n", n);
    for (i=2; i<=n; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
}

int main(){
    int n;
    printf("Enter the range of prime numbers to be generated: ");
    scanf("%d", &n);
    primeGenerator(n);
    return 0;
}