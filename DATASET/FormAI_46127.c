//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

// Function prototype
bool isPrime(int num);

int main() {
    int maxNum, num, count = 0;
    
    printf("Oh Romeo, Romeo, wherefore art thou,\n"); 
    printf("Enter thou maximum number for prime numbers:\n");
    scanf("%d", &maxNum);
    
    printf("Deny thy father and refuse thy name;\n");
    printf("For prime or not prime, that is my question:\n");
    
    for(num = 2; num <= maxNum; num++) {
        if(isPrime(num)) {
            printf("%d is a prime number!\n", num);
            count++;
        }
    }
    
    printf("Ah, Juliet, Juliet, wherefore art thou,\n");
    printf("%d prime numbers were found, my love!\n", count);
    
    return 0;
}

// Function to check if a number is prime or not
bool isPrime(int num) {
    int i;
    
    for(i = 2; i <= num/2; i++) {
        if(num%i == 0) {
            return false;
        }
    }
    
    return true;
}