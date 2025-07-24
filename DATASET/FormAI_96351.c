//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <math.h>

int main() {
    printf("Greetings! I am a scientific calculator programmed to perform a variety of mathematical functions. Let's get started!\n");
    //take user input for choosing mathematical operation
    int choice;
    printf("What would you like to do today? \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Exponential Calculation\n");
    printf("7. Trigonometric Functions\n");
    printf("8. Logarithmic Functions\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    double num1, num2, result;
    switch (choice) {
        case 1:
            printf("Great! You chose Addition\n");
            printf("Enter your first number: ");
            scanf("%lf", &num1);
            printf("Enter your second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("The sum of %lf and %lf is %lf\n", num1, num2, result);
            break;

        case 2:
            printf("Awesome! You chose Subtraction\n");
            printf("Enter your first number: ");
            scanf("%lf", &num1);
            printf("Enter your second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("The difference between %lf and %lf is %lf\n", num1, num2, result);
            break;

        case 3:
            printf("Way to go! You chose Multiplication\n");
            printf("Enter your first number: ");
            scanf("%lf", &num1);
            printf("Enter your second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("The product of %lf and %lf is %lf\n", num1, num2, result);
            break;

        case 4:
            printf("Fun! You chose Division\n");
            printf("Enter your first number: ");
            scanf("%lf", &num1);
            printf("Enter your second number: ");
            scanf("%lf", &num2);
            if(num2 == 0){
                printf("Error! Division by zero is not possible.");
            }
            else{
                result = num1 / num2;
                printf("The quotient of %lf divided by %lf is %lf\n", num1, num2, result);
            }
            break;

        case 5:
            printf("Amazing! You chose Square Root\n");
            printf("Enter your number: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("The square root of %lf is %lf\n", num1, result);
            break;

        case 6:
            printf("Cool! You chose Exponential Calculation\n");
            printf("Enter your first number (base): ");
            scanf("%lf", &num1);
            printf("Enter your second number (exponent): ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%lf raised to the power of %lf is %lf\n", num1, num2, result);
            break;

        case 7:
            printf("Nice! You chose Trigonometric Functions\n");
            printf("Enter your angle in degrees: ");
            scanf("%lf", &num1);
            //convert degrees to radians
            num1 = num1 * (3.14159265359 / 180);
            printf("The sin of %lf is %lf\n", num1, sin(num1));
            printf("The cos of %lf is %lf\n", num1, cos(num1));
            printf("The tan of %lf is %lf\n", num1, tan(num1));
            break;

        case 8:
            printf("Super! You chose Logarithmic Functions\n");
            printf("Enter your number: ");
            scanf("%lf", &num1);
            result = log(num1);
            printf("The natural logarithm of %lf is %lf\n", num1, result);
            break;

        case 9:
            printf("Bye! Thanks for using this calculator\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again\n");
    }
    return 0;
}