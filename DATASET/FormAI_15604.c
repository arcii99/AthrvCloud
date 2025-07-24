//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include<stdio.h>
#include<math.h>

int main()
{
    int num1, num2, choice;
    float result;

    printf("Welcome to Scientific Calculator \n");
    printf("Please Select an Option:\n");
    printf("1. Addition \n2. Subtraction \n3. Multiplication \n");
    printf("4. Division \n5. Power Calculation \n");
    printf("6. Square Root Calculation \n7. Logarithm Calculation\n");
    printf("8. Exponential Calculation \n9. Sine Calculation \n");
    printf("10. Cosine Calculation \n11. Tangent Calculation \n");
    printf("12. Exit\n");

    do{
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Two Numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2f \n\n", result);
                break;
            case 2:
                printf("Enter Two Numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2f \n\n", result);
                break;
            case 3:
                printf("Enter Two Numbers: ");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2f \n\n", result);
                break;
            case 4:
                printf("Enter Two Numbers: ");
                scanf("%d %d", &num1, &num2);
                result = (float)num1 / num2;
                printf("Result: %.2f \n\n", result);
                break;
            case 5:
                printf("Enter a Number: ");
                scanf("%d", &num1);
                printf("Enter Power: ");
                scanf("%d", &num2);
                result = pow(num1, num2);
                printf("Result: %.2f \n\n", result);
                break;
            case 6:
                printf("Enter a Number: ");
                scanf("%d", &num1);
                result = sqrt(num1);
                printf("Result: %.2f \n\n", result);
                break;
            case 7:
                printf("Enter a Number: ");
                scanf("%d", &num1);
                result = log(num1);
                printf("Result: %.2f \n\n", result);
                break;
            case 8:
                printf("Enter a Number: ");
                scanf("%d", &num1);
                result = exp(num1);
                printf("Result: %.2f \n\n", result);
                break;
            case 9:
                printf("Enter a Number (in Degrees): ");
                scanf("%d", &num1);
                result = sin(num1 * (M_PI / 180));
                printf("Result: %.2f \n\n", result);
                break;
            case 10:
                printf("Enter a Number (in Degrees): ");
                scanf("%d", &num1);
                result = cos(num1 * (M_PI / 180));
                printf("Result: %.2f \n\n", result);
                break;
            case 11:
                printf("Enter a Number (in Degrees): ");
                scanf("%d", &num1);
                result = tan(num1 * (M_PI / 180));
                printf("Result: %.2f \n\n", result);
                break;
            case 12:
                printf("Thank You! \n");
                break;
            default:
                printf("Invalid Choice! Please Enter Valid Choice. \n\n");
        }
    }while(choice != 12);

    return 0;
}