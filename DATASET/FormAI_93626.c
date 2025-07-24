//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include<stdio.h>
#include<math.h>

int main() {
    int option=0;
    float num1=0, num2=0, result=0;

    printf("Welcome to the Intelligent Scientific Calculator!\n");

    do {
        //Menu
        printf("\nChoose an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Square root\n");
        printf("6. Power\n");
        printf("7. Logarithm\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: //Addition
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;

            case 2: //Subtraction
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;

            case 3: //Multiplication
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;

            case 4: //Division
                printf("Enter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                if(num2 == 0) {
                    printf("Error: Division by zero\n");
                    break;
                }
                result = num1 / num2;
                printf("Result: %.2f\n", result);
                break;

            case 5: //Square root
                printf("Enter a number: ");
                scanf("%f", &num1);
                if(num1 < 0) {
                    printf("Error: Cannot find square root of a negative number\n");
                    break;
                }
                result = sqrt(num1);
                printf("Result: %.2f\n", result);
                break;

            case 6: //Power
                printf("Enter the base: ");
                scanf("%f", &num1);
                printf("Enter the exponent: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case 7: //Logarithm (natural)
                printf("Enter a number: ");
                scanf("%f", &num1);
                if(num1 <= 0) {
                    printf("Error: Cannot find logarithm of non-positive number\n");
                    break;
                }
                result = log(num1);
                printf("Result: %.2f\n", result);
                break;

            case 8: //Exit
                printf("Thank you for using the Intelligent Scientific Calculator!\n");
                break;

            default:
                printf("Error: Invalid Choice\n");
        }

    } while(option != 8);

    return 0;
}