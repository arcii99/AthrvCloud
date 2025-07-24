//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("\n\t\t~~~ Welcome to My Scientific Calculator ~~~\n");

    float num1, num2, result;
    int choice;

    printf("Enter the First Number:");
    scanf("%f", &num1);
    printf("\nEnter the Second Number:");
    scanf("%f", &num2);

    printf("\nPlease Select an Operation:");

    printf("\n\t1. Addition (+)\n");
    printf("\t2. Subtraction (-)\n");
    printf("\t3. Multiplication (*)\n");
    printf("\t4. Division (/)\n");
    printf("\t5. Power (^)\n");
    printf("\t6. Square Root (√)\n");
    printf("\t7. Logarithm (log10)\n");
    printf("\t8. Sine (sin)\n");
    printf("\t9. Cosine (cos)\n");
    printf("\t10.Tangent(tan)\n");

    printf("\nEnter Your Choice (1-10):");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        result = num1 + num2;
        printf("\n%.2f + %.2f = %.2f", num1, num2, result);
        break;

    case 2:
        result = num1 - num2;
        printf("\n%.2f - %.2f = %.2f", num1, num2, result);
        break;

    case 3:
        result = num1 * num2;
        printf("\n%.2f * %.2f = %.2f", num1, num2, result);
        break;

    case 4:
        result = num1 / num2;
        printf("\n%.2f / %.2f = %.2f", num1, num2, result);
        break;

    case 5:
        result = pow(num1, num2);
        printf("\n%.2f ^ %.2f = %.2f", num1, num2, result);
        break;

    case 6:
        result = sqrt(num1);
        printf("\n√%.2f = %.2f", num1, result);
        break;

    case 7:
        result = log10(num1);
        printf("\nlog10 %.2f = %.2f", num1, result);
        break;

    case 8:
        result = sin(num1);
        printf("\nsin %.2f = %.2f", num1, result);
        break;

    case 9:
        result = cos(num1);
        printf("\ncos %.2f = %.2f", num1, result);
        break;

    case 10:
        result = tan(num1);
        printf("\ntan %.2f = %.2f", num1, result);
        break;

    default:
        printf("\nInvalid Input. Please Try Again!");
    }

    printf("\n\n\t\t~~~ Thank You for Using My Calculator ~~~\n");
    return 0;
}