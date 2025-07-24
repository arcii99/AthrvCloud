//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main(){
    int choice;
    double num1, num2, result;

    printf("Welcome to my Visionary Scientific Calculator\n");
    printf("Please select the operation you would like to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Logarithm\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Addition\nEnter first number: ");
            scanf("%lf",&num1);
            printf("Enter second number: ");
            scanf("%lf",&num2);
            result = num1 + num2;
            printf("Result = %lf",result);
            break;
        case 2:
            printf("Subtraction\nEnter first number: ");
            scanf("%lf",&num1);
            printf("Enter second number: ");
            scanf("%lf",&num2);
            result = num1 - num2;
            printf("Result = %lf",result);
            break;
        case 3:
            printf("Multiplication\nEnter first number: ");
            scanf("%lf",&num1);
            printf("Enter second number: ");
            scanf("%lf",&num2);
            result = num1 * num2;
            printf("Result = %lf",result);
            break;
        case 4:
            printf("Division\nEnter first number: ");
            scanf("%lf",&num1);
            printf("Enter second number: ");
            scanf("%lf",&num2);
            result = num1 / num2;
            printf("Result = %lf",result);
            break;
        case 5:
            printf("Power\nEnter base: ");
            scanf("%lf",&num1);
            printf("Enter exponent: ");
            scanf("%lf",&num2);
            result = pow(num1,num2);
            printf("Result = %lf",result);
            break;
        case 6:
            printf("Square Root\nEnter number: ");
            scanf("%lf",&num1);
            result = sqrt(num1);
            printf("Result = %lf",result);
            break;
        case 7:
            printf("Logarithm\nEnter number: ");
            scanf("%lf",&num1);
            result = log10(num1);
            printf("Result = %lf",result);
            break;
        default:
            printf("Invalid input");
    }
}