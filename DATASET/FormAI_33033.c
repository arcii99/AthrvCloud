//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

void addition();
void subtraction();
void multiplication();
void division();
void power();
void logarithm();
void factorial();
void modulus();

int main() {
    int choice;

    while(1) {
        printf("Choose a mathematical operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Logarithm\n");
        printf("7. Factorial\n");
        printf("8. Modulus\n");
        printf("9. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
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
                logarithm();
                break;
            case 7:
                factorial();
                break;
            case 8:
                modulus();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addition() {
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);
    printf("Result: %.2lf\n", x+y);
}

void subtraction() {
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);
    printf("Result: %.2lf\n", x-y);
}

void multiplication() {
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);
    printf("Result: %.2lf\n", x*y);
}

void division() {
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);
    if(y!=0)
    printf("Result: %.2lf\n", x/y);
    else
    printf("Division by zero is invalid!\n");
}

void power() {
    double x, y;
    printf("Enter the base number: ");
    scanf("%lf", &x);
    printf("Enter the power: ");
    scanf("%lf", &y);
    printf("Result: %.2lf\n", pow(x,y));
}

void logarithm() {
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);
    printf("Result: %.2lf\n", log10(x));
}

void factorial() {
    int x;
    long int f=1;
    printf("Enter a non-negative integer: ");
    scanf("%d", &x);
    for(int i=1; i<=x; i++) {
        f*=i;
    }
    printf("Result: %ld\n", f);
}

void modulus() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("Result: %d\n", x%y);
}