//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include<stdio.h> 
#include<stdlib.h> 

int factorial(int n) { 
    if (n == 0 || n == 1) { 
        return 1; 
    } 
    else { 
        return n * factorial(n - 1); 
    } 
} 

int main() { 
    int n; 

    printf("Enter a number: "); 
    scanf("%d", &n); 
  
    int fact = factorial(n); 

    printf("Factorial of %d is: %d\n", n, fact); 

    return 0; 
}