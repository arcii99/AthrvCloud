//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Donald Knuth
#include <stdio.h> 

int is_prime(int n) //function to check if number is prime
{ 
    if (n <= 1) 
        return 0; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return 0; 
  
    return 1; 
} 
  
void generate_primes(int n) //function to generate prime numbers
{ 
    int primes[n]; //array to store prime numbers
    int i, j;
    int count = 0;
    for (i = 1; count < n; i++) { 
        if (is_prime(i)) { 
            primes[count++] = i; //store prime number in the array
        } 
    } 
    printf("%d prime numbers are:\n", n);
    for (j = 0; j < n; j++) { 
        printf("%d \n", primes[j]); //print array of prime numbers
    } 
} 
  
int main() 
{ 
    int n = 50; //number of prime numbers to generate
    generate_primes(n); 
    return 0; 
}