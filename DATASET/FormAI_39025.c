//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
//This is a Scientific Calculator implementation program in C, inspired by the work of Alan Turing.

#include <stdio.h>
#include <math.h>

int choice; //global variable to store user's input for choice

int main() {
    printf("Welcome to Alan Turing's Scientific Calculator\n\n");
    do {
        printf("Please select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square\n");
        printf("6. Square root\n");
        printf("7. Logarithm\n");
        printf("8. Sine\n");
        printf("9. Cosine\n");
        printf("10. Tangent\n");
        printf("11. Exit\n\n");
        printf("Enter your choice (1-11): ");
        scanf("%d", &choice);
        
        switch(choice) { //switch statement to execute user's choice
            case 1: //Addition
                add();
                break;
            case 2: //Subtraction
                subtract();
                break;
            case 3: //Multiplication
                multiply();
                break;
            case 4: //Division
                divide();
                break;
            case 5: //Square
                square();
                break;
            case 6: //Square root
                squareRoot();
                break;
            case 7: //Logarithm
                logarithm();
                break;
            case 8: //Sine
                sine();
                break;
            case 9: //Cosine
                cosine();
                break;
            case 10: //Tangent
                tangent();
                break;
            case 11: //Exit
                printf("Thank you for using Alan Turing's Scientific Calculator!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while(choice != 11);
    return 0;
}

void add() {
    double num1, num2, sum;
    printf("\nEnter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    sum = num1 + num2;
    printf("The sum of %.2lf and %.2lf is: %.2lf\n", num1, num2, sum);
}

void subtract() {
    double num1, num2, diff;
    printf("\nEnter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    diff = num1 - num2;
    printf("The difference between %.2lf and %.2lf is: %.2lf\n", num1, num2, diff);
}

void multiply() {
    double num1, num2, prod;
    printf("\nEnter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    prod = num1 * num2;
    printf("The product of %.2lf and %.2lf is: %.2lf\n", num1, num2, prod);
}

void divide() {
    double num1, num2, quotient;
    printf("\nEnter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    if(num2 == 0) {
        printf("Error! Division by zero is undefined.\n");
        return;
    }
    quotient = num1 / num2;
    printf("The quotient of %.2lf and %.2lf is: %.2lf\n", num1, num2, quotient);
}

void square() {
    double num, sq;
    printf("\nEnter a number: ");
    scanf("%lf", &num);
    sq = pow(num, 2);
    printf("The square of %.2lf is: %.2lf\n", num, sq);
}

void squareRoot() {
    double num, root;
    printf("\nEnter a number: ");
    scanf("%lf", &num);
    if(num < 0) {
        printf("Error! Square root of negative number is undefined.\n");
        return;
    }
    root = sqrt(num);
    printf("The square root of %.2lf is: %.2lf\n", num, root);
}

void logarithm() {
    double num;
    printf("\nEnter a number: ");
    scanf("%lf", &num);
    if(num <= 0) {
        printf("Error! Logarithm of non-positive number is undefined.\n");
        return;
    }
    double logValue=log10(num);
    printf("The logarithm of %.2lf is: %.2lf\n", num, logValue);
}

void sine() {
    double num;
    printf("\nEnter an angle in degrees: ");
    scanf("%lf", &num);
    double radian=num*(3.14/180);
    double sinValue=sin(radian);
    printf("The sine of %.2lf degrees is: %.2lf\n", num, sinValue);
}

void cosine() {
    double num;
    printf("\nEnter an angle in degrees: ");
    scanf("%lf", &num);
    double radian=num*(3.14/180);
    double cosValue=cos(radian);
    printf("The cosine of %.2lf degrees is: %.2lf\n", num, cosValue);
}

void tangent() {
    double num;
    printf("\nEnter an angle in degrees: ");
    scanf("%lf", &num);
    double radian=num*(3.14/180);
    double tanValue=tan(radian);
    printf("The tangent of %.2lf degrees is: %.2lf\n", num, tanValue);
}