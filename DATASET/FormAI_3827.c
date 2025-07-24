//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include<stdio.h>
#include<math.h>

int main()
{
    int operation;
    float num1, num2, result;

    printf("\n\n\t\t---SCIENTIFIC CALCULATOR---\n");
    printf("\n\n\t\t ------------------------\n");

    printf("\n\n Available Mathematical Operations\n");
    printf("\n 1. Addition    (+) ");
    printf("\n 2. Subtraction (-) ");
    printf("\n 3. Multiplication (*) ");
    printf("\n 4. Division (/) ");
    printf("\n 5. Square (x²) ");
    printf("\n 6. Square Root (√x) ");
    printf("\n 7. Cube (x³) ");
    printf("\n 8. Cube Root (∛x) ");
    printf("\n 9. Power (x^n) ");
    printf("\n 10.Absolute (|x|) ");
    printf("\n 11.Logarithm (log10) ");
    printf("\n 12.natural logarithm (ln) ");
    printf("\n 13.Sine Value (sin) ");
    printf("\n 14.Cosine Value (cos) ");
    printf("\n 15.Tangent Value (tan) ");

    printf("\n\n Enter Your Choice: ");
    scanf("%d", &operation);

    switch(operation)
    {
        case 1:
            printf("\n\n Enter First Number: ");
            scanf("%f", &num1);
            printf("\n\n Enter Second Number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("\n\n The Sum is: %.2f", result);
            break;

        case 2:
            printf("\n\n Enter First Number: ");
            scanf("%f", &num1);
            printf("\n\n Enter Second Number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("\n\n The Difference is: %.2f", result);
            break;

        case 3:
            printf("\n\n Enter First Number: ");
            scanf("%f", &num1);
            printf("\n\n Enter Second Number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("\n\n The Product is: %.2f", result);
            break;

        case 4:
            printf("\n\n Enter First Number: ");
            scanf("%f", &num1);
            printf("\n\n Enter Second Number: ");
            scanf("%f", &num2);
            if(num2 == 0)
            {
                printf("\n\n Error: Cannot divide by Zero");
            }
            else
            {
                result = num1 / num2;
                printf("\n\n The Quotient is: %.2f", result);
            }
            break;

        case 5:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            result = num1 * num1;
            printf("\n\n The Square of %.2f is: %.2f", num1, result);
            break;

        case 6:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            if(num1 < 0)
            {
                printf("\n\n Error: Square Root of Negative Number is Not Possible.");
            }
            else
            {
                result = sqrt(num1);
                printf("\n\n The Square Root of %.2f is: %.2f", num1, result);
            }
            break;

        case 7:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            result = num1 * num1 * num1;
            printf("\n\n The Cube of %.2f is: %.2f", num1, result);
            break;

        case 8:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            if(num1 < 0)
            {
                printf("\n\n Error: Cube Root of Negative Number is Not Possible.");
            }
            else
            {
                result = cbrt(num1);
                printf("\n\n The Cube Root of %.2f is: %.2f", num1, result);
            }
            break;

        case 9:
            printf("\n\n Enter the Base Number: ");
            scanf("%f", &num1);
            printf("\n\n Enter the Exponent Value: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("\n\n The Result is: %.2f", result);
            break;

        case 10:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            result = fabs(num1);
            printf("\n\n The Absolute Value of %.2f is: %.2f", num1, result);
            break;

        case 11:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            if(num1 <= 0)
            {
                printf("\n\n Error: Logarithm of Negative Number or Zero is Not Possible.");
            }
            else
            {
                result = log10(num1);
                printf("\n\n The Logarithm (Base 10) of %.2f is: %.2f", num1, result);
            }
            break;

        case 12:
            printf("\n\n Enter a Number: ");
            scanf("%f", &num1);
            if(num1 <= 0)
            {
                printf("\n\n Error: Natural Logarithm of Negative Number or Zero is Not Possible.");
            }
            else
            {
                result = log(num1);
                printf("\n\n The Natural Logarithm of %.2f is: %.2f", num1, result);
            }
            break;

        case 13:
            printf("\n\n Enter an Angle in Radians: ");
            scanf("%f", &num1);
            result = sin(num1);
            printf("\n\n The Sine Value of %.2f Radians is: %.2f", num1, result);
            break;

        case 14:
            printf("\n\n Enter an Angle in Radians: ");
            scanf("%f", &num1);
            result = cos(num1);
            printf("\n\n The Cosine Value of %.2f Radians is: %.2f", num1, result);
            break;

        case 15:
            printf("\n\n Enter an Angle in Radians: ");
            scanf("%f", &num1);
            result = tan(num1);
            printf("\n\n The Tangent Value of %.2f Radians is: %.2f", num1, result);
            break;

        default:
            printf("\n\n Error: Invalid Input");
    }

    printf("\n\n");

    return 0;
}