//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int choice;
    float num, result;

    printf("My Scientific Calculator\n");
    printf("***********************\n\n");

    do {
        printf("\nEnter the operation you want to perform:\n");
        printf("1. Square root\n");
        printf("2. Power\n");
        printf("3. Sine\n");
        printf("4. Cosine\n");
        printf("5. Tangent\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a number: ");
                scanf("%f", &num);
                result = sqrt(num);
                printf("The square root of %.2f is %.2f.\n", num, result);
                break;
            case 2:
                printf("\nEnter a number: ");
                scanf("%f", &num);
                printf("Enter the power to raise: ");
                int power;
                scanf("%d", &power);
                result = pow(num, power);
                printf("%.2f raised to the power of %d is %.2f.\n", num, power, result);
                break;
            case 3:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &num);
                result = sin(num * M_PI / 180);
                printf("The sine of %.2f degrees is %.2f.\n", num, result);
                break;
            case 4:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &num);
                result = cos(num * M_PI / 180);
                printf("The cosine of %.2f degrees is %.2f.\n", num, result);
                break;
            case 5:
                printf("\nEnter an angle in degrees: ");
                scanf("%f", &num);
                result = tan(num * M_PI / 180);
                printf("The tangent of %.2f degrees is %.2f.\n", num, result);
                break;
            case 6:
                printf("\nThanks for using the calculator. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }

        printf("\n\n");

    } while (choice != 6);

    return 0;
}