//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

// A prime number is a number that is only divisible by 1 and itself.
// This function determines whether a given number is a prime number or not.
bool isPrime(int num) {
  
    // A number less than or equal to 1 is not a prime number
    if (num <= 1) {
        return false;
    }
    
    // A number greater than 2 that is even is not a prime number
    if (num > 2 && num % 2 == 0) {
        return false;
    }
    
    // Check if the number is divisible by any odd number between 3 and the square root of the number
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}


int main(void) {
  
    int num, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("The prime numbers between 1 and %d are: \n", num);
  
    // Iterate through all numbers from 1 to num and determine if they are prime or not
    for (int i = 2; i <= num; ++i) {

        if (isPrime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\nThere are %d prime numbers between 1 and %d.", count, num);
  
    return 0;
}