//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h> 
  
int factorial(int n) 
{ 
    if (n == 1 || n == 0) 
        return 1; 
    else
        return n * factorial(n - 1); 
} 
  
int fibonacci(int n) 
{ 
    if (n == 0) 
        return 0; 
    else if (n == 1) 
        return 1; 
    else
        return (fibonacci(n - 1) + fibonacci(n - 2)); 
} 
  
int main() 
{ 
    int choice, number; 
    
    printf("Welcome to my recursive program! What would you like to do?\n");
    printf("1. Calculate factorial\n");
    printf("2. Calculate fibonacci\n");
    scanf("%d", &choice); 
    
    switch(choice) {
        case 1:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &number);
            printf("The factorial of %d is %d\n", number, factorial(number));
            break;
        case 2:
            printf("Enter a number to calculate its fibonacci sequence: ");
            scanf("%d", &number);
            printf("The fibonacci sequence of %d is %d\n", number, fibonacci(number));
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }
    
}