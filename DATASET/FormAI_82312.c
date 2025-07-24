//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include<stdio.h> 

unsigned long int factorial(unsigned int n) 
{ 
    if (n == 0) 
       return 1; 
    return n * factorial(n-1); 
} 

int main() 
{ 
    unsigned int num = 5; 
    printf("Factorial of %d is %lu", num, factorial(num)); 
    return 0; 
}