//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: irregular
#include <stdio.h>

int main(){
    int isPrime = 1; //flag for prime number
    
    for(int i=2; i<=100; i++){ //looping through numbers, starting from 2
        for(int j=2; j<=i/2; j++){ //looping through factors
            if(i%j == 0){ //if factor is found
                isPrime = 0; //set flag to false
            }
        }
        
        if(isPrime){ //if prime number
            printf("%d is a prime number.\n", i); //print prime number
        }
        
        isPrime = 1; //reset flag for the next number
    }
    
    return 0;
}