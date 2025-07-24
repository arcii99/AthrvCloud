//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include<stdio.h>
#include<math.h>

int main() {

    int choice;
    float num1, num2, result;
    printf("Enter operation choice:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square Root\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("Result: %f", result);
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("Result: %f", result);
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("Result: %f", result);
            break;

        case 4:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            if(num2 == 0) {
                printf("Error: Divide By Zero\n");
            }
            else {
                result = num1 / num2;
                printf("Result: %f", result);
            }
            break;

        case 5:
            printf("Enter base: ");
            scanf("%f", &num1);
            printf("Enter exponent: ");
            scanf("%f", &num2);
            result = pow(num1, num2);
            printf("Result: %f", result);
            break;

        case 6:
            printf("Enter number: ");
            scanf("%f", &num1);
            if(num1 < 0) {
                printf("Error: Invalid Input\n");
            }
            else {
                result = sqrt(num1);
                printf("Result: %f", result);
            }
            break;

        default:
            printf("Error: Invalid Choice\n");
            break;
    }

    return 0;
}