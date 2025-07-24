//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include<stdio.h>
#include<math.h>

int main(){
    printf("\n***********************************\n");
    printf("*      SCIENTIFIC CALCULATOR      *\n");
    printf("***********************************\n");

    float num1, num2, result;
    char operator;
    int choice;

    do {
        printf("\nPlease select an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Percentage\n");
        printf("8. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Addition
                printf("\nEnter two numbers to add: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f", num1, num2, result);
                break;
            case 2: // Subtraction
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f", num1, num2, result);
                break;
            case 3: // Multiplication
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f", num1, num2, result);
                break;
            case 4: // Division
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f", &num1, &num2);
                if(num2 == 0){
                    printf("Error! Cannot divide by zero.");
                }else{
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f", num1, num2, result);
                }
                break;
            case 5: // Power
                printf("\nEnter a number and its power: ");
                scanf("%f %f", &num1, &num2);
                result = pow(num1, num2);
                printf("%.2f ^ %.2f = %.2f", num1, num2, result);
                break;
            case 6: // Square Root
                printf("\nEnter a number to find its square root: ");
                scanf("%f", &num1);
                if(num1 < 0){
                    printf("Error! Cannot find square root of a negative number.");
                }else{
                    result = sqrt(num1);
                    printf("Square root of %.2f = %.2f", num1, result);
                }
                break;
            case 7: // Percentage
                printf("\nEnter a number and its percentage value: ");
                scanf("%f %f", &num1, &num2);
                result = (num1 * num2) / 100;
                printf("%.2f percent of %.2f = %.2f", num2, num1, result);
                break;
            case 8: // Exit
                printf("\nThank you for using the scientific calculator!");
                break;
            default:
                printf("\nInvalid choice! Please select a valid operation.");
        }

    }while(choice != 8);

    return 0;
}