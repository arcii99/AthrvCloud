//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Prime Number Generator!");
    printf("\nEnter a number: ");
    int num;
    scanf("%d", &num);

    if(num <= 1){
        printf("\n%d is not a prime number\n", num);
        exit(0);
    }

    int isPrime = 1; // Assume that num is prime initially
    for(int i=2; i<=num/2; i++){ // start the loop
        if(num%i == 0){ // check if a divisor exists
            isPrime = 0;
            break;
        }
    }

    if(isPrime){ // if not divisible by any other number
        printf("\n%d is a prime number!\n", num); // print the number
    } else {
        printf("\n%d is not a prime number\n", num); // print a negative
    }

    // Thank you for using our Prime Number Generator!
    return 0;
}