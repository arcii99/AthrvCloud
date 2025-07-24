//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void exponential();
void square();
void squareroot();
void cube();
void cuberoot();
 
// Main function
int main()
{
    int choice;
 
    // Display the menu
    printf("Scientific calculator\n");
    printf("------------------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exponential\n");
    printf("6. Square\n");
    printf("7. Square root\n");
    printf("8. Cube\n");
    printf("9. Cube root\n");
    printf("Enter your choice: ");
 
    scanf("%d", &choice);
 
    // Perform the corresponding operation
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            exponential();
            break;
        case 6:
            square();
            break;
        case 7:
            squareroot();
            break;
        case 8:
            cube();
            break;
        case 9:
            cuberoot();
            break;
        default:
            printf("Invalid choice\n");
    }
 
    return 0;
}
 
// Function to add two numbers
void add()
{
    double x, y, result;
 
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &x, &y);
 
    result = x + y;
    printf("Result: %lf\n", result);
}
 
// Function to subtract two numbers
void subtract()
{
    double x, y, result;
 
    printf("Enter two numbers to subtract: ");
    scanf("%lf %lf", &x, &y);
 
    result = x - y;
    printf("Result: %lf\n", result);
}
 
// Function to multiply two numbers
void multiply()
{
    double x, y, result;
 
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &x, &y);
 
    result = x * y;
    printf("Result: %lf\n", result);
}
 
// Function to divide two numbers
void divide()
{
    double x, y, result;
 
    printf("Enter two numbers to divide: ");
    scanf("%lf %lf", &x, &y);
 
    if (y == 0)
    {
        printf("Error: Divide by zero\n");
        return;
    }
 
    result = x / y;
    printf("Result: %lf\n", result);
}
 
// Function to calculate the exponential of a number
void exponential()
{
    double x, result;
 
    printf("Enter a number: ");
    scanf("%lf", &x);
 
    result = exp(x);
    printf("Result: %lf\n", result);
}
 
// Function to calculate the square of a number
void square()
{
    double x, result;
 
    printf("Enter a number: ");
    scanf("%lf", &x);
 
    result = x * x;
    printf("Result: %lf\n", result);
}
 
// Function to calculate the square root of a number
void squareroot()
{
    double x, result;
 
    printf("Enter a number: ");
    scanf("%lf", &x);
 
    if (x < 0)
    {
        printf("Error: Invalid input\n");
        return;
    }
 
    result = sqrt(x);
    printf("Result: %lf\n", result);
}
 
// Function to calculate the cube of a number
void cube()
{
    double x, result;
 
    printf("Enter a number: ");
    scanf("%lf", &x);
 
    result = pow(x, 3);
    printf("Result: %lf\n", result);
}
 
// Function to calculate the cube root of a number
void cuberoot()
{
    double x, result;
 
    printf("Enter a number: ");
    scanf("%lf", &x);
 
    result = cbrt(x);
    printf("Result: %lf\n", result);
}