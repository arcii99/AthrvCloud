//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include<stdio.h>
#include<math.h>

int main(){
    float num1, num2;
    int choice, result;
    float res;
    printf("***Welcome to My Scientific Calculator***\n\n");

    printf("Enter First Number: ");
    scanf("%f", &num1);
    printf("Enter Second Number: ");
    scanf("%f", &num2);

    printf("\nSelect The Operation You Want To Perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Modulus\n7. Square Root\n8. Log\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("\nAddition of %.2f and %.2f is: %d\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\nSubtraction of %.2f and %.2f is: %d\n", num1, num2, result);
            break;

        case 3:
            res = num1 * num2;
            printf("\nMultiplication of %.2f and %.2f is: %.2f\n", num1, num2, res);
            break;

        case 4:
            if(num2 == 0){
                printf("\nCan not divide by zero\n\n");
                break;
            }
            res = num1 / num2;
            printf("\nDivision of %.2f and %.2f is: %.2f\n", num1, num2, res);
            break;

        case 5:
            res = pow(num1, num2);
            printf("\n%.2f raised to %.2f is: %.2f\n", num1, num2, res);
            break;

        case 6:
            result = (int)num1 % (int)num2;
            printf("\nModulus of %.2f and %.2f is: %d\n", num1, num2, result);
            break;

        case 7:
            if(num1 < 0){
                printf("\nSquare Root is not possible of negative numbers\n\n");
                break;
            }
            res = sqrt(num1);
            printf("\nSquare Root of %.2f is: %.2f\n", num1, res);
            break;

        case 8:
            if(num1 <= 0){
                printf("\nLog is defined only for positive numbers\n\n");
                break;
            }
            res = log(num1);
            printf("\nNatural Logarithm of %.2f is: %.2f\n", num1, res);
            break;

        default:
            printf("\nInvalid Input\n\n");
            break;
    }

    printf("\nThank You For Using Our Calculator\n\n");

    return 0;
}