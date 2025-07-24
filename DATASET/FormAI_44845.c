//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include<stdio.h>

int isPrime(int); /*function to check if a number is prime or not*/

int main(){
    int num, count = 0, primes[50], i; /*count will keep track of how many primes have been found so far, primes will store the primes*/
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    for (i = 2; i <= num; i++){ /*iterating through all numbers from 2 to num*/
        if (isPrime(i)){
            primes[count] = i; /*if i is prime, add it to the primes array*/
            count++; /*increment the counter*/
        }
    }
    
    printf("The prime numbers from 2 to %d are: ", num);
    
    for (i = 0; i < count; i++){ /*printing out the primes*/
        printf("%d ", primes[i]);
    }
    
    printf("\n");
    return 0;
}

/*function to check if a number is prime or not*/
int isPrime(int num){
    int i;
    for (i = 2; i <= num/2; i++){
        if (num%i == 0){
            return 0; /*if num is divisible by any number between 2 and num/2, it is not prime*/
        }
    }
    return 1; /*if num is not divisible by any number between 2 and num/2, it is prime*/
}