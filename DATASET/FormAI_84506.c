//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b){
    return a+b;
}

double subtract(double a, double b){
    return a-b;
}

double multiply(double a, double b){
    return a*b;
}

double divide(double a, double b){
    return a/b;
}

double power(double a, double b){
    return pow(a,b);
}

int main() {
    printf("Welcome to the Scientific Calculator!\n");
    printf("Enter your first number: ");
    double num1;
    scanf("%lf",&num1);
    printf("Enter your second number: ");
    double num2;
    scanf("%lf",&num2);

    printf("What operation would you like to perform?\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");

    int operation;
    scanf("%d",&operation);

    switch(operation){
        case 1:
            printf("Result: %.2lf",add(num1,num2));
            break;
        case 2:
            printf("Result: %.2lf",subtract(num1,num2));
            break;
        case 3:
            printf("Result: %.2lf",multiply(num1,num2));
            break;
        case 4:
            printf("Result: %.2lf",divide(num1,num2));
            break;
        case 5:
            printf("Result: %.2lf",power(num1,num2));
            break;
        default:
            printf("Invalid operation selected!");
    }

    return 0;
}