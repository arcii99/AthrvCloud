//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    int choice;
    double num, result;
    printf("\nWelcome to C Scientific Calculator\n\n");
    
    while(1) {
        printf("Enter the operation you want to perform:\n");
        printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Square root \n6. Exponentiation \n7. Trigonometric functions \n8. Exit\n");
        scanf("%d", &choice);
        
        if(choice == 8) {
            printf("\nExiting the program... Thank you for using C Scientific Calculator!\n");
            break;
        }
        
        switch(choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%lf %lf", &num, &result);
                result += num;
                printf("Result: %.2lf\n\n", result);
                break;
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%lf %lf", &num, &result);
                result -= num;
                printf("Result: %.2lf\n\n", result);
                break;
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%lf %lf", &num, &result);
                result *= num;
                printf("Result: %.2lf\n\n", result);
                break;
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%lf %lf", &num, &result);
                result /= num;
                printf("Result: %.2lf\n\n", result);
                break;
            case 5:
                printf("\nEnter the number to calculate the square root: ");
                scanf("%lf", &num);
                result = sqrt(num);
                printf("Result: %.2lf\n\n", result);
                break;
            case 6:
                printf("\nEnter two numbers (base and exponent) to calculate exponential value: ");
                scanf("%lf %lf", &num, &result);
                result = pow(num, result);
                printf("Result: %.2lf\n\n", result);
                break;
            case 7:
                printf("\nEnter the angle in degrees: ");
                scanf("%lf", &num);
                double rad = num * PI / 180.0;
                printf("1. Sin\n2. Cos\n3. Tan\n4. Cosec\n5. Sec\n6. Cot\n");
                int choice2;
                scanf("%d", &choice2);
                switch(choice2) {
                    case 1:
                        result = sin(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    case 2:
                        result = cos(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    case 3:
                        result = tan(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    case 4:
                        result = 1.0 / sin(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    case 5:
                        result = 1.0 / cos(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    case 6:
                        result = 1.0 / tan(rad);
                        printf("Result: %.2lf\n\n", result);
                        break;
                    default:
                        printf("Invalid choice.\n\n");
                }
                break;
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}