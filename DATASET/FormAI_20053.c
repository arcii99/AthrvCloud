//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include<stdio.h>

//Function to check if a given number is prime or not
int isPrime(int num){
    if(num <= 1){
        return 0;
    }
    for(int i=2; i*i<=num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int primes[n];
    //Initializing count of primes to 0
    int count = 0;
    //Finding all primes until n
    for(i=2; i<=n; i++){
        if(isPrime(i)){
            primes[count] = i;
            count++;
        }
    }
    printf("\nPrime numbers until %d are: ", n);
    //Printing all primes
    for(i=0; i<count; i++){
        printf("%d ", primes[i]);
    }
    printf("\n");
    return 0;
}