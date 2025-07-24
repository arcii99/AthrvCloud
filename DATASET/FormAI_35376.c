//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, n, isPrime;
    printf("Let's generate some prime numbers!\n\n");
    printf("Enter the maximum range: ");
    scanf("%d", &n);
    printf("\nGenerating Prime Numbers between 2 and %d:\n\n", n);
    
    // Loop through all numbers from 2 to n
    for(i=2; i<=n; i++){
        isPrime = 1;   // Assume prime
        
        // Check if number is divisible by any number from 2 to i-1
        for(j=2; j<i; j++){
            if(i%j == 0){
                isPrime = 0;   // Not prime
                break;
            }
        }
        
        // If the number is prime, print it
        if(isPrime){
            printf("%d ", i);
        }
    }
    printf("\n\nDone generating prime numbers!");
    return 0;
}