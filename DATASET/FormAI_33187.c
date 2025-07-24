//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display_menu();
void addition();
void subtraction();
void multiplication();
void division();
void square_root();
void logarithm();
void power();

int main()
{
    int choice;
    
    do
    {
        display_menu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                square_root();
                break;
            case 6:
                logarithm();
                break;
            case 7:
                power();
                break;
            case 8:
                printf("\nThank you for using Shape Shifting Calculator!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);
}

void display_menu()
{
    printf("\n=========================\n");
    printf(" SHAPE SHIFTING CALCULATOR ");
    printf("\n=========================\n\n");
    
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Logarithm\n");
    printf("7. Power\n");
    printf("8. Exit\n");
}

void addition()
{
    int num1, num2;
    
    printf("\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\n%d + %d = %d\n", num1, num2, num1 + num2);
}

void subtraction()
{
    int num1, num2;
    
    printf("\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\n%d - %d = %d\n", num1, num2, num1 - num2);
}

void multiplication()
{
    int num1, num2;
    
    printf("\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\n%d x %d = %d\n", num1, num2, num1 * num2);
}

void division()
{
    int num1, num2;
    
    printf("\nEnter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    if(num2 == 0)
    {
        printf("\nCannot divide by zero!\n");
    }
    else
    {
        printf("\n%d / %d = %d\n", num1, num2, num1 / num2);
    }
}

void square_root()
{
    double num;
    
    printf("\nEnter a number: ");
    scanf("%lf", &num);
    
    if(num < 0)
    {
        printf("\nCannot find square root of a negative number!\n");
    }
    else
    {
        printf("\nSquare root of %lf is %lf\n", num, sqrt(num));
    }
}

void logarithm()
{
    double num;
    
    printf("\nEnter a number: ");
    scanf("%lf", &num);
    
    if(num <= 0)
    {
        printf("\nCannot find logarithm of a non-positive number!\n");
    }
    else
    {
        printf("\nLogarithm of %lf is %lf\n", num, log(num));
    }
}

void power()
{
    double base, exponent;
    
    printf("\nEnter the base: ");
    scanf("%lf", &base);
    
    printf("\nEnter the exponent: ");
    scanf("%lf", &exponent);
    
    printf("\n%lf ^ %lf = %lf\n", base, exponent, pow(base, exponent));
}