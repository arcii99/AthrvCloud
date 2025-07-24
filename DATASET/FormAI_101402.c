//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
#include<stdio.h>
#include<math.h>

void addition(double a, double b){
    printf("%.2lf + %.2lf = %.2lf\n", a, b, a+b);
}

void subtraction(double a, double b){
    printf("%.2lf - %.2lf = %.2lf\n", a, b, a-b);
}

void multiplication(double a, double b){
    printf("%.2lf x %.2lf = %.2lf\n", a, b, a*b);
}

void division(double a, double b){
    if(b==0.0) // checking for divide by zero error
        printf("Cannot divide by zero!\n");
    else
        printf("%.2lf / %.2lf = %.2lf\n", a, b, a/b);
}

// function to determine n factorial (n!)
double factorial(double n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

// function to calculate power of a base number
double power(double a, double b){
    return pow(a,b);
}

void trigonometry(double a){
    printf("sin(%.2lf) = %.2lf\n", a, sin(a));
    printf("cos(%.2lf) = %.2lf\n", a, cos(a));
    printf("tan(%.2lf) = %.2lf\n", a, tan(a));
}

void logarithm(double a){
    printf("log(%.2lf) = %.2lf\n", a, log10(a));
    printf("ln(%.2lf) = %.2lf\n", a, log(a));
}

int main(){
    int choice;
    double num1, num2;

    printf("WELCOME TO THE SCIENTIFIC CALCULATOR\n");
    printf("------------------------------------\n");

    do{
        printf("Please select an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Factorial\n");
        printf("6. Power\n");
        printf("7. Trigonometry\n");
        printf("8. Logarithm\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                addition(num1, num2);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                subtraction(num1, num2);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                multiplication(num1, num2);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                division(num1, num2);
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("%.2lf! = %.2lf\n", num1, factorial(num1));
                break;

            case 6:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, power(num1, num2));
                break;

            case 7:
                printf("Enter a number (in radians): ");
                scanf("%lf", &num1);
                trigonometry(num1);
                break;

            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                logarithm(num1);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice!=0);

    printf("Thank you for using the calculator!\n");
    return 0;
}