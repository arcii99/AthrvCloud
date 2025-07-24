//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h> 

int main() { 
    double num1, num2, result; // declare double data type variables
    printf("Enter two numbers: \n"); 
    if(scanf("%lf %lf", &num1, &num2) != 2) { // check if user inputs 2 numbers
        printf("Error: Invalid input.\n"); 
        return -1; // terminate program with error value
    }
    if(num2 == 0) { // check if denominator is zero 
        printf("Error: Division by zero.\n"); 
        return -1; // terminate program with error value
    } 
    
    result = num1/num2; // perform division
    printf("%.2f divided by %.2f = %.2f\n", num1, num2, result); // print result with 2 decimal places
    return 0; // terminate program normally
}