//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x, y; //declaring int variables to store inputs
    char op; //declaring a char variable to store operation
    
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y); //taking inputs from user
    
    printf("Enter the operation you want to perform (+, -, *, /): ");
    scanf(" %c", &op); //taking input operation from user
    
    switch(op) //switch case statement for different operations
    {
        case '+':
            printf("%d + %d = %d", x, y, x+y); //adding two numbers
            break;
        case '-':
            printf("%d - %d = %d", x, y, x-y); //subtracting two numbers
            break;
        case '*':
            printf("%d * %d = %d", x, y, x*y); //multiplying two numbers
            break;
        case '/':
            printf("%d / %d = %d", x, y, x/y); //dividing two numbers
            break;
        default:
            printf("Invalid operation!"); //if user enters invalid operation
            break;
    }
    return 0;
}