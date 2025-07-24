//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int option;
    double num1, num2, result=0;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an operation to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Power\n7. Square root\n");
    scanf("%d", &option);

    switch (option)
    {
      case 1:
        printf("Enter two numbers to perform addition:\n");
        scanf("%lf %lf", &num1, &num2);
        result = num1 + num2;
        printf("The sum of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 2:
        printf("Enter two numbers to perform subtraction:\n");
        scanf("%lf %lf", &num1, &num2);
        result = num1 - num2;
        printf("The difference of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 3:
        printf("Enter two numbers to perform multiplication:\n");
        scanf("%lf %lf", &num1, &num2);
        result = num1 * num2;
        printf("The product of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 4:
        printf("Enter two numbers to perform division:\n");
        scanf("%lf %lf", &num1, &num2);
        result = num1 / num2;
        printf("The quotient of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 5:
        printf("Enter two numbers to perform modulus:\n");
        scanf("%lf %lf", &num1, &num2);
        result = fmod(num1,num2);
        printf("The modulus of %.2lf and %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 6:
        printf("Enter the base and the exponent to perform power:\n");
        scanf("%lf %lf", &num1, &num2);
        result = pow(num1,num2);
        printf("%.2lf raised to the power of %.2lf is %.2lf\n", num1, num2, result);
        break;

      case 7:
        printf("Enter a number to perform square root:\n");
        scanf("%lf", &num1);
        result = sqrt(num1);
        printf("The square root of %.2lf is %.2lf\n", num1, result);
        break;

      default:
        printf("Invalid option selected. Please try again.\n");
        break;
    }

    return 0;
}