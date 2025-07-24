//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>

int main() {
   int num, i, isPrime;
   
   printf("Get ready to generate PRIME NUMBERS!\n");
   printf("Enter an integer greater than 1: ");
   
   scanf("%d", &num); 
  
   if (num <=1) {
        printf("Invalid input, please try again!\n");
        return 0; 
   }
   
   printf("Generating prime numbers up to %d:\n", num);
   
   // Check every number from 2 up to the input value
   for(int n = 2; n <= num; n++) {
        isPrime = 1;
        // Check if n is divisible by any number from 2 to n-1
        for(i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d is a prime number!\n", n);
        }
   }
   
   printf("All prime numbers up to %d have been generated!\n", num);
   return 0; 
}