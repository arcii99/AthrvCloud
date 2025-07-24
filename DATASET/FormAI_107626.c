//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    int choice, num1, num2, result, factorial, i;
    double sine, cosine, tangent, logarithm, power, root;

    printf("Welcome to the Scientific Calculator!\n");

    do {
        printf("\nEnter your choice:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Factorial\n6. Sine\n7. Cosine\n8. Tangent\n9. Logarithm\n10. Power\n11. Square Root\n12. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d%d", &num1, &num2);
                result = num1 + num2;
                printf("%d + %d = %d\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%d%d", &num1, &num2);
                result = num1 - num2;
                printf("%d - %d = %d\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d%d", &num1, &num2);
                result = num1 * num2;
                printf("%d x %d = %d\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%d%d", &num1, &num2);
                result = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, result);
                break;

            case 5:
                printf("Enter a number to find its factorial: ");
                scanf("%d", &num1);
                factorial = 1;

                for(i = 1; i <= num1; i++) {
                    factorial = factorial * i;
                }

                printf("%d! = %d\n", num1, factorial);
                break;

            case 6:
                printf("Enter the angle in degrees to find its sine: ");
                scanf("%lf", &sine);
                sine = sin(sine * M_PI / 180);
                printf("Sine of %.2lf degrees = %.2lf\n", sine, sine);
                break;

            case 7:
                printf("Enter the angle in degrees to find its cosine: ");
                scanf("%lf", &cosine);
                cosine = cos(cosine * M_PI / 180);
                printf("Cosine of %.2lf degrees = %.2lf\n", cosine, cosine);
                break;

            case 8:
                printf("Enter the angle in degrees to find its tangent: ");
                scanf("%lf", &tangent);
                tangent = tan(tangent * M_PI / 180);
                printf("Tangent of %.2lf degrees = %.2lf\n", tangent, tangent);
                break;

            case 9:
                printf("Enter a number to find its natural logarithm: ");
                scanf("%lf", &logarithm);
                logarithm = log(logarithm);
                printf("Natural logarithm of %.2lf = %.2lf\n", logarithm, logarithm);
                break;

            case 10:
                printf("Enter two numbers to find their power: ");
                scanf("%lf%lf", &num1, &num2);
                power = pow(num1, num2);
                printf("%.2lf raised to the power of %.2lf = %.2lf\n", num1, num2, power);
                break;

            case 11:
                printf("Enter a number to find its square root: ");
                scanf("%lf", &root);
                root = sqrt(root);
                printf("Square root of %.2lf = %.2lf\n", root, root);
                break;

            case 12:
                printf("Thank you for using the Scientific Calculator!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 12);

    return 0;
}