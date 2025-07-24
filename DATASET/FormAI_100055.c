//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include<stdio.h>
#include<math.h>

int main(){

    printf("Welcome to the Scientific Calculator!\n");

    int choice, num1, num2;
    float result;

    printf("Please select an operation to perform:\n");
    printf("1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Square root\n 6. Square\n 7. Cube\n 8. Power\n 9. Sine\n 10. Cosine\n 11. Tangent\n");
    scanf("%d", &choice);

    switch(choice){

        case 1: //Addition
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("The addition of %d and %d is %.2f\n", num1, num2, result);
            break;

        case 2: //Subtraction
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("The subtraction of %d and %d is %.2f\n", num1, num2, result);
            break;

        case 3: //Multiplication
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("The multiplication of %d and %d is %.2f\n", num1, num2, result);
            break;

        case 4: //Division
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = (float) num1 / num2;
            printf("The division of %d and %d is %.2f\n", num1, num2, result);
            break;

        case 5: //Square root
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = sqrt(num1);
            printf("The square root of %d is %.2f\n", num1, result);
            break;

        case 6: //Square
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = pow(num1, 2);
            printf("The square of %d is %.2f\n", num1, result);
            break;

        case 7: //Cube
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = pow(num1, 3);
            printf("The cube of %d is %.2f\n", num1, result);
            break;

        case 8: //Power
            printf("Enter a number: ");
            scanf("%d", &num1);
            printf("Enter the power: ");
            scanf("%d", &num2);
            result = pow(num1, num2);
            printf("%d raised to the power of %d is %.2f\n", num1, num2, result);
            break;

        case 9: //Sine
            printf("Enter the angle in degrees: ");
            scanf("%d", &num1);
            result = sin(num1 * M_PI/180);
            printf("The sine of %d is %.2f\n", num1, result);
            break;

        case 10: //Cosine
            printf("Enter the angle in degrees: ");
            scanf("%d", &num1);
            result = cos(num1 * M_PI/180);
            printf("The cosine of %d is %.2f\n", num1, result);
            break;

        case 11: //Tangent
            printf("Enter the angle in degrees: ");
            scanf("%d", &num1);
            result = tan(num1 * M_PI/180);
            printf("The tangent of %d is %.2f\n", num1, result);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0; 
}