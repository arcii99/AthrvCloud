//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    printf("\n\t------- Welcome to C Scientific Calculator! -------\n\n");
    printf("\tChoose an operation: \n");
    printf("\t1. Addition \n");
    printf("\t2. Subtraction \n");
    printf("\t3. Multiplication \n");
    printf("\t4. Division \n");
    printf("\t5. Square Root\n");
    printf("\t6. Power\n");
    printf("\t7. Logarithm \n");
    printf("\t8. Exit \n");

    int choice;
    double num1, num2, result;
    printf("\n\tEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\n\tEnter first number: ");
            scanf("%lf", &num1);
            printf("\n\tEnter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("\n\tResult: %.2lf\n", result);
            break;

        case 2:
            printf("\n\tEnter first number: ");
            scanf("%lf", &num1);
            printf("\n\tEnter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("\n\tResult: %.2lf\n", result);
            break;

        case 3:
            printf("\n\tEnter first number: ");
            scanf("%lf", &num1);
            printf("\n\tEnter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("\n\tResult: %.2lf\n", result);
            break;

        case 4:
            printf("\n\tEnter first number: ");
            scanf("%lf", &num1);
            printf("\n\tEnter second number: ");
            scanf("%lf", &num2);
            if(num2 == 0)
            {
                printf("\n\tDivision by zero is not possible.\n");
            }
            else
            {
                result = num1 / num2;
                printf("\n\tResult: %.2lf\n", result);
            }
            break;

        case 5:
            printf("\n\tEnter a number: ");
            scanf("%lf", &num1);
            if(num1 < 0)
            {
                printf("\n\tSquare Root of negative number not possible.\n");
            }
            else
            {
                result = sqrt(num1);
                printf("\n\tResult: %.2lf\n", result);
            }
            break;

        case 6:
            printf("\n\tEnter a number: ");
            scanf("%lf", &num1);
            printf("\n\tEnter power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("\n\tResult: %.2lf\n", result);
            break;

        case 7:
            printf("\n\tEnter a number: ");
            scanf("%lf", &num1);
            if(num1 < 0)
            {
                printf("\n\tLogarithm of negative number not possible.\n");
            }
            else
            {
                result = log(num1);
                printf("\n\tResult: %.2lf\n", result);
            }
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("\n\tInvalid choice. Please try again.\n");
            break;
    }
    main();
}