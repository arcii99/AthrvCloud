//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function for calculating square root of a number
double squareRoot(double num){
    double result = sqrt(num);
    return result;
}

// Function for calculating factorial of a number
double factorial(double num){
    if (num == 0) 
        return 1;
    else 
        return (num * factorial(num-1));
}

// Function for calculating power of a number
double power(double base, double exponent){
    double result = pow(base, exponent);
    return result;
}

// Function for calculating sine of an angle in radians
double sine(double angle){
    double result = sin(angle);
    return result;
}

// Function for calculating cosine of an angle in radians
double cosine(double angle){
    double result = cos(angle);
    return result;
}

// Function for calculating tangent of an angle in radians
double tangent(double angle){
    double result = tan(angle);
    return result;
}

// Function for calculating log of a number
double logarithm(double num){
    double result = log(num);
    return result;
}

// Main function for execution
int main(){
    int choice;
    double num, num2, result;
    char op;

    // Menu-driven calculator
    while(1){
        printf("\nMenu:\n");
        printf("1. Square Root\n");
        printf("2. Factorial\n");
        printf("3. Power\n");
        printf("4. Sine\n");
        printf("5. Cosine\n");
        printf("6. Tangent\n");
        printf("7. Logarithm\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter a number: ");
                scanf("%lf", &num);
                result = squareRoot(num);
                printf("\nSquare Root of %.2lf = %.2lf\n", num, result);
                break;
            
            case 2:
                printf("\nEnter a number: ");
                scanf("%lf", &num);
                result = factorial(num);
                printf("\nFactorial of %.2lf = %.2lf\n", num, result);
                break;
            
            case 3:
                printf("\nEnter the base: ");
                scanf("%lf", &num);
                printf("Enter the exponent: ");
                scanf("%lf", &num2);
                result = power(num, num2);
                printf("\n%.2lf raised to the power of %.2lf = %.2lf\n", num, num2, result);
                break;
            
            case 4:
                printf("\nEnter the angle in radians: ");
                scanf("%lf", &num);
                result = sine(num);
                printf("\nSin(%.2lf) = %.2lf\n", num, result);
                break;
            
            case 5:
                printf("\nEnter the angle in radians: ");
                scanf("%lf", &num);
                result = cosine(num);
                printf("\nCos(%.2lf) = %.2lf\n", num, result);
                break;
            
            case 6:
                printf("\nEnter the angle in radians: ");
                scanf("%lf", &num);
                result = tangent(num);
                printf("\nTan(%.2lf) = %.2lf\n", num, result);
                break;
            
            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num);
                result = logarithm(num);
                printf("\nLog(%.2lf) = %.2lf\n", num, result);
                break;
            
            case 8:
                exit(0);
            
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}