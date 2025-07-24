//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main() 
{
    int choice, num1, num2, ans;
    float fnum1, fnum2, fans;

    printf("-----------------------------\n");
    printf("|   C SCIENTIFIC CALCULATOR  |\n");
    printf("-----------------------------\n");
    printf("|   1. Addition             |\n");
    printf("|   2. Subtraction          |\n");
    printf("|   3. Multiplication       |\n");
    printf("|   4. Division             |\n");
    printf("|   5. Square Root          |\n");
    printf("|   6. Power                |\n");
    printf("-----------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two integers to add: ");
            scanf("%d%d", &num1, &num2);

            ans = num1 + num2;
            printf("The result of addition is: %d", ans);
            break;

        case 2:
            printf("Enter two integers to subtract: ");
            scanf("%d%d", &num1, &num2);

            ans = num1 - num2;
            printf("The result of subtraction is: %d", ans);
            break;

        case 3:
            printf("Enter two integers to multiply: ");
            scanf("%d%d", &num1, &num2);

            ans = num1 * num2;
            printf("The result of multiplication is: %d", ans);
            break;

        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f%f", &fnum1, &fnum2);

            fans = fnum1 / fnum2;
            printf("The result of division is: %.2f", fans);
            break;
        
        case 5:
            printf("Enter a number to find square root: ");
            scanf("%f", &fnum1);

            fans = sqrt(fnum1);
            printf("The square root of %.2f is: %.2f", fnum1, fans);
            break;
            
        case 6:
            printf("Enter two numbers to find power: ");
            scanf("%f%f", &fnum1, &fnum2);

            fans = pow(fnum1, fnum2);
            printf("The result of %.2f to the power of %.2f is: %.2f", fnum1, fnum2, fans);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}