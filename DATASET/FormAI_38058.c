//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototype function declaration
void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void power();
void square_root();
void logarithm();
void sine();
void cosine();
void tangent();

int main()
{
    int choice;

    while (1)
    {
        // Display the menu options
        printf("\n---------------Scientific Calculator---------------");
        printf("\n1. Addition\t\t2. Subtraction");
        printf("\n3. Multiplication\t4. Division");
        printf("\n5. Modulus\t\t6. Power");
        printf("\n7. Square Root\t\t8. Logarithm");
        printf("\n9. Sine\t\t\t10. Cosine");
        printf("\n11. Tangent\t\t0. Exit");
        printf("\n--------------------------------------------------");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        // Call function based on user's choice
        case 0:
            printf("\nThank you for using the calculator!");
            exit(0);
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
            modulus();
            break;
        case 6:
            power();
            break;
        case 7:
            square_root();
            break;
        case 8:
            logarithm();
            break;
        case 9:
            sine();
            break;
        case 10:
            cosine();
            break;
        case 11:
            tangent();
            break;
        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

void addition()
{
    double num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 + num2;

    printf("\n%lf + %lf = %lf", num1, num2, result);
}

void subtraction()
{
    double num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 - num2;

    printf("\n%lf - %lf = %lf", num1, num2, result);
}

void multiplication()
{
    double num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 * num2;

    printf("\n%lf * %lf = %lf", num1, num2, result);
}

void division()
{
    double num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 / num2;

    printf("\n%lf / %lf = %lf", num1, num2, result);
}

void modulus()
{
    int num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    result = num1 % num2;

    printf("\n%d %% %d = %d", num1, num2, result);
}

void power()
{
    double num, exponent, result;

    printf("\nEnter number: ");
    scanf("%lf", &num);

    printf("Enter exponent: ");
    scanf("%lf", &exponent);

    result = pow(num, exponent);

    printf("\n%lf ^ %lf = %lf", num, exponent, result);
}

void square_root()
{
    double num, result;

    printf("\nEnter number: ");
    scanf("%lf", &num);

    result = sqrt(num);

    printf("\nSquare root of %lf = %lf", num, result);
}

void logarithm()
{
    double num, base, result;

    printf("\nEnter number: ");
    scanf("%lf", &num);

    printf("Enter base: ");
    scanf("%lf", &base);

    result = log(num) / log(base);

    printf("\nlog%lf(%lf) = %lf", base, num, result);
}

void sine()
{
    double angle, result;

    printf("\nEnter angle: ");
    scanf("%lf", &angle);

    result = sin(angle);

    printf("\nsin(%lf) = %lf", angle, result);
}

void cosine()
{
    double angle, result;

    printf("\nEnter angle: ");
    scanf("%lf", &angle);

    result = cos(angle);

    printf("\ncos(%lf) = %lf", angle, result);
}

void tangent()
{
    double angle, result;

    printf("\nEnter angle: ");
    scanf("%lf", &angle);

    result = tan(angle);

    printf("\ntan(%lf) = %lf", angle, result);
}