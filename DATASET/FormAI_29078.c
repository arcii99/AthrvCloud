//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function Declarations
void print_menu();
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
int power(int, int);
int factorial(int);
double sine(double);
double cosine(double);
double tangent(double);
double square_root(double);

// Main Function
int main()
{
    int choice, num1, num2;
    double num3;
    char operator;
    
    do
    {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:     // Addition
                printf("Enter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                printf("Sum: %d\n", add(num1, num2));
                break;
            
            case 2:     // Subtraction
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &num1, &num2);
                printf("Difference: %d\n", subtract(num1, num2));
                break;
            
            case 3:     // Multiplication
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                printf("Product: %d\n", multiply(num1, num2));
                break;
                
            case 4:     // Division
                printf("Enter two numbers to divide: ");
                scanf("%d %d", &num1, &num2);
                if(num2 == 0)
                {
                    printf("Cannot divide by 0");
                    break;
                }
                printf("Quotient: %d\n", divide(num1, num2));
                break;
            
            case 5:     // Power
                printf("Enter a number and its power: ");
                scanf("%d %d", &num1, &num2);
                printf("%d raised to the power %d is %d\n", num1, num2, power(num1, num2));
                break;
                
            case 6:     // Factorial
                printf("Enter a number to find its factorial: ");
                scanf("%d", &num1);
                printf("Factorial of %d is %d\n", num1, factorial(num1));
                break;
            
            case 7:     // Sine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num3);
                printf("Sine of %lf degrees is %lf\n", num3, sine(num3));
                break;
                
            case 8:     // Cosine
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num3);
                printf("Cosine of %lf degrees is %lf\n", num3, cosine(num3));
                break;
                
            case 9:     // Tangent
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num3);
                printf("Tangent of %lf degrees is %lf\n", num3, tangent(num3));
                break;
                
            case 10:    // Square Root
                printf("Enter a number to find its square root: ");
                scanf("%lf", &num3);
                printf("Square root of %lf is %lf\n", num3, square_root(num3));
                break;
                
            case 11:    // Quit
                printf("Exiting...\n");
                exit(0);
                break;
            
            default:    // Invalid choice
                printf("Invalid choice! Try again.\n");
                break;
        }
        
        // Ask user if they want to continue
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &operator);
        
    } while(operator == 'Y' || operator == 'y');
    
    return 0;
}

// Function Definitions
void print_menu()
{
    printf("\n***CALCULATOR MENU***\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Square Root\n");
    printf("11. Quit\n");
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int divide(int num1, int num2)
{
    return num1 / num2;
}

int power(int num1, int num2)
{
    return pow(num1, num2);
}

int factorial(int num1)
{
    if(num1 == 1 || num1 == 0)
        return 1;
    else
        return num1 * factorial(num1 - 1);
}

double sine(double num3)
{
    return sin(num3 * (M_PI/180));
}

double cosine(double num3)
{
    return cos(num3 * (M_PI/180));
}

double tangent(double num3)
{
    return tan(num3 * (M_PI/180));
}

double square_root(double num3)
{
    return sqrt(num3);
}