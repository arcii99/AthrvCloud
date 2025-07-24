//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
//This program will generate a series of prime numbers until user input is satisfied
#include<stdio.h>

int main() {
    int n, prime, i, j; //initialize variables
    
    printf("How many prime numbers do you want to generate?\n");
    scanf("%d", &n); //take user input
    
    int primes[n], count = 0;
    primes[count++] = 2; //initialize the first prime number
    
    for (i = 3; count < n; i += 2) { //start at 3, go to the nth prime
        prime = 1;
        
        for (j = 3; j <= i/2; j += 2) { //check if number is prime
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        
        if (prime) {
            primes[count++] = i; //store prime number in array
        }
    }
    
    printf("The first %d prime numbers are: ", n);
    
    for (i = 0; i < n; i++) { //print out the prime numbers
        printf("%d ", primes[i]);
    }
    
    printf("\n"); //formatting
    
    return 0;
}