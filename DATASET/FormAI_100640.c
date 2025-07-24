//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void addition();
void subtraction();
void multiplication();
void division();
void power();
void square();
void cube();
void squareroot();
void cuberoot();
void logarithm();
void sine();
void cosine();
void tangent();


int main() {
    int choice;
    printf("Welcome to My C Scientific Calculator!\n");
    printf("\nPlease Select an Option:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square\n7. Cube\n8. Square Root\n9. Cube Root\n10. Logarithm\n11. Sine\n12. Cosine\n13. Tangent\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
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
            square();
            break;

        case 7:
            cube();
            break;

        case 8:
            squareroot();
            break;

        case 9:
            cuberoot();
            break;

        case 10:
            logarithm();
            break;

        case 11:
            sine();
            break;

        case 12:
            cosine();
            break;

        case 13:
            tangent();
            break;

        default:
            printf("Invalid Choice\n");
            break;
    }
    return 0;
}


void addition()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    result = num1 + num2;
    printf("Result: %lf\n", result);
}


void subtraction()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    result = num1 - num2;
    printf("Result: %lf\n", result);
}


void multiplication()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    result = num1 * num2;
    printf("Result: %lf\n", result);
}


void division()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    result = num1 / num2;
    printf("Result: %lf\n", result);
}


void power()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    result = pow(num1, num2);
    printf("Result: %lf\n", result);
}


void square()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = num * num;
    printf("Result: %lf\n", result);
}


void cube()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = num * num * num;
    printf("Result: %lf\n", result);
}


void squareroot()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = sqrt(num);
    printf("Result: %lf\n", result);
}


void cuberoot()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = cbrt(num);
    printf("Result: %lf\n", result);
}


void logarithm()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = log(num);
    printf("Result: %lf\n", result);
}


void sine()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = sin(num);
    printf("Result: %lf\n", result);
}


void cosine()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = cos(num);
    printf("Result: %lf\n", result);
}


void tangent()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);

    result = tan(num);
    printf("Result: %lf\n", result);
}