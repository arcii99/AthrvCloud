//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

double getNumber(char prompt[]) {
    double num;
    printf("%s", prompt);
    scanf("%lf", &num);
    return num;
}

void printResult(char prompt[], double result) {
    printf("%s %lf\n", prompt, result);
}

int main() {
    int choice;
    char operations[] = "+-*/%^";
    double result, num1, num2, angle;

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n");
        printf("5. Modulus (%%)\n6. Power (^)\n7. Square Root\n8. Cube Root\n9. Sine\n10. Cosine\n11. Tangent\n12. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 12)
            break;

        if (choice == 7 || choice == 8 || choice >= 9) {
            angle = getNumber("Enter angle (in degrees): ");
            angle = angle * (PI / 180.0);
        } else {
            num1 = getNumber("Enter the first number: ");
            num2 = getNumber("Enter the second number: ");
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printResult("Result:", result);
                break;
            case 2:
                result = num1 - num2;
                printResult("Result:", result);
                break;
            case 3:
                result = num1 * num2;
                printResult("Result:", result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Cannot divide by zero\n");
                } else {
                    result = num1 / num2;
                    printResult("Result:", result);
                }
                break;
            case 5:
                if (num2 == 0) {
                    printf("Error: Cannot modulo by zero\n");
                } else {
                    result = fmod(num1, num2);
                    printResult("Result:", result);
                }
                break;
            case 6:
                result = pow(num1, num2);
                printResult("Result:", result);
                break;
            case 7:
                result = sqrt(angle);
                printResult("Result:", result);
                break;
            case 8:
                result = cbrt(angle);
                printResult("Result:", result);
                break;
            case 9:
                result = sin(angle);
                printResult("Result:", result);
                break;
            case 10:
                result = cos(angle);
                printResult("Result:", result);
                break;
            case 11:
                if (cos(angle) == 0) {
                    printf("Error: Cannot tangent angle of 90 degrees\n");
                } else {
                    result = tan(angle);
                    printResult("Result:", result);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}