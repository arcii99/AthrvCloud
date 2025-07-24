//FormAI DATASET v1.0 Category: Arithmetic ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int num1, num2;
    float result;
    printf("Enter two numbers to perform arithmetic operations on: ");
    scanf("%d %d", &num1, &num2);

    int choice;
    printf("Choose an operation to perform:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is: %.2f", num1, num2, result);
            break;
        
        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is: %.2f", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is: %.2f", num1, num2, result);
            break;

        case 4:
            if(num2 == 0)
            {
                printf("Cannot divide by zero!");
                exit(1);
            }
            result = (float) num1 / num2;
            printf("The quotient of %d divided by %d is: %.2f", num1, num2, result);
            break;

        default:
            printf("Invalid choice!");
            exit(1);
    }

    printf("\nPerforming some additional calculations...\n");
    int i, j, k;
    i = num1 * 2;
    j = num2 / 2;
    k = pow(i, j);
    printf("The result after multiplying %d by 2 is: %d\n", num1, i);
    printf("The result after dividing %d by 2 is: %d\n", num2, j);
    printf("The result after raising %d to the power of %d is: %d\n", i, j, k);

    printf("\nPerforming some more calculations...\n");
    float x, y, z, temp;
    x = num1 * 1.5;
    y = num2 / 1.5;
    z = sqrt(pow(x, 2) + pow(y, 2));
    temp = (float) k / z;
    printf("The result after multiplying %d by 1.5 is: %.2f\n", num1, x);
    printf("The result after dividing %d by 1.5 is: %.2f\n", num2, y);
    printf("The result after finding the hypotenuse of %d and %d is: %.2f\n", (int) x, (int) y, z);
    printf("The final result after dividing %d by %.2f is: %.2f\n", k, z, temp);

    return 0;
}