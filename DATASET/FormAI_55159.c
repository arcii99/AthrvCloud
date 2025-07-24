//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.14159265359

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
    if(b == 0){
        printf("Error! Division by zero.\n");
        exit(0);
    }
    return a/b;
}

double power(double a, double b){
    return pow(a,b);
}

double squareRoot(double a){
    if(a < 0){
        printf("Error! Square root of negative number.\n");
        exit(0);
    }
    return sqrt(a);
}

double sine(double a){
    return sin(a*PI/180);
}

double cosine(double a){
    return cos(a*PI/180);
}

double tangent(double a){
    return tan(a*PI/180);
}

double logarithm(double a){
    if(a <= 0){
        printf("Error! Logarithm of non-positive number.\n");
        exit(0);
    }
    return log10(a);
}

int main(){
    int choice;
    double num1,num2,result;
    
    printf("Welcome to the Scientific Calculator!\n\n");
    
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%lf %lf",&num1,&num2);
            result = add(num1,num2);
            printf("%.2f + %.2f = %.2f\n",num1,num2,result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf",&num1,&num2);
            result = subtract(num1,num2);
            printf("%.2f - %.2f = %.2f\n",num1,num2,result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf",&num1,&num2);
            result = multiply(num1,num2);
            printf("%.2f x %.2f = %.2f\n",num1,num2,result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf",&num1,&num2);
            result = divide(num1,num2);
            printf("%.2f / %.2f = %.2f\n",num1,num2,result);
            break;
        case 5:
            printf("Enter base number: ");
            scanf("%lf",&num1);
            printf("Enter exponent number: ");
            scanf("%lf",&num2);
            result = power(num1,num2);
            printf("%.2f ^ %.2f = %.2f\n",num1,num2,result);
            break;
        case 6:
            printf("Enter number to find square root: ");
            scanf("%lf",&num1);
            result = squareRoot(num1);
            printf("Square root of %.2f = %.2f\n",num1,result);
            break;
        case 7:
            printf("Enter angle in degrees: ");
            scanf("%lf",&num1);
            result = sine(num1);
            printf("Sine of %.2f = %.2f\n",num1,result);
            break;
        case 8:
            printf("Enter angle in degrees: ");
            scanf("%lf",&num1);
            result = cosine(num1);
            printf("Cosine of %.2f = %.2f\n",num1,result);
            break;
        case 9:
            printf("Enter angle in degrees: ");
            scanf("%lf",&num1);
            result = tangent(num1);
            printf("Tangent of %.2f = %.2f\n",num1,result);
            break;
        case 10:
            printf("Enter number to find logarithm: ");
            scanf("%lf",&num1);
            result = logarithm(num1);
            printf("Logarithm of %.2f = %.2f\n",num1,result);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
            break;
    }
    
    return 0;
}