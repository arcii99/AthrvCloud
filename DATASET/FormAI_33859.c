//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

void calculate(char operator, double num1, double num2);
double sine(double num);
double cosine(double num);
double tangent(double num);
double logarithm(double num);
double exponent(double num);
double power(double base, double exponent);
double square_root(double num);
double absolute_value(double num);

int main(){
    int choice;
    double num1, num2;
    printf("\nWelcome to my Scientific Calculator! You can use this calculator to solve various scientific calculations.\n");
    while(1){
        printf("Please select an operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Sine\n6. Cosine\n7. Tangent\n8. Logarithm\n9. Exponent\n10. Power\n11. Square Root\n12. Absolute Value\n13. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                calculate(choice+41, num1, num2);
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Sine of %lf is %lf\n", num1, sine(num1));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Cosine of %lf is %lf\n", num1, cosine(num1));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Tangent of %lf is %lf\n", num1, tangent(num1));
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Logarithm of %lf is %lf\n", num1, logarithm(num1));
                break;
            case 9:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Exponent of %lf is %lf\n", num1, exponent(num1));
                break;
            case 10:
                printf("Enter base: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                printf("Power of %lf^%lf is %lf\n", num1, num2, power(num1, num2));
                break;
            case 11:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Square root of %lf is %lf\n", num1, square_root(num1));
                break;
            case 12:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Absolute value of %lf is %lf\n", num1, absolute_value(num1));
                break;
            case 13:
                printf("Thank you for using my calculator!\n");
                exit(0);
                break;
            default:
                printf("Please choose a valid option!\n");
        }
    }
    return 0;
}

void calculate(char operator, double num1, double num2){
    switch(operator){
        case 42:
            printf("%lf + %lf = %lf\n", num1, num2, num1+num2);
            break;
        case 43:
            printf("%lf - %lf = %lf\n", num1, num2, num1-num2);
            break;
        case 44:
            printf("%lf * %lf = %lf\n", num1, num2, num1*num2);
            break;
        case 45:
            printf("%lf / %lf = %lf\n", num1, num2, num1/num2);
            break;
        default:
            printf("Error: Invalid operator!\n");
    }
}

double sine(double num){
    return sin(num*PI/180);
}

double cosine(double num){
    return cos(num*PI/180);
}

double tangent(double num){
    return tan(num*PI/180);
}

double logarithm(double num){
    return log(num);
}

double exponent(double num){
    return exp(num);
}

double power(double base, double exponent){
    return pow(base, exponent);
}

double square_root(double num){
    return sqrt(num);
}

double absolute_value(double num){
    return fabs(num);
}