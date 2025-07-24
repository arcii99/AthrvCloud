//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Welcome to the Super Scientific Calculator!\n");
    printf("Please enter the calculation you'd like to perform or type 'q' to quit: \n");
    char input[1000];
    fgets(input, 1000, stdin); // Get user input
    
    while (input[0] != 'q')
    {
        // Initialize variables
        double num1 = 0.0, num2 = 0.0, result = 0.0;
        char op;
        
        // Scan input for operator and numbers
        sscanf(input, "%lf %c %lf", &num1, &op, &num2);
        
        // Perform calculation based on operator
        switch (op)
        {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            case '^':
                result = pow(num1, num2);
                break;
            case 's': // sin function
                result = sin(num1);
                break;
            case 'c': // cos function
                result = cos(num1);
                break;
            case 't': // tan function
                result = tan(num1);
                break;
            case 'l': // log function
                result = log10(num1);
                break;
            case 'e': // exponential function
                result = exp(num1);
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
        
        printf("Result: %.2f\n", result); // Print result to two decimal places
        
        printf("Please enter the calculation you'd like to perform or type 'q' to quit: \n");
        fgets(input, 1000, stdin); // Get new user input
    }
    
    printf("Thank you for using the Super Scientific Calculator!");
    return 0;
}