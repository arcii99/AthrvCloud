//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>

int isPrime(int num);

int main() {
   int lowerLimit, upperLimit, i, isPrimeFlag = 0;
   
   printf("Enter lower limit: ");
   scanf("%d", &lowerLimit);

   printf("\nEnter upper limit: ");
   scanf("%d", &upperLimit);
   
   printf("\nPrime numbers between %d and %d are: ", lowerLimit, upperLimit);
   
   for(i=lowerLimit+1; i<upperLimit; i++) {
      isPrimeFlag = isPrime(i);
      if(isPrimeFlag == 1) {
         printf("%d, ", i);
      }
   }
   
   printf("\n");
   
   return 0;
}

int isPrime(int num) {
   int j;
   
   if(num == 1 || num == 0) { // base case
      return 0;
   }
   
   for(j=2; j<=num/2; j++) {
      if(num%j == 0) { // not a prime number
         return 0;
      }
   }
   
   return 1; // is a prime number
}