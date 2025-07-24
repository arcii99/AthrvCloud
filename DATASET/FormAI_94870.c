//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include<stdio.h>
#include<math.h>

// function prototypes for calculator operations
void addition();
void subtraction();
void multiplication();
void division();
void power();
void squareRoot();
void sinFn();
void cosFn();
void tanFn();
void cotFn();

int main(){
    // display user instructions
    printf("************Welcome to My Calculator************\n\n");
    printf("This calculator can perform the following operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Cotangent\n");
    printf("\nPlease enter the corresponding number for the operation you would like to perform:\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
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
            power();
            break;
        case 6:
            squareRoot();
            break;
        case 7:
            sinFn();
            break;
        case 8:
            cosFn();
            break;
        case 9:
            tanFn();
            break;
        case 10:
            cotFn();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}

// function to add two numbers
void addition(){
    double num1, num2;
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);
    printf("%lf + %lf = %lf\n", num1, num2, (num1+num2));
}

// function to subtract two numbers
void subtraction(){
    double num1, num2;
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);
    printf("%lf - %lf = %lf\n", num1, num2, (num1-num2));
}

// function to multiply two numbers
void multiplication(){
    double num1, num2;
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);
    printf("%lf x %lf = %lf\n", num1, num2, (num1*num2));
}

// function to divide two numbers
void division(){
    double num1, num2;
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    // check for division by zero
    if(num2 == 0){
        printf("Error! Cannot divide by zero.\n");
    }
    else{
        printf("%lf / %lf = %lf\n", num1, num2, (num1/num2));
    }
}

// function for exponentiation
void power(){
    double num1, num2;
    printf("Please enter the base: ");
    scanf("%lf", &num1);
    printf("Please enter the exponent: ");
    scanf("%lf", &num2);
    printf("%lf raised to the power of %lf = %lf\n", num1, num2, pow(num1,num2));
}

// function for calculating square root
void squareRoot(){
    double num;
    printf("Please enter the number to calculate the square root of: ");
    scanf("%lf", &num);

    // check for negative numbers
    if(num < 0){
        printf("Error! Cannot calculate square root of a negative number.\n");
    }
    else{
        printf("Square root of %lf = %lf\n", num, sqrt(num));
    }
}

// function for calculating sin
void sinFn(){
    double num;
    printf("Please enter the angle in degrees: ");
    scanf("%lf", &num);
    printf("Sin(%lf) = %lf\n", num, sin((num*M_PI)/180));
}

// function for calculating cos
void cosFn(){
    double num;
    printf("Please enter the angle in degrees: ");
    scanf("%lf", &num);
    printf("Cos(%lf) = %lf\n", num, cos((num*M_PI)/180));
}

// function for calculating tan
void tanFn(){
    double num;
    printf("Please enter the angle in degrees: ");
    scanf("%lf", &num);
    printf("Tan(%lf) = %lf\n", num, tan((num*M_PI)/180));
}

// function for calculating cot
void cotFn(){
    double num;
    printf("Please enter the angle in degrees: ");
    scanf("%lf", &num);
    printf("Cot(%lf) = %lf\n", num, (1/tan((num*M_PI)/180)));
}