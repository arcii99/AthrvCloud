//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    int choice;
    double num1, num2, ans;

    printf("Welcome to the Scientific Calculator!\n");
    printf("------------------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Square root\n");
    printf("7. Trigonometric Functions\n");
    printf("8. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two values to add: ");
                scanf("%lf %lf", &num1, &num2);
                ans = num1 + num2;
                printf("The sum of %.2lf and %.2lf is: %.2lf\n", num1, num2, ans);
                break;

            case 2:
                printf("Enter two values to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                ans = num1 - num2;
                printf("The difference between %.2lf and %.2lf is: %.2lf\n", num1, num2, ans);
                break;

            case 3:
                printf("Enter two values to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                ans = num1 * num2;
                printf("The product of %.2lf and %.2lf is: %.2lf\n", num1, num2, ans);
                break;

            case 4:
                printf("Enter two values to divide: ");
                scanf("%lf %lf", &num1, &num2);
                ans = num1 / num2;
                printf("The quotient of %.2lf and %.2lf is: %.2lf\n", num1, num2, ans);
                break;

            case 5:
                printf("Enter the base value: ");
                scanf("%lf", &num1);
                printf("Enter the exponent value: ");
                scanf("%lf", &num2);
                ans = pow(num1, num2);
                printf("%.2lf to the power of %.2lf is: %.2lf\n", num1, num2, ans);
                break;

            case 6:
                printf("Enter a value to calculate the square root of: ");
                scanf("%lf", &num1);
                ans = sqrt(num1);
                printf("The square root of %.2lf is: %.2lf\n", num1, ans);
                break;

            case 7:
                printf("Trigonometric Functions:\n");
                printf("-----------------------\n");
                printf("1. Sine\n");
                printf("2. Cosine\n");
                printf("3. Tangent\n");
                printf("4. Arcsine\n");
                printf("5. Arccosine\n");
                printf("6. Arctangent\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                printf("Enter a value (in degrees): ");
                scanf("%lf", &num1);

                switch (choice) {
                    case 1:
                        ans = sin(num1 * PI / 180);
                        printf("The sine of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    case 2:
                        ans = cos(num1 * PI / 180);
                        printf("The cosine of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    case 3:
                        ans = tan(num1 * PI / 180);
                        printf("The tangent of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    case 4:
                        ans = asin(num1) * 180 / PI;
                        printf("The arcsine of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    case 5:
                        ans = acos(num1) * 180 / PI;
                        printf("The arccosine of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    case 6:
                        ans = atan(num1) * 180 / PI;
                        printf("The arctangent of %.2lf degrees is: %.2lf\n", num1, ans);
                        break;

                    default:
                        printf("Invalid choice!\n");
                }

                break;

            case 8:
                printf("Thank you for using the Scientific Calculator!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}