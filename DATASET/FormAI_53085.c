//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  

// Function to perform addition  
void add()  
{  
    float num1, num2, result;  
    printf("\nEnter the first number: ");  
    scanf("%f", &num1);  
    printf("\nEnter the second number: ");  
    scanf("%f", &num2);  
    result = num1 + num2;  
    printf("\nThe sum of %f and %f is: %f\n", num1, num2, result);  
}  
  
// Function to perform subtraction  
void subtract()  
{  
    float num1, num2, result;  
    printf("\nEnter the first number: ");  
    scanf("%f", &num1);  
    printf("\nEnter the second number: ");  
    scanf("%f", &num2);  
    result = num1 - num2;  
    printf("\nThe difference between %f and %f is: %f\n", num1, num2, result);  
}  
  
// Function to perform multiplication  
void multiply()  
{  
    float num1, num2, result;  
    printf("\nEnter the first number: ");  
    scanf("%f", &num1);  
    printf("\nEnter the second number: ");  
    scanf("%f", &num2);  
    result = num1 * num2;  
    printf("\nThe product of %f and %f is: %f\n", num1, num2, result);  
}  
  
// Function to perform division  
void divide()  
{  
    float num1, num2, result;  
    printf("\nEnter the first number: ");  
    scanf("%f", &num1);  
    printf("\nEnter the second number: ");  
    scanf("%f", &num2);  
    result = num1 / num2;  
    printf("\nThe quotient of %f and %f is: %f\n", num1, num2, result);  
}  
  
// Function to perform square root  
void squareroot()  
{  
    float num, result;  
    printf("\nEnter the number: ");  
    scanf("%f", &num);  
    result = sqrt(num);  
    printf("\nThe square root of %f is: %f\n", num, result);  
}  
  
// Function to perform power of a number  
void power()  
{  
    float num1, num2, result;  
    printf("\nEnter the base number: ");  
    scanf("%f", &num1);  
    printf("\nEnter the power: ");  
    scanf("%f", &num2);  
    result = pow(num1, num2);  
    printf("\n%.2f to the power of %.2f is: %.2f\n", num1, num2, result);  
}  
  
int main()  
{  
    int choice;  

    printf("Welcome to the Scientific Calculator\n\n");
  
    do  
    {  
        printf("\n\nChoose your Operation:\n");  
        printf("\nPress 1 for Addition");  
        printf("\nPress 2 for Subtraction");  
        printf("\nPress 3 for Multiplication");  
        printf("\nPress 4 for Division");  
        printf("\nPress 5 for Square Root");  
        printf("\nPress 6 for Power of a Number");  
        printf("\nPress 7 to Exit");  
  
        printf("\nEnter your choice: ");  
        scanf("%d", &choice);  
  
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
                squareroot();  
                break;  
            case 6:  
                power();  
                break;  
            case 7:  
                exit(0);  
                break;  
            default:  
                printf("\nInvalid Choice. Please enter a valid choice.\n");  
        }  
    }
    while(choice != 7);  
  
    return 0;  
}