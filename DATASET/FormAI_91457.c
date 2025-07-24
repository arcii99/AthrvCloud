//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include<stdio.h>

int isPrime(int num){
    if(num == 2 || num == 3) return 1;   //2 and 3 are considered prime

    if(num == 1 || num % 2 == 0) return 0;   //1 is not prime and even numbers greater than 2 are not prime

    for(int i=3; i*i<=num; i+=2){    //iterate only through odd numbers
        if(num%i == 0) return 0;    //if the number is divisible by any of the odd numbers, then it is not prime
    }
    return 1;
}

int main(){
    int num, count = 0;

    printf("Enter the maximum limit till which prime numbers should be generated: ");
    scanf("%d", &num);

    printf("The prime numbers between 1 and %d are: ", num);
    for(int i = 1; i <= num; i++){
        if(isPrime(i)){
            count++;
            printf("%d ", i);
        }
    }
    printf("\n\nThere are a total of %d prime numbers from 1 to %d.\n", count, num);

    return 0;
}