//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include<stdio.h>
#include<math.h>

double add(double a, double b){ // function to add two numbers
    return a+b;
}

double subtract(double a, double b){ // function to subtract two numbers
    return a-b;
}

double multiply(double a, double b){ // function to multiply two numbers
    return a*b;
}

double divide(double a, double b){ // function to divide two numbers
    return a/b;
}

double power(double a, double b){ // function to find power of a number
    return pow(a,b);
}

double squareroot(double a){ // function to find the square root of a number
    return sqrt(a);
}

double logarithm(double a){ // function to find the logarithmic value of a number
    return log(a);
}

int main(){
    double num1, num2;
    char operation;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Choose the operation you want to perform (+, -, *, /, ^, S, L): ");
    scanf(" %c", &operation);
    switch(operation){
        case '+': 
            printf("%.2lf + %.2lf = %.2lf", num1, num2, add(num1,num2));
            break;
        case '-': 
            printf("%.2lf - %.2lf = %.2lf", num1, num2, subtract(num1,num2));
            break;
        case '*': 
            printf("%.2lf * %.2lf = %.2lf", num1, num2, multiply(num1,num2));
            break;
        case '/': 
            printf("%.2lf / %.2lf = %.2lf", num1, num2, divide(num1,num2));
            break;
        case '^':
            printf("%.2lf to the power of %.2lf = %.2lf", num1, num2, power(num1,num2));
            break;
        case 'S':
            printf("Square root of %.2lf = %.2lf", num1, squareroot(num1));
            break;
        case 'L':
            printf("Logarithmic value of %.2lf = %.2lf", num1, logarithm(num1));
            break;
        default:
            printf("Invalid operation selected.");
    }
    return 0;
}