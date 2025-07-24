//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
    int a, b, sum, diff, product;
    float quotient;
    
    // prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &a);
    
    printf("Enter the second number: ");
    scanf("%d", &b);
    
    // perform arithmetic operations
    sum = a + b;
    diff = a - b;
    product = a * b;
    quotient = (float)a / (float)b;
    
    // output results
    printf("The sum of the two numbers is: %d\n", sum);
    printf("The difference of the two numbers is: %d\n", diff);
    printf("The product of the two numbers is: %d\n", product);
    printf("The quotient of the two numbers is: %.2f\n", quotient);
    
    return 0;
}