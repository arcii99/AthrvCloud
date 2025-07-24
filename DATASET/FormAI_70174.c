//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include<stdio.h>
#include<math.h>

int main(){
    int choice;
    float num1, num2, result;
    printf("Welcome to the Scientific Calculator\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Log\n7. Square root\n8. Exit\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("The result of %f + %f is %f\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("The result of %f - %f is %f\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("The result of %f * %f is %f\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            result = num1 / num2;
            printf("The result of %f / %f is %f\n", num1, num2, result);
            break;
        case 5:
            printf("Enter the base number: ");
            scanf("%f", &num1);
            printf("Enter the exponent: ");
            scanf("%f", &num2);
            result = pow(num1,num2);
            printf("The result of %f raised to the power of %f is %f\n", num1, num2, result);
            break;
        case 6:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = log10(num1);
            printf("The log of %f is %f\n", num1, result);
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%f", &num1);
            result = sqrt(num1);
            printf("The square root of %f is %f\n", num1, result);
            break;
        case 8:
            printf("Thank you for using the Scientific Calculator.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    main();
}