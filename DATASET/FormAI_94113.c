//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int num){
    if(num<=1){
        return 0;
    }
    for(int i=2;i<=num/2;i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

// Function to generate and print prime numbers up to n
void primeGenerator(int n){
    printf("Prime numbers up to %d:\n",n);
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    printf("\n");
}

// Main function to execute the program
int main(){
    int n;
    printf("Enter the maximum number to generate prime numbers: ");
    scanf("%d",&n);
    primeGenerator(n);
    return 0;
}