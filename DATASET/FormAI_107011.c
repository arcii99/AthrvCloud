//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h> //for bool datatype
#include <math.h> //for sqrt()

// Function to check whether a number is prime or not. 
bool isPrime(int num) 
{ 
    // Base case 
    if (num <= 1) 
        return false; //not prime 
    
    // Check for each number from 2 to sqrt(n) 
    for (int i = 2; i <= sqrt(num); i++) 
        if (num % i == 0) //if divisible 
            return false; //not prime 
    
    return true; //prime number 
} 

int main()
{
  int n; //limit for prime numbers 
  printf("Enter the limit till where you want to generate prime numbers: ");
  scanf("%d", &n);

  // Checking each number whether it is prime or not 
  printf("\nPrime numbers between 1 and %d are: ", n);
  for (int i = 2; i <= n; i++) 
    if (isPrime(i)) 
      printf("%d ", i);

  printf("\n\nThe game is afoot! We have successfully generated prime numbers using our magnificent program.\n");
  printf("Elementary, my dear Watson!\n");
  return 0;
}