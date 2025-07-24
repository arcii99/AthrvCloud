//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void printBanner() {
    printf("***************************\n");
    printf("*                         *\n");
    printf("*    Medieval Calculator  *\n");
    printf("*                         *\n");
    printf("***************************\n\n");
}

int main() {
    int choice, num1, num2, result;

    printBanner();

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n\n");

    scanf("%d", &choice);

    printf("\nEnter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("\n %d + %d = %d \n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n %d - %d = %d \n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n %d * %d = %d \n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0) {
                printf("\nDivide by zero error\n");
                exit(0);
            }
            result = num1 / num2;
            printf("\n %d / %d = %d \n", num1, num2, result);
            break;
        default:
            printf("\nInvalid operator choice\n");
            break;
    }

    printf("\nThank you for using Medieval Calculator");

    return 0;
}